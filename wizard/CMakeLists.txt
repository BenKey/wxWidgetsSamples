cmake_minimum_required(VERSION 3.10)
project(wizard LANGUAGES CXX)

if(WIN32)
  file(GLOB SRC_FILES *.cpp *.h ${CMAKE_SOURCE_DIR}/*.rc  ${CMAKE_SOURCE_DIR}/*.xpm)
else()
  file(GLOB SRC_FILES *.cpp *.h ${CMAKE_SOURCE_DIR}/*.xpm)
endif()
if(WIN32)
  add_executable(wizard WIN32 ${SRC_FILES})
else()
  add_executable(wizard ${SRC_FILES})
endif()
target_link_libraries(wizard PRIVATE ${wxWidgets_LIBRARIES})
add_custom_command(
  TARGET wizard POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_CURRENT_SOURCE_DIR}/wiztest.svg
  ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/wiztest.svg)
add_custom_command(
  TARGET wizard POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_CURRENT_SOURCE_DIR}/wiztest2.svg
  ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/wiztest2.svg)
