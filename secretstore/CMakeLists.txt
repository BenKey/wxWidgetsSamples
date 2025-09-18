cmake_minimum_required(VERSION 3.10)
project(secretstore LANGUAGES CXX)

if(WIN32)
  file(GLOB SRC_FILES *.cpp *.h ${CMAKE_SOURCE_DIR}/*.rc  ${CMAKE_SOURCE_DIR}/*.xpm)
  add_executable(secretstore ${SRC_FILES})
  target_link_libraries(secretstore PRIVATE ${wxWidgets_LIBRARIES})
endif()
