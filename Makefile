#############################################################################
# Makefile for building: eviewer
# Generated by qmake (2.01a) (Qt 4.8.3) on: Sun Oct 28 15:55:52 2012
# Project:  eviewer.pro
# Template: app
# Command: /usr/bin/qmake -spec /usr/share/qt4/mkspecs/linux-g++ CONFIG+=debug CONFIG+=declarative_debug -o Makefile eviewer.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -g -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -g -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++ -I. -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4 -I.
LINK          = g++
LFLAGS        = 
LIBS          = $(SUBLIBS)  -L/usr/lib64/qt4 -lQtGui -L/usr/lib64 -L/usr/lib64/qt4 -L/usr/X11R6/lib -lQtCore -lgthread-2.0 -lrt -lglib-2.0 -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = main.cpp \
		mainwindow.cpp \
		statusbar.cpp \
		toolbar.cpp \
		menubar.cpp \
		infodock.cpp \
		groupfiltersdock.cpp \
		settingsdock.cpp \
		graphicsview.cpp \
		graph.cpp \
		source.cpp \
		timeline.cpp moc_mainwindow.cpp \
		moc_statusbar.cpp \
		moc_toolbar.cpp \
		moc_menubar.cpp \
		moc_infodock.cpp \
		moc_graph.cpp \
		moc_timeline.cpp \
		qrc_res.cpp
OBJECTS       = main.o \
		mainwindow.o \
		statusbar.o \
		toolbar.o \
		menubar.o \
		infodock.o \
		groupfiltersdock.o \
		settingsdock.o \
		graphicsview.o \
		graph.o \
		source.o \
		timeline.o \
		moc_mainwindow.o \
		moc_statusbar.o \
		moc_toolbar.o \
		moc_menubar.o \
		moc_infodock.o \
		moc_graph.o \
		moc_timeline.o \
		qrc_res.o
DIST          = /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_phonon.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/debug.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/declarative_debug.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		eviewer.pro
QMAKE_TARGET  = eviewer
DESTDIR       = 
TARGET        = eviewer

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET):  $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)
	{ test -n "$(DESTDIR)" && DESTDIR="$(DESTDIR)" || DESTDIR=.; } && test $$(gdb --version | sed -e 's,[^0-9]\+\([0-9]\)\.\([0-9]\).*,\1\2,;q') -gt 72 && gdb --nx --batch --quiet -ex 'set confirm off' -ex "save gdb-index $$DESTDIR" -ex quit '$(TARGET)' && test -f $(TARGET).gdb-index && objcopy --add-section '.gdb_index=$(TARGET).gdb-index' --set-section-flags '.gdb_index=readonly' '$(TARGET)' '$(TARGET)' && rm -f $(TARGET).gdb-index || true

Makefile: eviewer.pro  /usr/share/qt4/mkspecs/linux-g++/qmake.conf /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_phonon.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/debug.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/declarative_debug.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		/usr/lib64/qt4/libQtGui.prl \
		/usr/lib64/qt4/libQtCore.prl
	$(QMAKE) -spec /usr/share/qt4/mkspecs/linux-g++ CONFIG+=debug CONFIG+=declarative_debug -o Makefile eviewer.pro
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/common/gcc-base.conf:
/usr/share/qt4/mkspecs/common/gcc-base-unix.conf:
/usr/share/qt4/mkspecs/common/g++-base.conf:
/usr/share/qt4/mkspecs/common/g++-unix.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/modules/qt_phonon.pri:
/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/debug.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/declarative_debug.prf:
/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/share/qt4/mkspecs/features/include_source_dir.prf:
/usr/lib64/qt4/libQtGui.prl:
/usr/lib64/qt4/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -spec /usr/share/qt4/mkspecs/linux-g++ CONFIG+=debug CONFIG+=declarative_debug -o Makefile eviewer.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/eviewer1.0.0 || $(MKDIR) .tmp/eviewer1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/eviewer1.0.0/ && $(COPY_FILE) --parents mainwindow.h statusbar.h toolbar.h menubar.h infodock.h groupfiltersdock.h settingsdock.h graphicsview.h graph.h source.h timeline.h .tmp/eviewer1.0.0/ && $(COPY_FILE) --parents res.qrc .tmp/eviewer1.0.0/ && $(COPY_FILE) --parents main.cpp mainwindow.cpp statusbar.cpp toolbar.cpp menubar.cpp infodock.cpp groupfiltersdock.cpp settingsdock.cpp graphicsview.cpp graph.cpp source.cpp timeline.cpp .tmp/eviewer1.0.0/ && (cd `dirname .tmp/eviewer1.0.0` && $(TAR) eviewer1.0.0.tar eviewer1.0.0 && $(COMPRESS) eviewer1.0.0.tar) && $(MOVE) `dirname .tmp/eviewer1.0.0`/eviewer1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/eviewer1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_mainwindow.cpp moc_statusbar.cpp moc_toolbar.cpp moc_menubar.cpp moc_infodock.cpp moc_graph.cpp moc_timeline.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_mainwindow.cpp moc_statusbar.cpp moc_toolbar.cpp moc_menubar.cpp moc_infodock.cpp moc_graph.cpp moc_timeline.cpp
moc_mainwindow.cpp: toolbar.h \
		statusbar.h \
		menubar.h \
		infodock.h \
		groupfiltersdock.h \
		settingsdock.h \
		mainwindow.h
	/usr/bin/moc $(DEFINES) $(INCPATH) mainwindow.h -o moc_mainwindow.cpp

moc_statusbar.cpp: statusbar.h
	/usr/bin/moc $(DEFINES) $(INCPATH) statusbar.h -o moc_statusbar.cpp

moc_toolbar.cpp: toolbar.h
	/usr/bin/moc $(DEFINES) $(INCPATH) toolbar.h -o moc_toolbar.cpp

moc_menubar.cpp: menubar.h
	/usr/bin/moc $(DEFINES) $(INCPATH) menubar.h -o moc_menubar.cpp

moc_infodock.cpp: infodock.h
	/usr/bin/moc $(DEFINES) $(INCPATH) infodock.h -o moc_infodock.cpp

moc_graph.cpp: graph.h
	/usr/bin/moc $(DEFINES) $(INCPATH) graph.h -o moc_graph.cpp

moc_timeline.cpp: timeline.h
	/usr/bin/moc $(DEFINES) $(INCPATH) timeline.h -o moc_timeline.cpp

compiler_rcc_make_all: qrc_res.cpp
compiler_rcc_clean:
	-$(DEL_FILE) qrc_res.cpp
qrc_res.cpp: res.qrc \
		icons/24x24/info.png \
		icons/24x24/search.png \
		icons/24x24/settings.png
	/usr/bin/rcc -name res res.qrc -o qrc_res.cpp

compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all:
compiler_uic_clean:
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_rcc_clean 

####### Compile

main.o: main.cpp mainwindow.h \
		toolbar.h \
		statusbar.h \
		menubar.h \
		infodock.h \
		groupfiltersdock.h \
		settingsdock.h \
		graphicsview.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

mainwindow.o: mainwindow.cpp mainwindow.h \
		toolbar.h \
		statusbar.h \
		menubar.h \
		infodock.h \
		groupfiltersdock.h \
		settingsdock.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o mainwindow.o mainwindow.cpp

statusbar.o: statusbar.cpp statusbar.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o statusbar.o statusbar.cpp

toolbar.o: toolbar.cpp toolbar.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o toolbar.o toolbar.cpp

menubar.o: menubar.cpp menubar.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o menubar.o menubar.cpp

infodock.o: infodock.cpp infodock.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o infodock.o infodock.cpp

groupfiltersdock.o: groupfiltersdock.cpp groupfiltersdock.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o groupfiltersdock.o groupfiltersdock.cpp

settingsdock.o: settingsdock.cpp settingsdock.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o settingsdock.o settingsdock.cpp

graphicsview.o: graphicsview.cpp graphicsview.h \
		graph.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o graphicsview.o graphicsview.cpp

graph.o: graph.cpp graph.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o graph.o graph.cpp

source.o: source.cpp source.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o source.o source.cpp

timeline.o: timeline.cpp timeline.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o timeline.o timeline.cpp

moc_mainwindow.o: moc_mainwindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_mainwindow.o moc_mainwindow.cpp

moc_statusbar.o: moc_statusbar.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_statusbar.o moc_statusbar.cpp

moc_toolbar.o: moc_toolbar.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_toolbar.o moc_toolbar.cpp

moc_menubar.o: moc_menubar.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_menubar.o moc_menubar.cpp

moc_infodock.o: moc_infodock.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_infodock.o moc_infodock.cpp

moc_graph.o: moc_graph.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_graph.o moc_graph.cpp

moc_timeline.o: moc_timeline.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_timeline.o moc_timeline.cpp

qrc_res.o: qrc_res.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o qrc_res.o qrc_res.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

