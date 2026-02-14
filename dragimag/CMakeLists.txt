cmake_minimum_required(VERSION 3.25.0)
project(dragimag LANGUAGES CXX)

file(GLOB RC_FILES *.rc)
file(GLOB SOURCE_FILES *.cpp *.h *.xpm)
if(WIN32)
  list(APPEND SOURCE_FILES ${RC_FILES})
endif()
add_executable(${PROJECT_NAME} WIN32 ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} PRIVATE ${wxWidgets_LIBRARIES})

add_custom_command(
  TARGET ${PROJECT_NAME} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_CURRENT_SOURCE_DIR}/backgrnd.png
  $<TARGET_FILE_DIR:dragimag>/backgrnd.png)
add_custom_command(
  TARGET ${PROJECT_NAME} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_CURRENT_SOURCE_DIR}/dragicon.ico
  $<TARGET_FILE_DIR:dragimag>/dragicon.ico)
add_custom_command(
  TARGET ${PROJECT_NAME} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_CURRENT_SOURCE_DIR}/dragicon.xpm
  $<TARGET_FILE_DIR:dragimag>/dragicon.xpm)
add_custom_command(
  TARGET ${PROJECT_NAME} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_CURRENT_SOURCE_DIR}/shape01.png
  $<TARGET_FILE_DIR:dragimag>/shape01.png)
add_custom_command(
  TARGET ${PROJECT_NAME} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_CURRENT_SOURCE_DIR}/shape02.png
  $<TARGET_FILE_DIR:dragimag>/shape02.png)
add_custom_command(
  TARGET ${PROJECT_NAME} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_CURRENT_SOURCE_DIR}/shape03.png
  $<TARGET_FILE_DIR:dragimag>/shape03.png)
