############################################################
#    >  CopyRight   :                                      #
#    >  File Name   : CMakeLists.txt
#    >  Author      : zhuhaiwen                            #
#    >  mail        : zhwren0211@whu.edu.cn                #
#    >  Created Time: 2016-06-22 14:14                     #
#    >  PhoneNumber : 18625272373                          #
############################################################
CMAKE_MINIMUM_REQUIRED(VERSION 3.0)
PROJECT(MyQQ.exe)

FIND_PACKAGE(Qt5Widgets)
ADD_EXECUTABLE(MyQQ.exe main.cc ShowAreaDialog.cc ShowAreaDialog.hh)
TARGET_LINK_LIBRARIES(MyQQ.exe Qt5::Widgets)
