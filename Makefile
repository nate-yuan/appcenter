#############################################################################
# Makefile for building: appcenter
# Generated by qmake (2.01a) (Qt 4.7.4) on: ?? 11? 1 14:40:16 2011
# Project:  appcenter.pro
# Template: app
# Command: /usr/bin/qmake-qt4 -o Makefile appcenter.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -O2 -g -pipe -Wall -Wp,-D_FORTIFY_SOURCE=2 -fstack-protector --param=ssp-buffer-size=4 -m32 -march=i686 -mtune=atom -fasynchronous-unwind-tables -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -O2 -g -pipe -Wall -Wp,-D_FORTIFY_SOURCE=2 -fstack-protector --param=ssp-buffer-size=4 -m32 -march=i686 -mtune=atom -fasynchronous-unwind-tables -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/lib/qt4/mkspecs/linux-g++ -I. -I/usr/include/QtCore -I/usr/include/QtGui -I/usr/include -I. -Itmp
LINK          = g++
LFLAGS        = -Wl,-O1
LIBS          = $(SUBLIBS)  -L/usr/lib -lQtSql -lX11 -lQtGui -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/bin/qmake-qt4
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = 
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

OBJECTS_DIR   = tmp/

####### Files

SOURCES       = src/appwidget.cpp \
		src/dashboard.cpp \
		src/localapps.cpp \
		src/main.cpp \
		src/client/applist.cpp \
		src/client/appnode.cpp \
		src/client/center.cpp \
		src/client/itemdelegate.cpp \
		src/client/itemmodel.cpp \
		src/client/packageWidget.cpp \
		src/client/pictureframe.cpp \
		src/client/rftabbar.cpp \
		src/client/rftitlebar.cpp \
		src/client/tableview.cpp \
		src/client/widget.cpp tmp/moc_appwidget.cpp \
		tmp/moc_dashboard.cpp \
		tmp/moc_center.cpp \
		tmp/moc_appnode.cpp \
		tmp/moc_itemdelegate.cpp \
		tmp/moc_itemmodel.cpp \
		tmp/moc_packageWidget.cpp \
		tmp/moc_pictureframe.cpp \
		tmp/moc_rftabbar.cpp \
		tmp/moc_rftitlebar.cpp \
		tmp/moc_tableview.cpp \
		tmp/moc_widget.cpp
OBJECTS       = tmp/appwidget.o \
		tmp/dashboard.o \
		tmp/localapps.o \
		tmp/main.o \
		tmp/applist.o \
		tmp/appnode.o \
		tmp/center.o \
		tmp/itemdelegate.o \
		tmp/itemmodel.o \
		tmp/packageWidget.o \
		tmp/pictureframe.o \
		tmp/rftabbar.o \
		tmp/rftitlebar.o \
		tmp/tableview.o \
		tmp/widget.o \
		tmp/moc_appwidget.o \
		tmp/moc_dashboard.o \
		tmp/moc_center.o \
		tmp/moc_appnode.o \
		tmp/moc_itemdelegate.o \
		tmp/moc_itemmodel.o \
		tmp/moc_packageWidget.o \
		tmp/moc_pictureframe.o \
		tmp/moc_rftabbar.o \
		tmp/moc_rftitlebar.o \
		tmp/moc_tableview.o \
		tmp/moc_widget.o
DIST          = /usr/lib/qt4/mkspecs/common/g++-multilib.conf \
		/usr/lib/qt4/mkspecs/common/unix.conf \
		/usr/lib/qt4/mkspecs/common/linux.conf \
		/usr/lib/qt4/mkspecs/qconfig.pri \
		/usr/lib/qt4/mkspecs/modules/qt_webkit_version.pri \
		/usr/lib/qt4/mkspecs/features/qt_functions.prf \
		/usr/lib/qt4/mkspecs/features/qt_config.prf \
		/usr/lib/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/lib/qt4/mkspecs/features/default_pre.prf \
		/usr/lib/qt4/mkspecs/features/release.prf \
		/usr/lib/qt4/mkspecs/features/default_post.prf \
		/usr/lib/qt4/mkspecs/features/warn_on.prf \
		/usr/lib/qt4/mkspecs/features/qt.prf \
		/usr/lib/qt4/mkspecs/features/unix/thread.prf \
		/usr/lib/qt4/mkspecs/features/moc.prf \
		/usr/lib/qt4/mkspecs/features/resources.prf \
		/usr/lib/qt4/mkspecs/features/uic.prf \
		/usr/lib/qt4/mkspecs/features/yacc.prf \
		/usr/lib/qt4/mkspecs/features/lex.prf \
		appcenter.pro
QMAKE_TARGET  = appcenter
DESTDIR       = 
TARGET        = appcenter

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

Makefile: appcenter.pro  /usr/lib/qt4/mkspecs/linux-g++/qmake.conf /usr/lib/qt4/mkspecs/common/g++-multilib.conf \
		/usr/lib/qt4/mkspecs/common/unix.conf \
		/usr/lib/qt4/mkspecs/common/linux.conf \
		/usr/lib/qt4/mkspecs/qconfig.pri \
		/usr/lib/qt4/mkspecs/modules/qt_webkit_version.pri \
		/usr/lib/qt4/mkspecs/features/qt_functions.prf \
		/usr/lib/qt4/mkspecs/features/qt_config.prf \
		/usr/lib/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/lib/qt4/mkspecs/features/default_pre.prf \
		/usr/lib/qt4/mkspecs/features/release.prf \
		/usr/lib/qt4/mkspecs/features/default_post.prf \
		/usr/lib/qt4/mkspecs/features/warn_on.prf \
		/usr/lib/qt4/mkspecs/features/qt.prf \
		/usr/lib/qt4/mkspecs/features/unix/thread.prf \
		/usr/lib/qt4/mkspecs/features/moc.prf \
		/usr/lib/qt4/mkspecs/features/resources.prf \
		/usr/lib/qt4/mkspecs/features/uic.prf \
		/usr/lib/qt4/mkspecs/features/yacc.prf \
		/usr/lib/qt4/mkspecs/features/lex.prf \
		/usr/lib/libQtSql.prl \
		/usr/lib/libQtCore.prl \
		/usr/lib/libQtGui.prl
	$(QMAKE) -o Makefile appcenter.pro
/usr/lib/qt4/mkspecs/common/g++-multilib.conf:
/usr/lib/qt4/mkspecs/common/unix.conf:
/usr/lib/qt4/mkspecs/common/linux.conf:
/usr/lib/qt4/mkspecs/qconfig.pri:
/usr/lib/qt4/mkspecs/modules/qt_webkit_version.pri:
/usr/lib/qt4/mkspecs/features/qt_functions.prf:
/usr/lib/qt4/mkspecs/features/qt_config.prf:
/usr/lib/qt4/mkspecs/features/exclusive_builds.prf:
/usr/lib/qt4/mkspecs/features/default_pre.prf:
/usr/lib/qt4/mkspecs/features/release.prf:
/usr/lib/qt4/mkspecs/features/default_post.prf:
/usr/lib/qt4/mkspecs/features/warn_on.prf:
/usr/lib/qt4/mkspecs/features/qt.prf:
/usr/lib/qt4/mkspecs/features/unix/thread.prf:
/usr/lib/qt4/mkspecs/features/moc.prf:
/usr/lib/qt4/mkspecs/features/resources.prf:
/usr/lib/qt4/mkspecs/features/uic.prf:
/usr/lib/qt4/mkspecs/features/yacc.prf:
/usr/lib/qt4/mkspecs/features/lex.prf:
/usr/lib/libQtSql.prl:
/usr/lib/libQtCore.prl:
/usr/lib/libQtGui.prl:
qmake:  FORCE
	@$(QMAKE) -o Makefile appcenter.pro

dist: 
	@$(CHK_DIR_EXISTS) tmp/appcenter1.0.0 || $(MKDIR) tmp/appcenter1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) tmp/appcenter1.0.0/ && $(COPY_FILE) --parents src/appwidget.h src/constants.h src/dashboard.h src/localapps.h src/client/center.h src/client/applist.h src/client/appnode.h src/client/center.h src/client/itemdelegate.h src/client/itemmodel.h src/client/packageWidget.h src/client/pictureframe.h src/client/rftabbar.h src/client/rftitlebar.h src/client/tableview.h src/client/widget.h tmp/appcenter1.0.0/ && $(COPY_FILE) --parents src/appwidget.cpp src/dashboard.cpp src/localapps.cpp src/main.cpp src/client/applist.cpp src/client/appnode.cpp src/client/center.cpp src/client/itemdelegate.cpp src/client/itemmodel.cpp src/client/packageWidget.cpp src/client/pictureframe.cpp src/client/rftabbar.cpp src/client/rftitlebar.cpp src/client/tableview.cpp src/client/widget.cpp tmp/appcenter1.0.0/ && $(COPY_FILE) --parents appcenter.ts tmp/appcenter1.0.0/ && (cd `dirname tmp/appcenter1.0.0` && $(TAR) appcenter1.0.0.tar appcenter1.0.0 && $(COMPRESS) appcenter1.0.0.tar) && $(MOVE) `dirname tmp/appcenter1.0.0`/appcenter1.0.0.tar.gz . && $(DEL_FILE) -r tmp/appcenter1.0.0


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

compiler_moc_header_make_all: tmp/moc_appwidget.cpp tmp/moc_dashboard.cpp tmp/moc_center.cpp tmp/moc_appnode.cpp tmp/moc_center.cpp tmp/moc_itemdelegate.cpp tmp/moc_itemmodel.cpp tmp/moc_packageWidget.cpp tmp/moc_pictureframe.cpp tmp/moc_rftabbar.cpp tmp/moc_rftitlebar.cpp tmp/moc_tableview.cpp tmp/moc_widget.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) tmp/moc_appwidget.cpp tmp/moc_dashboard.cpp tmp/moc_center.cpp tmp/moc_appnode.cpp tmp/moc_center.cpp tmp/moc_itemdelegate.cpp tmp/moc_itemmodel.cpp tmp/moc_packageWidget.cpp tmp/moc_pictureframe.cpp tmp/moc_rftabbar.cpp tmp/moc_rftitlebar.cpp tmp/moc_tableview.cpp tmp/moc_widget.cpp
tmp/moc_appwidget.cpp: src/localapps.h \
		src/client/center.h \
		src/client/packageWidget.h \
		src/client/pictureframe.h \
		src/client/widget.h \
		src/client/tableview.h \
		src/client/appnode.h \
		src/client/itemmodel.h \
		src/client/itemdelegate.h \
		src/appwidget.h
	/usr/lib/qt4/bin/moc $(DEFINES) $(INCPATH) src/appwidget.h -o tmp/moc_appwidget.cpp

tmp/moc_dashboard.cpp: src/dashboard.h
	/usr/lib/qt4/bin/moc $(DEFINES) $(INCPATH) src/dashboard.h -o tmp/moc_dashboard.cpp

tmp/moc_center.cpp: src/client/packageWidget.h \
		src/client/pictureframe.h \
		src/client/widget.h \
		src/client/tableview.h \
		src/client/appnode.h \
		src/client/itemmodel.h \
		src/client/itemdelegate.h \
		src/client/center.h
	/usr/lib/qt4/bin/moc $(DEFINES) $(INCPATH) src/client/center.h -o tmp/moc_center.cpp

tmp/moc_appnode.cpp: src/client/appnode.h
	/usr/lib/qt4/bin/moc $(DEFINES) $(INCPATH) src/client/appnode.h -o tmp/moc_appnode.cpp

tmp/moc_center.cpp: src/client/packageWidget.h \
		src/client/pictureframe.h \
		src/client/widget.h \
		src/client/tableview.h \
		src/client/appnode.h \
		src/client/itemmodel.h \
		src/client/itemdelegate.h \
		src/client/center.h
	/usr/lib/qt4/bin/moc $(DEFINES) $(INCPATH) src/client/center.h -o tmp/moc_center.cpp

tmp/moc_itemdelegate.cpp: src/client/itemmodel.h \
		src/client/appnode.h \
		src/client/itemdelegate.h
	/usr/lib/qt4/bin/moc $(DEFINES) $(INCPATH) src/client/itemdelegate.h -o tmp/moc_itemdelegate.cpp

tmp/moc_itemmodel.cpp: src/client/appnode.h \
		src/client/itemmodel.h
	/usr/lib/qt4/bin/moc $(DEFINES) $(INCPATH) src/client/itemmodel.h -o tmp/moc_itemmodel.cpp

tmp/moc_packageWidget.cpp: src/client/pictureframe.h \
		src/client/widget.h \
		src/client/tableview.h \
		src/client/appnode.h \
		src/client/itemmodel.h \
		src/client/itemdelegate.h \
		src/client/packageWidget.h
	/usr/lib/qt4/bin/moc $(DEFINES) $(INCPATH) src/client/packageWidget.h -o tmp/moc_packageWidget.cpp

tmp/moc_pictureframe.cpp: src/client/widget.h \
		src/client/pictureframe.h
	/usr/lib/qt4/bin/moc $(DEFINES) $(INCPATH) src/client/pictureframe.h -o tmp/moc_pictureframe.cpp

tmp/moc_rftabbar.cpp: src/client/rftabbar.h
	/usr/lib/qt4/bin/moc $(DEFINES) $(INCPATH) src/client/rftabbar.h -o tmp/moc_rftabbar.cpp

tmp/moc_rftitlebar.cpp: src/client/rftitlebar.h
	/usr/lib/qt4/bin/moc $(DEFINES) $(INCPATH) src/client/rftitlebar.h -o tmp/moc_rftitlebar.cpp

tmp/moc_tableview.cpp: src/client/appnode.h \
		src/client/itemmodel.h \
		src/client/itemdelegate.h \
		src/client/tableview.h
	/usr/lib/qt4/bin/moc $(DEFINES) $(INCPATH) src/client/tableview.h -o tmp/moc_tableview.cpp

tmp/moc_widget.cpp: src/client/widget.h
	/usr/lib/qt4/bin/moc $(DEFINES) $(INCPATH) src/client/widget.h -o tmp/moc_widget.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: tmp/qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) tmp/qmake_image_collection.cpp
compiler_moc_source_make_all: tmp/packageWidget.moc
compiler_moc_source_clean:
	-$(DEL_FILE) tmp/packageWidget.moc
tmp/packageWidget.moc: src/client/packageWidget.h \
		src/client/pictureframe.h \
		src/client/widget.h \
		src/client/tableview.h \
		src/client/appnode.h \
		src/client/itemmodel.h \
		src/client/itemdelegate.h \
		src/client/packageWidget.cpp
	/usr/lib/qt4/bin/moc $(DEFINES) $(INCPATH) src/client/packageWidget.cpp -o tmp/packageWidget.moc

compiler_uic_make_all:
compiler_uic_clean:
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_moc_source_clean 

####### Compile

tmp/appwidget.o: src/appwidget.cpp src/appwidget.h \
		src/localapps.h \
		src/client/center.h \
		src/client/packageWidget.h \
		src/client/pictureframe.h \
		src/client/widget.h \
		src/client/tableview.h \
		src/client/appnode.h \
		src/client/itemmodel.h \
		src/client/itemdelegate.h \
		src/constants.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o tmp/appwidget.o src/appwidget.cpp

tmp/dashboard.o: src/dashboard.cpp src/dashboard.h \
		src/appwidget.h \
		src/localapps.h \
		src/client/center.h \
		src/client/packageWidget.h \
		src/client/pictureframe.h \
		src/client/widget.h \
		src/client/tableview.h \
		src/client/appnode.h \
		src/client/itemmodel.h \
		src/client/itemdelegate.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o tmp/dashboard.o src/dashboard.cpp

tmp/localapps.o: src/localapps.cpp src/localapps.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o tmp/localapps.o src/localapps.cpp

tmp/main.o: src/main.cpp src/dashboard.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o tmp/main.o src/main.cpp

tmp/applist.o: src/client/applist.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o tmp/applist.o src/client/applist.cpp

tmp/appnode.o: src/client/appnode.cpp src/client/appnode.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o tmp/appnode.o src/client/appnode.cpp

tmp/center.o: src/client/center.cpp src/client/rftabbar.h \
		src/client/rftitlebar.h \
		src/client/center.h \
		src/client/packageWidget.h \
		src/client/pictureframe.h \
		src/client/widget.h \
		src/client/tableview.h \
		src/client/appnode.h \
		src/client/itemmodel.h \
		src/client/itemdelegate.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o tmp/center.o src/client/center.cpp

tmp/itemdelegate.o: src/client/itemdelegate.cpp src/client/itemdelegate.h \
		src/client/itemmodel.h \
		src/client/appnode.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o tmp/itemdelegate.o src/client/itemdelegate.cpp

tmp/itemmodel.o: src/client/itemmodel.cpp src/client/itemmodel.h \
		src/client/appnode.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o tmp/itemmodel.o src/client/itemmodel.cpp

tmp/packageWidget.o: src/client/packageWidget.cpp src/client/packageWidget.h \
		src/client/pictureframe.h \
		src/client/widget.h \
		src/client/tableview.h \
		src/client/appnode.h \
		src/client/itemmodel.h \
		src/client/itemdelegate.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o tmp/packageWidget.o src/client/packageWidget.cpp

tmp/pictureframe.o: src/client/pictureframe.cpp src/client/pictureframe.h \
		src/client/widget.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o tmp/pictureframe.o src/client/pictureframe.cpp

tmp/rftabbar.o: src/client/rftabbar.cpp src/client/rftabbar.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o tmp/rftabbar.o src/client/rftabbar.cpp

tmp/rftitlebar.o: src/client/rftitlebar.cpp src/client/rftitlebar.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o tmp/rftitlebar.o src/client/rftitlebar.cpp

tmp/tableview.o: src/client/tableview.cpp src/client/tableview.h \
		src/client/appnode.h \
		src/client/itemmodel.h \
		src/client/itemdelegate.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o tmp/tableview.o src/client/tableview.cpp

tmp/widget.o: src/client/widget.cpp src/client/widget.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o tmp/widget.o src/client/widget.cpp

tmp/moc_appwidget.o: tmp/moc_appwidget.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o tmp/moc_appwidget.o tmp/moc_appwidget.cpp

tmp/moc_dashboard.o: tmp/moc_dashboard.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o tmp/moc_dashboard.o tmp/moc_dashboard.cpp

tmp/moc_center.o: tmp/moc_center.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o tmp/moc_center.o tmp/moc_center.cpp

tmp/moc_appnode.o: tmp/moc_appnode.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o tmp/moc_appnode.o tmp/moc_appnode.cpp

tmp/moc_itemdelegate.o: tmp/moc_itemdelegate.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o tmp/moc_itemdelegate.o tmp/moc_itemdelegate.cpp

tmp/moc_itemmodel.o: tmp/moc_itemmodel.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o tmp/moc_itemmodel.o tmp/moc_itemmodel.cpp

tmp/moc_packageWidget.o: tmp/moc_packageWidget.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o tmp/moc_packageWidget.o tmp/moc_packageWidget.cpp

tmp/moc_pictureframe.o: tmp/moc_pictureframe.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o tmp/moc_pictureframe.o tmp/moc_pictureframe.cpp

tmp/moc_rftabbar.o: tmp/moc_rftabbar.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o tmp/moc_rftabbar.o tmp/moc_rftabbar.cpp

tmp/moc_rftitlebar.o: tmp/moc_rftitlebar.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o tmp/moc_rftitlebar.o tmp/moc_rftitlebar.cpp

tmp/moc_tableview.o: tmp/moc_tableview.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o tmp/moc_tableview.o tmp/moc_tableview.cpp

tmp/moc_widget.o: tmp/moc_widget.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o tmp/moc_widget.o tmp/moc_widget.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

