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

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../3dparty/sub-parser/lib/ -lSubParser
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../3dparty/sub-parser/lib/ -lSubParser
else:unix: LIBS += -L$$PWD/../3dparty/sub-parser/lib/ -lSubParser

INCLUDEPATH += $$PWD/../3dparty/sub-parser/include
DEPENDPATH += $$PWD/../3dparty/sub-parser/include

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../Common/Services/release/ -lServices
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../Common/Services/debug/ -lServices
else:unix: LIBS += -L$$OUT_PWD/../../Common/Services/ -lServices

INCLUDEPATH += $$PWD/../../Common/Services
DEPENDPATH += $$PWD/../../Common/Services

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Common/Services/release/libServices.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Common/Services/debug/libServices.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Common/Services/release/Services.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Common/Services/debug/Services.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../../Common/Services/libServices.a

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../Common/Exceptions/release/ -lExceptions
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../Common/Exceptions/debug/ -lExceptions
else:unix: LIBS += -L$$OUT_PWD/../../Common/Exceptions/ -lExceptions

INCLUDEPATH += $$PWD/../../Common/Exceptions
DEPENDPATH += $$PWD/../../Common/Exceptions

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Common/Exceptions/release/libExceptions.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Common/Exceptions/debug/libExceptions.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Common/Exceptions/release/Exceptions.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Common/Exceptions/debug/Exceptions.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../../Common/Exceptions/libExceptions.a

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
