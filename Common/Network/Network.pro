#-------------------------------------------------
#
# Project created by QtCreator 2015-11-11T13:56:52
#
#-------------------------------------------------

QT       += core network

QT       -= gui

TARGET = Network
TEMPLATE = lib
CONFIG += staticlib

SOURCES += \
    NetworkManager.cpp \
    Request.cpp \
    RequestSender.cpp

HEADERS += \
    NetworkManager.h \
    Request.h \
    RequestSender.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Exceptions/release/ -lExceptions
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Exceptions/debug/ -lExceptions
else:unix: LIBS += -L$$OUT_PWD/../Exceptions/ -lExceptions

INCLUDEPATH += $$PWD/../Exceptions
DEPENDPATH += $$PWD/../Exceptions

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Exceptions/release/libExceptions.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Exceptions/debug/libExceptions.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Exceptions/release/Exceptions.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Exceptions/debug/Exceptions.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../Exceptions/libExceptions.a
