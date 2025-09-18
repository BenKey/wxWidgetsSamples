cmake_minimum_required(VERSION 3.10)
project(combo LANGUAGES CXX)

if(WIN32)
  file(GLOB SRC_FILES *.cpp *.h ${CMAKE_SOURCE_DIR}/*.rc  ${CMAKE_SOURCE_DIR}/*.xpm)
else()
  file(GLOB SRC_FILES *.cpp *.h ${CMAKE_SOURCE_DIR}/*.xpm)
endif()
if(WIN32)
  add_executable(combo WIN32 ${SRC_FILES})
else()
  add_executable(combo ${SRC_FILES})
endif()
target_link_libraries(combo PRIVATE ${wxWidgets_LIBRARIES})
add_custom_command(
  TARGET combo POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_CURRENT_SOURCE_DIR}/dropbuth.svg
  ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/dropbuth.svg)
add_custom_command(
  TARGET combo POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_CURRENT_SOURCE_DIR}/dropbutn.svg
  ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/dropbutn.svg)
add_custom_command(
  TARGET combo POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_CURRENT_SOURCE_DIR}/dropbutp.svg
  ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/dropbutp.svg)
add_custom_command(
  TARGET combo POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_CURRENT_SOURCE_DIR}/three-dots.svg
  ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/three-dots.svg)
