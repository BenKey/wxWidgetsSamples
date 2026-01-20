cmake_minimum_required(VERSION 3.25.0)
project(arttest LANGUAGES CXX)

file(GLOB RC_FILES ${CMAKE_SOURCE_DIR}/*.rc)
file(GLOB SRC_FILES *.cpp *.h *.xpm ${CMAKE_SOURCE_DIR}/*.xpm)
if(WIN32)
  list(APPEND SRC_FILES ${RC_FILES})
endif()
add_executable(${PROJECT_NAME} WIN32 ${SRC_FILES})

target_link_libraries(${PROJECT_NAME} PRIVATE ${wxWidgets_LIBRARIES})
add_custom_command(
  TARGET ${PROJECT_NAME} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_CURRENT_SOURCE_DIR}/error.xpm
  $<TARGET_FILE_DIR:arttest>/error.xpm)
add_custom_command(
  TARGET ${PROJECT_NAME} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_CURRENT_SOURCE_DIR}/info.xpm
  $<TARGET_FILE_DIR:arttest>/info.xpm)
add_custom_command(
  TARGET ${PROJECT_NAME} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_CURRENT_SOURCE_DIR}/null.xpm
  $<TARGET_FILE_DIR:arttest>/null.xpm)
add_custom_command(
  TARGET ${PROJECT_NAME} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_CURRENT_SOURCE_DIR}/question.xpm
  $<TARGET_FILE_DIR:arttest>/question.xpm)
add_custom_command(
  TARGET ${PROJECT_NAME} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_CURRENT_SOURCE_DIR}/warning.xpm
  $<TARGET_FILE_DIR:arttest>/warning.xpm)
