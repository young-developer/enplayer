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
    exapp.cpp \
    exmessagebox.cpp \
    qtexception.cpp

HEADERS += \
    exapp.h \
    exmessagebox.h \
    qtexception.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
