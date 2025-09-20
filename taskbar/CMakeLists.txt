cmake_minimum_required(VERSION 3.15)
project(taskbar LANGUAGES CXX)

if(WIN32)
  file(GLOB SRC_FILES *.cpp *.h ${CMAKE_SOURCE_DIR}/*.rc  ${CMAKE_SOURCE_DIR}/*.xpm)
else()
  file(GLOB SRC_FILES *.cpp *.h ${CMAKE_SOURCE_DIR}/*.xpm)
endif()
if(WIN32)
  add_executable(taskbar WIN32 ${SRC_FILES})
else()
  add_executable(taskbar ${SRC_FILES})
endif()
target_link_libraries(taskbar PRIVATE ${wxWidgets_LIBRARIES})
add_custom_command(
  TARGET taskbar POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_CURRENT_SOURCE_DIR}/info.svg
  $<TARGET_FILE_DIR:taskbar>/info.svg)
