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
    world.cpp \
geometric_objects.cpp \
    raytracer.cpp \
    vector.cpp

HEADERS  += mainwindow.h \
    camera.h \
    hit_info.h \
    ray.h \
    vector.h \
    world.h \
    geometric_objects.h \
    raytracer.h

FORMS    += mainwindow.ui
