cmake_minimum_required(VERSION 3.15)
project(wxWidgetsBook-launch LANGUAGES CXX)

file(GLOB SRC_FILES *.cpp *.h)
add_library(${PROJECT_NAME} ${SRC_FILES})
if(VCPKG_INCLUDE_DIR)
  # This works around a bug in which the VCPKG include directory is not used by
  # the add_library() command.
  target_include_directories(${PROJECT_NAME} PRIVATE ${VCPKG_INCLUDE_DIR})
endif()
