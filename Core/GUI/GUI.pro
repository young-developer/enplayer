#-------------------------------------------------
#
# Project created by QtCreator 2015-08-22T17:13:35
#
#-------------------------------------------------

QT       -= gui

TARGET = GUI
TEMPLATE = lib
CONFIG += staticlib

SOURCES += gui.cpp

HEADERS += gui.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
