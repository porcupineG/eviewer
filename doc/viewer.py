#!/usr/bin/python

# actresses.py

import wx
import sys
import socket
import thread
import struct
import time





class LogList(wx.Frame):
    def __init__(self, parent, id, title, server_ip):
        wx.Frame.__init__(self, parent, id, title, size=(900, 230))

        hbox = wx.BoxSizer(wx.HORIZONTAL)
        panel = wx.Panel(self, -1)
        
        self.list = wx.ListCtrl(panel, -1, style=wx.LC_REPORT)
        self.list.InsertColumn(0, 'timestamp', width=140)
        self.list.InsertColumn(1, 'type', width=150)
        self.list.InsertColumn(2, 'code', width=149)
        self.list.InsertColumn(3, 'ppe_id', width=55)
        self.list.InsertColumn(4, 'node_addr', width=70)
        self.list.InsertColumn(5, 'app_id', width=55)
        self.list.InsertColumn(6, 'agent_id', width=100)
        self.list.InsertColumn(7, 'agent_type', width=100)
        self.list.InsertColumn(8, 'value', wx.LIST_FORMAT_RIGHT, 90)

        hbox.Add(self.list, 1, wx.EXPAND)
        panel.SetSizer(hbox)

        self.Centre()
        self.Show(True)
        
        #start receiver thread
        thread.start_new_thread(self.log_receiver, (server_ip,))
        
    def decode_type(self, log_type):
        return hex(log_type)
        
    def decode_code(self, log_code, log_type):
        return hex(log_code)
    
    def add_log(self, log_entry):
    
        #timestamp = str(log_entry[2]) + '.' + str(log_entry[3])
        timestamp = time.strftime("%d/%m/%y - %H:%M:%S", time.gmtime(log_entry[2])) + '.' + str(log_entry[3])
        
        if(log_entry[0] != None):
            log_type = self.decode_type(log_entry[0])
        else:
            log_type = None
            
        if(log_entry[4] != None):
            log_code = self.decode_code(log_entry[4], log_entry[0])
        else:
            log_code = None
            
        if(log_entry[5] != None):
            ppe_id = log_entry[5]
        else:
            ppe_id = None
            
        if(log_entry[6] != None):
            node_addr =  log_entry[6]
        else:
            node_addr = None
            
        if(log_entry[7] != None):
            app_id =  hex(log_entry[7])
        else:
            app_id = None
            
        if(log_entry[8] != None):
            agent_id =  hex(log_entry[8])
        else:
            agent_id = None
            
        if(log_entry[9] != None):
            agent_type =  hex(log_entry[9])
        else:
            agent_type = None
            
        if(log_entry[10] != None):
            value = log_entry[10]
        else:
            value = None
        
        self.list.Append((timestamp, log_type, log_code, ppe_id, node_addr, app_id, agent_id, agent_type, value))
        
        self.list.EnsureVisible(self.list.GetItemCount() - 1)
        #self.list.SetStringItem(index, 4, i[4])
        #self.list.SetStringItem(index, 5, i[5])
        #self.list.SetStringItem(index, 6, i[6])
        #self.list.SetStringItem(index, 7, i[7])
        #self.list.SetStringItem(index, 8, i[8])
    
    def parse_log(self,log):
        #print "log added, len " + str(len(log))
        type_field = socket.ntohs((ord(log[0])) | ord(log[1]) << 8) 
        log_struct = type_field & 0xF000
        print "type field:"
        print hex(type_field)
        print "log struct:"
        print hex(log_struct)
        if(log_struct == 0x0000):
            #struct a
            if(type_field & 0x0800):
                log_entry = struct.unpack("!HBLHLf", log)
                log_entry = list(log_entry + (None, None, None, None, log_entry[5]))
                log_entry[5] = None
            else:
                log_entry = struct.unpack("!HBLHL", log)
                log_entry = log_entry + (None, None, None, None, None, None)
        elif(log_struct == 0x1000):
            #struct b
            if(type_field & 0x0800):
                log_entry = struct.unpack("!HBLHLBf", log)
                log_entry = list(log_entry + (None, None, None, log_entry[6]))
                log_entry[6] = None
            else:
                log_entry = struct.unpack("!HBLHLB", log)
                log_entry = log_entry + (None, None, None, None, None)
        elif(log_struct == 0x2000):
            #struct c
            if(type_field & 0x0800):
                log_entry = struct.unpack("!HBLHLBHf", log)
                log_entry = list(log_entry + (None, None, log_entry[7]))
                log_entry[7] = None
            else:
                log_entry = struct.unpack("!HBLHLBH", log)
                log_entry = log_entry + (None, None, None, None)
        elif(log_struct == 0x3000):
            #struct d
            if(type_field & 0x0800):
                log_entry = struct.unpack("!HBLHLBHLf", log)
                log_entry = list(log_entry + (None, log_entry[8]))
                log_entry[8] = None
            else:
                log_entry = struct.unpack("!HBLHLBHL", log)
                log_entry = log_entry + (None, None, None)
        elif(log_struct == 0x4000):
            #struct e
            if(type_field & 0x0800):
                log_entry = struct.unpack("!HBLHLBHLLf", log)
                log_entry = list(log_entry + (log_entry[9],))
                log_entry[9] = None
            else:
                log_entry = struct.unpack("!HBLHLBHLL", log)
                log_entry = log_entry + (None, None)
        elif(log_struct == 0x5000):
            #struct f
            if(type_field & 0x0800):
                log_entry = struct.unpack("!HBLHLBHLLLf", log)
                log_entry = log_entry
            else:
                log_entry = struct.unpack("!HBLHLBHLLL", log)
                log_entry = log_entry + (None,)
            
        print log_entry
        #add to table
        wx.CallAfter(self.add_log, (log_entry))
        return
        
    def log_receiver(self, server_ip):
        s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        s.connect((server_ip, 7001))
        msg = ''
        while(1):
            chunk = s.recv(1)
            #print chunk
            if(chunk == ''):
                break;
            msg = msg + chunk
            
            if(len(msg) > 3):
                #print "packet len " + str(ord(msg[1]))
                if((len(msg)-3) >= ord(msg[2])):
                    #interpret
                    log = msg[:(ord(msg[2])+3)]
                    self.parse_log(log)
                    msg = msg[(ord(msg[2])+3):]
        
        return


app = wx.App()
LogList(None, -1, 'Log List',sys.argv[1])
app.MainLoop()
