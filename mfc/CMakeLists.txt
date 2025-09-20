cmake_minimum_required(VERSION 3.15)
project(mfctest LANGUAGES CXX)

if(MSVC AND WIN32)
  file(GLOB SRC_FILES *.cpp *.h *.rc ${CMAKE_SOURCE_DIR}/*.xpm)
  add_executable(${PROJECT_NAME} WIN32 ${SRC_FILES})
  target_link_libraries(${PROJECT_NAME} PRIVATE ${wxWidgets_LIBRARIES})
endif()  
