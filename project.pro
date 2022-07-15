QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

CONFIG -= debug_and_release debug_and_release_target

include(mythread/mythread.pri)

SOURCES += \
    main.cpp \
    widget.cpp

HEADERS += \
    widget.h

