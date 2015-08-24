#-------------------------------------------------
#
# Project created by QtCreator 2015-08-24T21:58:34
#
#-------------------------------------------------

QT       += widgets

TARGET = DomainLogic
TEMPLATE = lib
CONFIG += staticlib

SOURCES += domainlogic.cpp \
    enplayer.cpp \
    Subtitles/subtitlemanager.cpp

HEADERS += domainlogic.h \
    enplayer.h \
    Subtitles/subtitlemanager.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../GUI/release/ -lGUI
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../GUI/debug/ -lGUI
else:unix: LIBS += -L$$OUT_PWD/../GUI/ -lGUI

INCLUDEPATH += $$PWD/../GUI
DEPENDPATH += $$PWD/../GUI

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../GUI/release/libGUI.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../GUI/debug/libGUI.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../GUI/release/GUI.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../GUI/debug/GUI.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../GUI/libGUI.a

unix|win32: LIBS += -L$$PWD/../3dparty/libvlc-qt/lib/ -lvlc-qt

INCLUDEPATH += $$PWD/../3dparty/libvlc-qt/include
DEPENDPATH += $$PWD/../3dparty/libvlc-qt/include

unix|win32: LIBS += -L$$PWD/../3dparty/libvlc-qt/lib/ -lvlc-qt-widgets

INCLUDEPATH += $$PWD/../3dparty/libvlc-qt/include
DEPENDPATH += $$PWD/../3dparty/libvlc-qt/include
