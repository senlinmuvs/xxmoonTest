QT += testlib
QT += widgets
QT += qml
QT += quick
QT += quickcontrols2
QT += sql
QT += network

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle
CONFIG += testcase

TEMPLATE = app

SOURCES +=  tst_xxmoontest.cpp

include(../xxmoon/xxmoon.pri)
