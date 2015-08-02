#-------------------------------------------------
#
# Project created by QtCreator 2015-08-01T16:33:02
# Project use Semantic Versioning http://semver.org/
#-------------------------------------------------
VERSION = 0.1.1
DEFINES += VERSION_NUMBER=\\\"0.1.1\\\"

QT       += core gui widgets

TARGET = Player
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

# Edit below for custom library location
LIBS     += -LC:\Qt\libvlc-qt\lib -lvlc-qt -lvlc-qt-widgets
INCLUDEPATH += C:\Qt\libvlc-qt\include
