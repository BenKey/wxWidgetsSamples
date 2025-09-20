cmake_minimum_required(VERSION 3.15)
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
  $<TARGET_FILE_DIR:splash>/press.mpg)
add_custom_command(
  TARGET splash POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_CURRENT_SOURCE_DIR}/press.pov
  $<TARGET_FILE_DIR:splash>/press.pov)
add_custom_command(
  TARGET splash POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_CURRENT_SOURCE_DIR}/splash.png
  $<TARGET_FILE_DIR:splash>/splash.png)
add_custom_command(
  TARGET splash POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_CURRENT_SOURCE_DIR}/splash.pov
  $<TARGET_FILE_DIR:splash>/splash.pov)
