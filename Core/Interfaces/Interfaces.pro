#-------------------------------------------------
#
# Project created by QtCreator 2015-12-24T12:25:31
#
#-------------------------------------------------

QT       -= gui

TARGET = Interfaces
TEMPLATE = lib
CONFIG += staticlib

SOURCES += interfaces.cpp

HEADERS += interfaces.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
