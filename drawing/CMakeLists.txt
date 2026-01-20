cmake_minimum_required(VERSION 3.25.0)
project(drawing LANGUAGES CXX)

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
  ${CMAKE_CURRENT_SOURCE_DIR}/cursor_2x.xpm
  $<TARGET_FILE_DIR:drawing>/cursor_2x.xpm)
add_custom_command(
  TARGET ${PROJECT_NAME} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_CURRENT_SOURCE_DIR}/cursor.xpm
  $<TARGET_FILE_DIR:drawing>/cursor.xpm)
add_custom_command(
  TARGET ${PROJECT_NAME} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_CURRENT_SOURCE_DIR}/image.bmp
  $<TARGET_FILE_DIR:drawing>/image.bmp)
add_custom_command(
  TARGET ${PROJECT_NAME} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_CURRENT_SOURCE_DIR}/mask.bmp
  $<TARGET_FILE_DIR:drawing>/mask.bmp)
add_custom_command(
  TARGET ${PROJECT_NAME} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_CURRENT_SOURCE_DIR}/pat4.bmp
  $<TARGET_FILE_DIR:drawing>/pat4.bmp)
add_custom_command(
  TARGET ${PROJECT_NAME} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_CURRENT_SOURCE_DIR}/pat35.bmp
  $<TARGET_FILE_DIR:drawing>/pat35.bmp)
add_custom_command(
  TARGET ${PROJECT_NAME} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_CURRENT_SOURCE_DIR}/pat36.bmp
  $<TARGET_FILE_DIR:drawing>/pat36.bmp)
add_custom_command(
  TARGET ${PROJECT_NAME} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_CURRENT_SOURCE_DIR}/smile.xpm
  $<TARGET_FILE_DIR:drawing>/smile.xpm)
