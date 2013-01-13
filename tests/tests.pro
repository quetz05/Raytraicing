#-------------------------------------------------
#
# Project created by QtCreator 2013-01-13T13:57:58
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

TARGET = tst_teststest
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += tst_teststest.cpp \
    vector_test.cpp \
    ../vector.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

HEADERS += \
    vector_test.h
