QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += main.cpp mainwindow.cpp interface_info.cpp

HEADERS += mainwindow.h interface_info.h

LIBS += -L../../boost_1_80_0/stage/lib/ -lboost_system-mgw7-mt-d-x64-1_80

INCLUDEPATH += ../../boost_1_80_0
DEPENDPATH += ../../boost_1_80_0
