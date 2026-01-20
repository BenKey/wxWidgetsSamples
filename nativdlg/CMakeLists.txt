cmake_minimum_required(VERSION 3.25.0)
project(nativdlg LANGUAGES CXX)

if(WIN32)
  file(GLOB SRC_FILES *.cpp *.h nativdlg.rc ${CMAKE_SOURCE_DIR}/*.xpm)
  add_executable(${PROJECT_NAME} WIN32 ${SRC_FILES})
  target_link_libraries(${PROJECT_NAME} PRIVATE ${wxWidgets_LIBRARIES})
endif()
