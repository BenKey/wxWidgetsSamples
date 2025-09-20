cmake_minimum_required(VERSION 3.15)
project(arttest LANGUAGES CXX)

if(WIN32)
  file(GLOB SRC_FILES *.cpp *.h *.xpm ${CMAKE_SOURCE_DIR}/*.rc  ${CMAKE_SOURCE_DIR}/*.xpm)
else()
  file(GLOB SRC_FILES *.cpp *.h *.xpm ${CMAKE_SOURCE_DIR}/*.xpm)
endif()
if(WIN32)
  add_executable(arttest WIN32 ${SRC_FILES})
else()
  add_executable(arttest ${SRC_FILES})
endif()
target_link_libraries(arttest PRIVATE ${wxWidgets_LIBRARIES})
add_custom_command(
  TARGET arttest POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_CURRENT_SOURCE_DIR}/error.xpm
  $<TARGET_FILE_DIR:arttest>/error.xpm)
add_custom_command(
  TARGET arttest POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_CURRENT_SOURCE_DIR}/info.xpm
  $<TARGET_FILE_DIR:arttest>/info.xpm)
add_custom_command(
  TARGET arttest POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_CURRENT_SOURCE_DIR}/null.xpm
  $<TARGET_FILE_DIR:arttest>/null.xpm)
add_custom_command(
  TARGET arttest POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_CURRENT_SOURCE_DIR}/question.xpm
  $<TARGET_FILE_DIR:arttest>/question.xpm)
add_custom_command(
  TARGET arttest POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_CURRENT_SOURCE_DIR}/warning.xpm
  $<TARGET_FILE_DIR:arttest>/warning.xpm)
