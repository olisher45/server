QT += testlib
QT -= gui

QT += core
QT += network
QT += sql

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_server_test.cpp

SOURCES += ../server/database.cpp \
    ../server/server.cpp \
    ../server/tcpserver.cpp \
    ../server/taskmanager.cpp

HEADERS += ../server/database.h \
    ../server/server.h \
    ../server/tcpserver.h \
    ../server/taskmanager.h
