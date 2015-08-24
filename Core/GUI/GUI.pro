#-------------------------------------------------
#
# Project created by QtCreator 2015-08-22T17:13:35
#
#-------------------------------------------------

QT += widgets

TARGET = GUI
TEMPLATE = lib
CONFIG += staticlib

SOURCES += gui.cpp \
    controlpanel.cpp \
    Subtitles/subtitlepanel.cpp \
    Subtitles/subtitlelabel.cpp

HEADERS += gui.h \
    controlpanel.h \
    Subtitles/subtitlepanel.h \
    Subtitles/subtitlelabel.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}


win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../Common/GUI/release/ -lGUI
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../Common/GUI/debug/ -lGUI
else:unix: LIBS += -L$$OUT_PWD/../../Common/GUI/ -lGUI

INCLUDEPATH += $$PWD/../../Common/GUI
DEPENDPATH += $$PWD/../../Common/GUI

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Common/GUI/release/libGUI.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Common/GUI/debug/libGUI.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Common/GUI/release/GUI.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Common/GUI/debug/GUI.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../../Common/GUI/libGUI.a

unix|win32: LIBS += -L$$PWD/../3dparty/libvlc-qt/lib/ -lvlc-qt

INCLUDEPATH += $$PWD/../3dparty/libvlc-qt/include
DEPENDPATH += $$PWD/../3dparty/libvlc-qt/include

unix|win32: LIBS += -L$$PWD/../3dparty/libvlc-qt/lib/ -lvlc-qt-widgets

INCLUDEPATH += $$PWD/../3dparty/libvlc-qt/include
DEPENDPATH += $$PWD/../3dparty/libvlc-qt/include
