#-------------------------------------------------
#
# Project created by QtCreator 2015-08-22T17:11:57
#
#-------------------------------------------------

QT       -= gui-common
QT       += core widgets
TARGET = GUI
TEMPLATE = lib
CONFIG += staticlib

SOURCES += gui.cpp \
    Layout/flowlayout.cpp

HEADERS += gui.h \
    Layout/flowlayout.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
