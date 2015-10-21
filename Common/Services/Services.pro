#-------------------------------------------------
#
# Project created by QtCreator 2015-08-22T17:11:57
#
#-------------------------------------------------

QT       += widgets network
TARGET = Services
TEMPLATE = lib
CONFIG += staticlib

SOURCES += \
    ITranslateService.cpp \
    YandexTranslate.cpp \
    GoogleTranslate.cpp \
    BingTranslate.cpp \
    TranslateManager.cpp \
    NetworkManager.cpp

HEADERS += \
    ITranslateService.h \
    YandexTranslate.h \
    GoogleTranslate.h \
    BingTranslate.h \
    TranslateManager.h \
    NetworkManager.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
