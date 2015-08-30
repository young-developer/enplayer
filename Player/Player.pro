#-------------------------------------------------
#
# Project created by QtCreator 2015-08-01T16:33:02
# Project Semantic Versioning http://semver.org/
#-------------------------------------------------
VERSION = 0.4.4
DEFINES += VERSION_NUMBER=\\\"0.4.4\\\"

QT       += core gui widgets

TARGET = Player
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

# Edit below for custom library location

unix|win32: LIBS += -L$$PWD/../Core/3dparty/libvlc-qt/lib/ -lvlc-qt

INCLUDEPATH += $$PWD/../Core/3dparty/libvlc-qt/include
DEPENDPATH += $$PWD/../Core/3dparty/libvlc-qt/include

unix|win32: LIBS += -L$$PWD/../Core/3dparty/libvlc-qt/lib/ -lvlc-qt-widgets

INCLUDEPATH += $$PWD/../Core/3dparty/libvlc-qt/include
DEPENDPATH += $$PWD/../Core/3dparty/libvlc-qt/include


win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Core/GUI/release/ -lGUI-core
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Core/GUI/debug/ -lGUI-core
else:unix: LIBS += -L$$OUT_PWD/../Core/GUI/ -lGUI-core

INCLUDEPATH += $$PWD/../Core/GUI
DEPENDPATH += $$PWD/../Core/GUI

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Core/GUI/release/libGUI-core.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Core/GUI/debug/libGUI-core.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Core/GUI/release/GUI-core.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Core/GUI/debug/GUI-core.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../Core/GUI/libGUI-core.a

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Core/DomainLogic/release/ -lDomainLogic
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Core/DomainLogic/debug/ -lDomainLogic
else:unix: LIBS += -L$$OUT_PWD/../Core/DomainLogic/ -lDomainLogic

INCLUDEPATH += $$PWD/../Core/DomainLogic
DEPENDPATH += $$PWD/../Core/DomainLogic

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Core/DomainLogic/release/libDomainLogic.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Core/DomainLogic/debug/libDomainLogic.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Core/DomainLogic/release/DomainLogic.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Core/DomainLogic/debug/DomainLogic.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../Core/DomainLogic/libDomainLogic.a


win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Common/GUI/release/ -lGUI-cmn
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Common/GUI/debug/ -lGUI-cmn
else:unix: LIBS += -L$$OUT_PWD/../Common/GUI/ -lGUI-cmn

INCLUDEPATH += $$PWD/../Common/GUI
DEPENDPATH += $$PWD/../Common/GUI

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Common/GUI/release/libGUI-cmn.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Common/GUI/debug/libGUI-cmn.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Common/GUI/release/GUI-cmn.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Common/GUI/debug/GUI-cmn.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../Common/GUI/libGUI-cmn.a
