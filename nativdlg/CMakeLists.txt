cmake_minimum_required(VERSION 3.15)
project(nativdlg LANGUAGES CXX)

if(WIN32)
  file(GLOB SRC_FILES *.cpp *.h nativdlg.rc ${CMAKE_SOURCE_DIR}/*.xpm)
  add_executable(nativdlg WIN32 ${SRC_FILES})
  target_link_libraries(nativdlg PRIVATE ${wxWidgets_LIBRARIES})
endif()
