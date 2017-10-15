# Specify the minimum version for CMake

CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

# Project's name

PROJECT(SuperFakeBox CXX)
# Set the output folder where your program will be created
SET(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
SET(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
SET(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

# enable C++11 standard
SET(CMAKE_CXX_STANDARD 11)  

# The following folder will be included
SET(SOURCES src/main.cpp)

INCLUDE(src/CMakeLists.txt)
INCLUDE(src/Weapons/CMakeLists.txt)
INCLUDE(src/Enemies/CMakeLists.txt)
INCLUDE(src/ParticleSystem/CMakeLists.txt)
INCLUDE(src/Physics/CMakeLists.txt)
INCLUDE(src/ResourceManager/CMakeLists.txt)

ADD_EXECUTABLE(SuperFakeBox ${SOURCES})

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

# Detect and add SFML
find_package(SFML 2 REQUIRED system window graphics network audio)
if(SFML_FOUND)
  include_directories(${SFML_INCLUDE_DIR})
  target_link_libraries(SuperFakeBox ${SFML_LIBRARIES})
endif()

