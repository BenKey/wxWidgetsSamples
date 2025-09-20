cmake_minimum_required(VERSION 3.15)
project(ownerdrw LANGUAGES CXX)

if(WIN32)
  file(GLOB SRC_FILES *.cpp *.h *.rc ${CMAKE_SOURCE_DIR}/*.xpm)
  add_executable(ownerdrw WIN32 ${SRC_FILES})
  target_link_libraries(ownerdrw PRIVATE ${wxWidgets_LIBRARIES})
endif()
