cmake_minimum_required(VERSION 3.5)
project(cutils)

if (CMAKE_VERSION VERSION_LESS 3.0.0)
  set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
else()
  set(CMAKE_CXX_STANDARD 11)
endif()
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

include_directories(
    ${CMAKE_SOURCE_DIR}/include
)

if (CMAKE_SYSTEM_NAME MATCHES "Windows")
elseif (CMAKE_SYSTEM_NAME MATCHES "Linux")
#BDS is linked to libc++ since 1.20.40
  if(NOT "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    message(NOTICE "Setting compiler to clang++")
    set(CMAKE_CXX_COMPILER "clang++")
  endif()
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -stdlib=libc++")
endif()

add_library(cutils STATIC "src/string.cpp")
