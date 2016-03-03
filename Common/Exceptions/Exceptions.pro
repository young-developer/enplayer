#-------------------------------------------------
#
# Project created by QtCreator 2015-11-04T21:10:56
#
#-------------------------------------------------

QT       -= gui

TARGET = Exceptions
TEMPLATE = lib
CONFIG += staticlib

SOURCES += \
    ExApp.cpp \
    ExMessagebox.cpp \
    QtException.cpp \
    NullPointerException.cpp

HEADERS += \
    ExApp.h \
    ExMessagebox.h \
    QtException.h \
    NullPointerException.h \
    CommonException.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
