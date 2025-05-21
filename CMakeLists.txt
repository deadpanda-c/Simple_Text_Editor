cmake_minimum_required(VERSION 3.22)
project(text_editor)
set(CMAKE_CXX_STANDARD 20)

include_directories(
  include
)
file(GLOB_RECURSE SOURCES
  src/*.cpp
)

add_executable(text_editor ${SOURCES})
