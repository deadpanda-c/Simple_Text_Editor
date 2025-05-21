cmake_minimum_required(VERSION 3.22)
project(text_editor)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)

include_directories(
  include
  ${CMAKE_CURRENT_SOURCE_DIR}/lib/logging/include
)
file(GLOB_RECURSE SOURCES
  src/*.cpp
)


find_package(Qt5 COMPONENTS Widgets REQUIRED)
add_executable(text_editor ${SOURCES})
target_link_libraries(text_editor Qt5::Widgets)

add_subdirectory(lib/logging)
target_link_libraries(text_editor logging)
