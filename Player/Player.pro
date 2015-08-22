#-------------------------------------------------
#
# Project created by QtCreator 2015-08-01T16:33:02
# Project Semantic Versioning http://semver.org/
#-------------------------------------------------
VERSION = 0.4.1
DEFINES += VERSION_NUMBER=\\\"0.4.1\\\"

QT       += core gui widgets

TARGET = Player
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    controlpanel.cpp \
    Subtitles/subtitlepanel.cpp \
    Subtitles/subtitlelabel.cpp \
    Subtitles/subtitlemanager.cpp

HEADERS  += mainwindow.h \
    controlpanel.h \
    Subtitles/subtitlepanel.h \
    Subtitles/subtitlelabel.h \
    Subtitles/subtitlemanager.h

FORMS    += mainwindow.ui

# Edit below for custom library location
LIBS     += -LC:\Qt\libvlc-qt\lib -lvlc-qt -lvlc-qt-widgets
INCLUDEPATH += C:\Qt\libvlc-qt\include

INCLUDEPATH += E:\Repositories\SubParser\

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Common/GUI/release/ -lGUI
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Common/GUI/debug/ -lGUI
else:unix: LIBS += -L$$OUT_PWD/../Common/GUI/ -lGUI

INCLUDEPATH += $$PWD/../Common/GUI
DEPENDPATH += $$PWD/../Common/GUI

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Common/GUI/release/libGUI.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Common/GUI/debug/libGUI.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Common/GUI/release/GUI.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Common/GUI/debug/GUI.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../Common/GUI/libGUI.a
