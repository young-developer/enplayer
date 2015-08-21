#-------------------------------------------------
#
# Project created by QtCreator 2015-08-01T16:33:02
# Project use Semantic Versioning http://semver.org/
#-------------------------------------------------
VERSION = 0.3.1
DEFINES += VERSION_NUMBER=\\\"0.3.1\\\"

QT       += core gui widgets

TARGET = Player
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    controlpanel.cpp \
    Subtitles/subtitlepanel.cpp \
    Subtitles/subtitlelabel.cpp \
    flowlayout.cpp

HEADERS  += mainwindow.h \
    controlpanel.h \
    Subtitles/subtitlepanel.h \
    Subtitles/subtitlelabel.h \
    flowlayout.h

FORMS    += mainwindow.ui

# Edit below for custom library location
LIBS     += -LC:\Qt\libvlc-qt\lib -lvlc-qt -lvlc-qt-widgets
INCLUDEPATH += C:\Qt\libvlc-qt\include
