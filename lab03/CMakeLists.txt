cmake_minimum_required (VERSION 2.8.9)

project(exec CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

#set(LIBSRC wire.h wire.cpp)
#add_library(libtest ${LIBSRC})
include_directories(${PROJECT_SOURCE_DIR}/include)
file(GLOB SOURCES "${PROJECT_SOURCE_DIR}/src/*.cpp")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}-DLIB_TEST -Wall -pedantic")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG}")
set(CMAKE_CXX_FLAGS_RELEASE "-DNDEBUG -O2")

add_executable(${PROJECT_NAME} ${SOURCES})

include(CTest)
add_test(check ${PROJECT_NAME})

add_custom_target(run COMMAND ${PROJECT_NAME} DEPENDS ${PROJECT_NAME} WORKING_DIRECTORY ${CMAKE_PROJECT_DIR})

