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

unix|win32: LIBS += -L$$PWD/../3dparty/libvlc-qt/lib/ -lvlc-qt

INCLUDEPATH += $$PWD/../3dparty/libvlc-qt/include
DEPENDPATH += $$PWD/../3dparty/libvlc-qt/include

unix|win32: LIBS += -L$$PWD/../3dparty/libvlc-qt/lib/ -lvlc-qt-widgets

INCLUDEPATH += $$PWD/../3dparty/libvlc-qt/include
DEPENDPATH += $$PWD/../3dparty/libvlc-qt/include

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../GUI/release/ -lGUI-core
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../GUI/debug/ -lGUI-core
else:unix: LIBS += -L$$OUT_PWD/../GUI/ -lGUI-core

INCLUDEPATH += $$PWD/../GUI
DEPENDPATH += $$PWD/../GUI

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../GUI/release/libGUI-core.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../GUI/debug/libGUI-core.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../GUI/release/GUI-core.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../GUI/debug/GUI-core.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../GUI/libGUI-core.a
