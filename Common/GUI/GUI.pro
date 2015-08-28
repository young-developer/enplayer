#-------------------------------------------------
#
# Project created by QtCreator 2015-08-22T17:11:57
#
#-------------------------------------------------

QT       += widgets
TARGET = GUI-cmn
TEMPLATE = lib
CONFIG += staticlib

SOURCES += \
    Layout/flowlayout.cpp \
    gui-cmn.cpp

HEADERS += \
    Layout/flowlayout.h \
    gui-cmn.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
