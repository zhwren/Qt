############################################################
#    >  CopyRight   :                                      #
#    >  File Name   : CMakeLists.txt
#    >  Author      : zhuhaiwen                            #
#    >  mail        : zhwren0211@whu.edu.cn                #
#    >  Created Time: 2016-06-22 14:10                     #
#    >  PhoneNumber : 18625272373                          #
############################################################
CMAKE_MINIMUM_REQUIRED(VERSION 3.0)
PROJECT(ShowArea)

FIND_PACKAGE(Qt4 REQUIRED)

FILE(GLOB showarea_SOURCES ${PROJECT_SOURCE_DIR}/*.cc)
FILE(GLOB showarea_HEADERS ${PROJECT_SOURCE_DIR}/*.hh)

QT4_WRAP_CPP(showarea_HEADERS_MOC ${showarea_HEADERS})
INCLUDE(${QT_USE_FILE})
ADD_DEFINITIONS(${QT_DEFINITIONS})

ADD_EXECUTABLE(ShowArea main.cc ${showarea_SOURCES} ${showarea_HEADERS_MOC})
TARGET_LINK_LIBRARIES(ShowArea ${QT_LIBRARIES})
