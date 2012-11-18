typedef struct {
	short type;
	char len;
	long timestamp_s;
	short timestamp_m;
	long code;
	char ppe_id;
	short node_addr;
	long app_id;
	long agent_id;
	long agent_type;
}__attribute__((packed)) log_struct_f;

typedef struct {
	short type;
	char len;
	long timestamp_s;
	short timestamp_m;
	long code;
	char ppe_id;
	short node_addr;
	long app_id;
	long agent_id;
}__attribute__((packed)) log_struct_e;

typedef struct {
	short type;
	char len;
	long timestamp_s;
	short timestamp_m;
	long code;
	char ppe_id;
	short node_addr;
	long app_id;
}__attribute__((packed)) log_struct_d;

typedef struct {
	short type;
	char len;
	long timestamp_s;
	short timestamp_m;
	long code;
	char ppe_id;
	short node_addr;
}__attribute__((packed)) log_struct_c;

typedef struct {
	short type;
	char len;
	long timestamp_s;
	short timestamp_m;
	long code;
	char ppe_id;
}__attribute__((packed)) log_struct_b;

typedef struct {
	short type;
	char len;
	long timestamp_s;
	short timestamp_m;
	long code;
}__attribute__((packed)) log_struct_a;

typedef struct {
	float value;
}__attribute__((packed)) log_struct_indicator;



int log_event(	uint16_t type, 
				uint32_t code, 
				uint8_t ppe_id, 
				uint16_t node_addr, 
				uint32_t app_id, 
				uint32_t agent_id, 
				uint32_t agent_type,
				float value){
	
	struct timeval tim;
	log_struct_f new_log;
	short type_s;
	char indicator_len = 0;
	char * log_to_send = NULL;
	int packet_len = 0;
	uint32_t corrected_value;
	
		//get event timestamp
    gettimeofday(&tim, NULL);
	
	new_log.type = htons(type);
   	//new_log.len = sizeof(new_log) - (sizeof(new_log.type) + sizeof(new_log.len));
   	new_log.timestamp_s = htonl(tim.tv_sec);
   	new_log.timestamp_m = htons(tim.tv_usec/1000);
   	new_log.code = htonl(code);
   	new_log.ppe_id = ppe_id;
   	new_log.node_addr = htons(node_addr);
   	new_log.app_id = htonl(app_id);
   	new_log.agent_id = htonl(agent_id);
	new_log.agent_type = htonl(agent_type);
	
	
	//add lenght of the value field
	if(type & LOG_INDICATOR){
		union f_swap {
			float f;
			uint32_t i;
		};
		
		union f_swap temp;
		
		indicator_len = sizeof(log_struct_indicator);
		
		temp.f = value;
		corrected_value = htonl(temp.i);
	}
	
	type_s = type & LOG_STRUCT_MASK;
	switch(type_s){
		case LOG_STRUCT_A:{
			packet_len = sizeof(log_struct_a) + indicator_len;
			log_to_send = (char *)malloc(packet_len);
			new_log.len = sizeof(log_struct_a) - (sizeof(new_log.type) + sizeof(new_log.len)) + indicator_len;
			//copy only fields of the final structure
			memcpy(log_to_send, (char *)&new_log, sizeof(log_struct_a));
		}
		break;
		case LOG_STRUCT_B:{
			packet_len = sizeof(log_struct_b) + indicator_len;
			log_to_send = (char *)malloc(packet_len);
			new_log.len = sizeof(log_struct_b) - (sizeof(new_log.type) + sizeof(new_log.len)) + indicator_len;
			//copy only fields of the final structure
			memcpy(log_to_send, (char *)&new_log, sizeof(log_struct_b));
		}
		break;
		case LOG_STRUCT_C:{
			packet_len = sizeof(log_struct_c) + indicator_len;
			log_to_send = (char *)malloc(packet_len);
			new_log.len = sizeof(log_struct_c) - (sizeof(new_log.type) + sizeof(new_log.len)) + indicator_len;
			//copy only fields of the final structure
			memcpy(log_to_send, (char *)&new_log, sizeof(log_struct_c));
		}
		break;
		case LOG_STRUCT_D:{
			packet_len = sizeof(log_struct_d) + indicator_len;
			log_to_send = (char *)malloc(packet_len);
			new_log.len = sizeof(log_struct_d) - (sizeof(new_log.type) + sizeof(new_log.len)) + indicator_len;
			//copy only fields of the final structure
			memcpy(log_to_send, (char *)&new_log, sizeof(log_struct_d));
		}
		break;
		case LOG_STRUCT_E:{
			packet_len = sizeof(log_struct_e) + indicator_len;
			log_to_send = (char *)malloc(packet_len);
			new_log.len = sizeof(log_struct_e) - (sizeof(new_log.type) + sizeof(new_log.len)) + indicator_len;
			//copy only fields of the final structure
			memcpy(log_to_send, (char *)&new_log, sizeof(log_struct_e));
		}
		break;
		case LOG_STRUCT_F:{
			packet_len = sizeof(log_struct_f) + indicator_len;
			log_to_send = (char *)malloc(packet_len);
			new_log.len = sizeof(log_struct_f) - (sizeof(new_log.type) + sizeof(new_log.len)) + indicator_len;
			//copy only fields of the final structure
			memcpy(log_to_send, (char *)&new_log, sizeof(log_struct_f));
		}
		break;
		default:{
			dbg("DBG_ERROR","Logging error, unknown type ! %04x\n",type);
			return 0;
		}
		break;
	}
	
		//add indicator at the end of the packet
	if(indicator_len != 0)
		memcpy(&log_to_send[packet_len - indicator_len], &corrected_value, indicator_len);
	
	log_send(packet_len, log_to_send);
	//printf("Send log: %02x %02x %02x %2x, packet len: %d \n",log_to_send[0], log_to_send[1], log_to_send[2], log_to_send[3], packet_len);
	
	return packet_len;
	
}
