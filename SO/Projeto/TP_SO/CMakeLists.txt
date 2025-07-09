cmake_minimum_required(VERSION 3.28)
project(TP_SO C)

set(CMAKE_CXX_STANDARD 14)

include_directories(/usr/include/glib-2.0)
include_directories(/usr/lib/x86_64-linux-gnu/glib-2.0/include)
include_directories(/usr/include/glib-2.0)
include_directories(/usr/include/glib-2.0/glib)
include_directories(../include/)

add_executable(TP_SO
    makefile
        include/document.h
        src/document.c
        include/message.h
        src/dclient.c
        src/dserver.c)
