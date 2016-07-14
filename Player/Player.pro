#-------------------------------------------------
#
# Project created by QtCreator 2015-08-01T16:33:02
# Project Semantic Versioning http://semver.org/
#-------------------------------------------------

win32:VERSION = 0.6.9.0 # major.minor.patch.build
else:VERSION = 0.6.9    # major.minor.patch

DEFINES += APP_VERSION_NUMBER=\\\"0.6.9\\\"
DEFINES += APP_NAME=\\\"EnPlayer\\\"
DEFINES += APP_LOG_FILENAME=\\\"log.txt\\\"

QT       += core gui widgets network xml

TARGET = Player
TEMPLATE = app

PKGCONFIG += openssl

SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui \
    aboutdialog.ui

# Edit below for custom library location

#Exceptions

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Common/Exceptions/release/ -lExceptions
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Common/Exceptions/debug/ -lExceptions
else:unix: LIBS += -L$$OUT_PWD/../Common/Exceptions/ -lExceptions

INCLUDEPATH += $$PWD/../Common/Exceptions
DEPENDPATH += $$PWD/../Common/Exceptions

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Common/Exceptions/release/libExceptions.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Common/Exceptions/debug/libExceptions.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Common/Exceptions/release/Exceptions.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Common/Exceptions/debug/Exceptions.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../Common/Exceptions/libExceptions.a

#DOMAIN LOGIC

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

# Common Translate Services

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Common/Services/release/ -lServices
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Common/Services/debug/ -lServices
else:unix: LIBS += -L$$OUT_PWD/../Common/Services/ -lServices

INCLUDEPATH += $$PWD/../Common/Services
DEPENDPATH += $$PWD/../Common/Services

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Common/Services/release/libServices.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Common/Services/debug/libServices.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Common/Services/release/Services.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Common/Services/debug/Services.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../Common/Services/libServices.a

#Subtitle Parser library
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../Core/3dparty/sub-parser/lib/ -lSubParser
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../Core/3dparty/sub-parser/lib/ -lSubParser_d
else:unix: LIBS += -L$$PWD/../Core/3dparty/sub-parser/lib/ -lSubParser
unix: PRE_TARGETDEPS += $$OUT_PWD/../Core/3dparty/sub-parser/lib/libSubParser.a

INCLUDEPATH += $$PWD/../Core/3dparty/sub-parser/include
DEPENDPATH += $$PWD/../Core/3dparty/sub-parser/include

# CORE APPLICATION GUI
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

# LibVLC

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../Core/3dparty/libvlc-qt/lib/ -lvlc-qt
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../Core/3dparty/libvlc-qt/lib/ -lvlc-qt
else:unix: LIBS += -L$$PWD/../Core/3dparty/libvlc-qt/lib/ -lvlc-qt.dll
unix: PRE_TARGETDEPS += $$OUT_PWD/../Core/3dparty/libvlc-qt/lib/libvlc-qt.dll.a

INCLUDEPATH += $$PWD/../Core/3dparty/libvlc-qt/include
DEPENDPATH += $$PWD/../Core/3dparty/libvlc-qt/include

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../Core/3dparty/libvlc-qt/lib/ -lvlc-qt-widgets
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../Core/3dparty/libvlc-qt/lib/ -lvlc-qt-widgets
else:unix: LIBS += -L$$PWD/../Core/3dparty/libvlc-qt/lib/ -lvlc-qt-widgets.dll
unix: PRE_TARGETDEPS += $$OUT_PWD/../Core/3dparty/libvlc-qt/lib/libvlc-qt-widgets.dll.a

INCLUDEPATH += $$PWD/../Core/3dparty/libvlc-qt/include
DEPENDPATH += $$PWD/../Core/3dparty/libvlc-qt/include

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Common/Network/release/ -lNetwork
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Common/Network/debug/ -lNetwork
else:unix: LIBS += -L$$OUT_PWD/../Common/Network/ -lNetwork

INCLUDEPATH += $$PWD/../Common/Network
DEPENDPATH += $$PWD/../Common/Network

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Common/Network/release/libNetwork.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Common/Network/debug/libNetwork.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Common/Network/release/Network.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Common/Network/debug/Network.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../Common/Network/libNetwork.a

unix: LIBS += -lvlc -lvlccore

#Common application GUI

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
