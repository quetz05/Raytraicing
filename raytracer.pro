#-------------------------------------------------
#
# Project created by QtCreator 2013-01-04T18:20:08
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = raytracer
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    camera.cpp \
    world.cpp

HEADERS  += mainwindow.h \
    camera.h \
    geometricObjects.h \
    hit_info.h \
    ray.h \
    vector.h \
    world.h

FORMS    += mainwindow.ui
