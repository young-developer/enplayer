#-------------------------------------------------
#
# Project created by QtCreator 2015-08-01T16:33:02
# Project use Semantic Versioning http://semver.org/
#-------------------------------------------------
VERSION = 0.1.0
DEFINES += VERSION_NUMBER=\\\"0.1.0\\\"

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Player
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui
