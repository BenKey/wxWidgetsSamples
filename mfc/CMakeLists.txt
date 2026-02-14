cmake_minimum_required(VERSION 3.25.0)
project(mfctest LANGUAGES CXX)

if(MSVC AND WIN32)
  file(GLOB SOURCE_FILES *.cpp *.h *.rc ${CMAKE_SOURCE_DIR}/*.xpm)
  add_executable(${PROJECT_NAME} WIN32 ${SOURCE_FILES})
  target_link_libraries(${PROJECT_NAME} PRIVATE ${wxWidgets_LIBRARIES})
endif()  
