cmake_minimum_required(VERSION 3.17)
project(Milestone_2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")
set(CMAKE_CXX_STANDARD 17)

include_directories(.)

add_executable(Milestone_2
        main.cpp
        CONTROLLER.h
        CPU.h
        #GUI.cpp
        MemoryDump.h
        MenuStrings.h
        MODEL.h
        VIEW.h)
