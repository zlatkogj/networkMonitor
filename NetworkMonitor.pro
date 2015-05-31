#-------------------------------------------------
#
# Project created by QtCreator 2015-05-31T22:48:41
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = NetworkMonitor
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += \
    main.c

unix:!macx: LIBS += -lpcap
