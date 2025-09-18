cmake_minimum_required(VERSION 3.10)
project(splash LANGUAGES CXX)

if(WIN32)
  file(GLOB SRC_FILES *.cpp *.h *.ani *.gif ${CMAKE_SOURCE_DIR}/*.rc  ${CMAKE_SOURCE_DIR}/*.xpm)
else()
  file(GLOB SRC_FILES *.cpp *.h *.ani *.gif ${CMAKE_SOURCE_DIR}/*.xpm)
endif()
if(WIN32)
  add_executable(splash WIN32 ${SRC_FILES})
else()
  add_executable(splash ${SRC_FILES})
endif()
target_link_libraries(splash PRIVATE ${wxWidgets_LIBRARIES})
add_custom_command(
  TARGET splash POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_CURRENT_SOURCE_DIR}/press.mpg
  ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/press.mpg)
add_custom_command(
  TARGET splash POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_CURRENT_SOURCE_DIR}/press.pov
  ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/press.pov)
add_custom_command(
  TARGET splash POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_CURRENT_SOURCE_DIR}/splash.png
  ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/splash.png)
add_custom_command(
  TARGET splash POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_CURRENT_SOURCE_DIR}/splash.pov
  ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/splash.pov)
