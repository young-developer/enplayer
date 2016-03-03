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
    Layout/FlowLayout.cpp \
    gui-cmn.cpp \
    CustomTooltip.cpp

HEADERS += \
    Layout/FlowLayout.h \
    gui-cmn.h \
    CustomTooltip.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
