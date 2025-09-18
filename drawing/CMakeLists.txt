cmake_minimum_required(VERSION 3.10)
project(drawing LANGUAGES CXX)

if(WIN32)
  file(GLOB SRC_FILES *.cpp *.h *.xpm ${CMAKE_SOURCE_DIR}/*.rc ${CMAKE_SOURCE_DIR}/*.xpm)
else()
  file(GLOB SRC_FILES *.cpp *.h *.xpm ${CMAKE_SOURCE_DIR}/*.xpm)
endif()
if(WIN32)
  add_executable(drawing WIN32 ${SRC_FILES})
else()
  add_executable(drawing ${SRC_FILES})
endif()
target_link_libraries(drawing PRIVATE ${wxWidgets_LIBRARIES})
add_custom_command(
  TARGET drawing POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_CURRENT_SOURCE_DIR}/cursor_2x.xpm
  ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/cursor_2x.xpm)
add_custom_command(
  TARGET drawing POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_CURRENT_SOURCE_DIR}/cursor.xpm
  ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/cursor.xpm)
add_custom_command(
  TARGET drawing POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_CURRENT_SOURCE_DIR}/image.bmp
  ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/image.bmp)
add_custom_command(
  TARGET drawing POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_CURRENT_SOURCE_DIR}/mask.bmp
  ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/mask.bmp)
add_custom_command(
  TARGET drawing POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_CURRENT_SOURCE_DIR}/pat4.bmp
  ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/pat4.bmp)
add_custom_command(
  TARGET drawing POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_CURRENT_SOURCE_DIR}/pat35.bmp
  ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/pat35.bmp)
add_custom_command(
  TARGET drawing POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_CURRENT_SOURCE_DIR}/pat36.bmp
  ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/pat36.bmp)
add_custom_command(
  TARGET drawing POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_CURRENT_SOURCE_DIR}/smile.xpm
  ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/smile.xpm)
