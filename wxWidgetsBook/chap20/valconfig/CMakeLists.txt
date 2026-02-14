cmake_minimum_required(VERSION 3.25.0)
project(wxWidgetsBook-valconfig LANGUAGES CXX)

file(GLOB SOURCE_FILES *.cpp *.h)
add_library(${PROJECT_NAME} ${SOURCE_FILES})
if(CMAKE_SYSTEM_NAME STREQUAL "Linux" AND USE_GTK)
  target_compile_definitions(${PROJECT_NAME} PRIVATE __WXGTK3__ __WXGTK__)
endif()
