#-------------------------------------------------
#
# Project created by QtCreator 2015-08-01T16:33:02
# Project Semantic Versioning http://semver.org/
#-------------------------------------------------

win32:VERSION = 0.6.8.1 # major.minor.patch.build
else:VERSION = 0.6.8    # major.minor.patch

DEFINES += APP_VERSION_NUMBER=\\\"0.6.8\\\"
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

#Qt Network wrapper

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

# LibVLC
unix|win32: LIBS += -L$$PWD/../Core/3dparty/libvlc-qt/lib/ -lvlc-qt

INCLUDEPATH += $$PWD/../Core/3dparty/libvlc-qt/include
DEPENDPATH += $$PWD/../Core/3dparty/libvlc-qt/include

unix|win32: LIBS += -L$$PWD/../Core/3dparty/libvlc-qt/lib/ -lvlc-qt-widgets

INCLUDEPATH += $$PWD/../Core/3dparty/libvlc-qt/include
DEPENDPATH += $$PWD/../Core/3dparty/libvlc-qt/include

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

#Subtitle Parser library

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../SubParser/build-SubParser-Desktop_Qt_5_5_0_MSVC2013_64bit-Release/release/ -lSubParser
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../SubParser/build-SubParser-Desktop_Qt_5_5_0_MSVC2013_64bit-Debug/debug/ -lSubParser
else:unix: LIBS += -L$$PWD/../../SubParser/build-SubParser-Desktop_Qt_5_5_0_MSVC2013_64bit-Debug/ -lSubParser

INCLUDEPATH += $$PWD/../../SubParser
DEPENDPATH += $$PWD/../../SubParser
