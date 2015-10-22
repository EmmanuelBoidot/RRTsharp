#-------------------------------------------------
#
# Project created by QtCreator 2015-10-20T12:05:56
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RRTsharp
TEMPLATE = app

CONFIG += c++11

SOURCES += RRTsharp.cpp \
        window.cpp \
        main.cpp \
#        sharp_planning.cpp\

HEADERS  += window.h \
        RRTsharp.h

unix: LIBS += -L/opt/ros/indigo/lib/x86_64-linux-gnu/ -L/usr/lib/x86_64-linux-gnu/ -lompl -lompl_app -lompl_app_base -lboost_thread -lboost_system

INCLUDEPATH += /opt/ros/indigo/include
DEPENDPATH += /opt/ros/indigo/include
