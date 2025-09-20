cmake_minimum_required(VERSION 3.15)
project(dragimag LANGUAGES CXX)

if(WIN32)
  file(GLOB SRC_FILES *.cpp *.h *.rc  *.xpm)
else()
  file(GLOB SRC_FILES *.cpp *.h *.xpm)
endif()
if(WIN32)
  add_executable(${PROJECT_NAME} WIN32 ${SRC_FILES})
else()
  add_executable(${PROJECT_NAME} ${SRC_FILES})
endif()
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
