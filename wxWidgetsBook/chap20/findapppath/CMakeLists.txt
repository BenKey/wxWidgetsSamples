cmake_minimum_required(VERSION 3.15)
project(wxWidgetsBook-findapppath LANGUAGES CXX)

file(GLOB SRC_FILES *.cpp *.h)
add_library(${PROJECT_NAME} ${SRC_FILES})
# When the "Unix Makefiles" and "Visual Studio 17 2022" generators are used,
# the VCPKG include directories are not automatically added to the include
# path when the add_library() command is used. The add_executable() command
# does not have this problem. 
if(VCPKG_INCLUDE_DIR)
  target_include_directories(${PROJECT_NAME} PRIVATE ${VCPKG_INCLUDE_DIR})
endif()
if(VCPKG_INCLUDE_WX_DIR)
  target_include_directories(${PROJECT_NAME} PRIVATE ${VCPKG_INCLUDE_WX_DIR})
endif()
