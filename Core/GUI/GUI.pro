#-------------------------------------------------
#
# Project created by QtCreator 2015-08-22T17:13:35
#
#-------------------------------------------------

QT += widgets

TARGET = GUI-core
TEMPLATE = lib
CONFIG += staticlib

SOURCES += \
    ControlPanel.cpp \
    Subtitles/SubtitlePanel.cpp \
    Subtitles/SubtitleLabel.cpp \
    gui-core.cpp

HEADERS += \
    ControlPanel.h \
    Subtitles/SubtitlePanel.h \
    Subtitles/SubtitleLabel.h \
    gui-core.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Interfaces/release/ -lInterfaces
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Interfaces/debug/ -lInterfaces
else:unix: LIBS += -L$$OUT_PWD/../Interfaces/ -lInterfaces

INCLUDEPATH += $$PWD/../Interfaces
DEPENDPATH += $$PWD/../Interfaces

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Interfaces/release/libInterfaces.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Interfaces/debug/libInterfaces.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Interfaces/release/Interfaces.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Interfaces/debug/Interfaces.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../Interfaces/libInterfaces.a

#VLC QT

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../3dparty/libvlc-qt/lib/ -lvlc-qt
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../3dparty/libvlc-qt/lib/ -llibvlc-qt.dll
else:unix: LIBS += -L$$PWD/../3dparty/libvlc-qt/lib/ -llibvlc-qt.dll

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../3dparty/libvlc-qt/lib/ -lvlc-qt-widgets
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../3dparty/libvlc-qt/lib/ -llibvlc-qt-widgets.dll
else:unix: LIBS += -L$$PWD/../3dparty/libvlc-qt/lib/ -llibvlc-qt-widgets.dll

INCLUDEPATH += $$PWD/../3dparty/libvlc-qt/include
DEPENDPATH += $$PWD/../3dparty/libvlc-qt/include

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../Common/GUI/release/ -lGUI-cmn
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../Common/GUI/debug/ -lGUI-cmn
else:unix: LIBS += -L$$OUT_PWD/../../Common/GUI/ -lGUI-cmn

INCLUDEPATH += $$PWD/../../Common/GUI
DEPENDPATH += $$PWD/../../Common/GUI

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Common/GUI/release/libGUI-cmn.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Common/GUI/debug/libGUI-cmn.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Common/GUI/release/GUI-cmn.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Common/GUI/debug/GUI-cmn.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../../Common/GUI/libGUI-cmn.a
