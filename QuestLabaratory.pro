#-------------------------------------------------
#
# Project created by QtCreator 2014-07-28T20:29:40
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QuestLabaratory
TEMPLATE = app
QTPLUGIN += qsqloci qgif
CONFIG += static

SOURCES += main.cpp\
        laboratory.cpp

HEADERS  += laboratory.h

FORMS    += laboratory.ui
