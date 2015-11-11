#-------------------------------------------------
#
# Project created by QtCreator 2015-11-11T13:56:52
#
#-------------------------------------------------

QT       += core network

QT       -= gui

TARGET = Network
TEMPLATE = lib
CONFIG += staticlib

SOURCES += \
    NetworkManager.cpp \
    Request.cpp \
    RequestSender.cpp

HEADERS += \
    NetworkManager.h \
    Request.h \
    RequestSender.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
