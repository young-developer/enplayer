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
    Subtitles/subtitlemanager.cpp

HEADERS  += mainwindow.h \
    controlpanel.h \
    Subtitles/subtitlemanager.h

FORMS    += mainwindow.ui

# Edit below for custom library location

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Core/GUI/release/ -lGUI
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Core/GUI/debug/ -lGUI
else:unix: LIBS += -L$$OUT_PWD/../Core/GUI/ -lGUI

INCLUDEPATH += $$PWD/../Core/GUI
DEPENDPATH += $$PWD/../Core/GUI

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Core/GUI/release/libGUI.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Core/GUI/debug/libGUI.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Core/GUI/release/GUI.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Core/GUI/debug/GUI.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../Core/GUI/libGUI.a

unix|win32: LIBS += -L$$PWD/../Core/3dparty/libvlc-qt/lib/ -lvlc-qt

INCLUDEPATH += $$PWD/../Core/3dparty/libvlc-qt/include
DEPENDPATH += $$PWD/../Core/3dparty/libvlc-qt/include

unix|win32: LIBS += -L$$PWD/../Core/3dparty/libvlc-qt/lib/ -lvlc-qt-widgets

INCLUDEPATH += $$PWD/../Core/3dparty/libvlc-qt/include
DEPENDPATH += $$PWD/../Core/3dparty/libvlc-qt/include
