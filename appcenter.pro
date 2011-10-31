TEMPLATE = app
TARGET = 
DEPENDPATH += .
INCLUDEPATH += .
win32:CONFIG += console
Qt += DEBUG
Qt += QtSql 
Qt += webkit
LIBS += -lQtSql -lX11
TRANSLATIONS = appcenter.ts
#RESOURCES += res.qrc

HEADERS += src/dashboard.h \
           src/pager.h \
           src/iconarea.h

SOURCES += src/main.cpp \
           src/iconarea.cpp \
           src/pager.cpp \
           src/dashboard.cpp
