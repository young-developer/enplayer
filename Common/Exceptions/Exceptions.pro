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
    qtexception.cpp \
    nullpointerexception.cpp

HEADERS += \
    exapp.h \
    exmessagebox.h \
    qtexception.h \
    nullpointerexception.h \
    commonexception.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
