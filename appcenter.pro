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

HEADERS += src/appwidget.h \
           src/constants.h \
           src/dashboard.h \
           src/localapps.h \
           src/client/center.h \
           src/client/appnode.h \
           src/client/center.h \
           src/client/itemdelegate.h \
           src/client/itemmodel.h \
           src/client/packageWidget.h \
           src/client/pictureframe.h \
           src/client/rftabbar.h \
           src/client/rftitlebar.h \
           src/client/tableview.h \
           src/client/widget.h

SOURCES += src/appwidget.cpp \
           src/dashboard.cpp \
           src/localapps.cpp \
           src/main.cpp \
           src/client/appnode.cpp \
           src/client/center.cpp \
           src/client/itemdelegate.cpp \
           src/client/itemmodel.cpp \
           src/client/packageWidget.cpp \
           src/client/pictureframe.cpp \
           src/client/rftabbar.cpp \
           src/client/rftitlebar.cpp \
           src/client/tableview.cpp \
           src/client/widget.cpp

