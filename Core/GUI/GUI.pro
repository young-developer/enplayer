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
    controlpanel.cpp \
    Subtitles/subtitlepanel.cpp \
    Subtitles/subtitlelabel.cpp \
    gui-core.cpp

HEADERS += \
    controlpanel.h \
    Subtitles/subtitlepanel.h \
    Subtitles/subtitlelabel.h \
    gui-core.h
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
