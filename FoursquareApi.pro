#-------------------------------------------------
#
# Project created by QtCreator 2011-01-20T22:59:05
#
#-------------------------------------------------

QT       += core network script

QT       -= gui

TARGET = FoursquareApi
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    api/foursquareapi.cpp \
    api/checkin.cpp \
    api/user.cpp \
    api/venue.cpp

HEADERS += \
    api/foursquareapi.h \
    api/checkin.h \
    api/user.h \
    api/venue.h
