TEMPLATE = app
TARGET = 
DEPENDPATH += .
INCLUDEPATH += .
UI_DIR = ./tmp
MOC_DIR = ./tmp
OBJECTS_DIR = ./tmp
RCC_DIR = ./tmp

Qt += DEBUG
Qt += QtSql 
Qt += webkit
LIBS += -lQtSql

#ifdef LINUX_X11
LIBS += -lX11
#endif

TRANSLATIONS = appcenter.ts
#RESOURCES += res.qrc

HEADERS += src/dashboard.h \
           src/pager.h \
           src/iconarea.h

SOURCES += src/main.cpp \
           src/iconarea.cpp \
           src/pager.cpp \
           src/dashboard.cpp
