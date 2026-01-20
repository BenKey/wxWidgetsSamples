cmake_minimum_required(VERSION 3.25.0)
project(wxWidgetsBook-flag LANGUAGES CXX)

file(GLOB RC_FILES *.rc)
file(GLOB SRC_FILES *.cpp *.h *.xpm)
if(WIN32)
  list(APPEND SRC_FILES ${RC_FILES})
endif()
add_executable(${PROJECT_NAME} WIN32 ${SRC_FILES})
target_link_libraries(${PROJECT_NAME} PRIVATE ${wxWidgets_LIBRARIES})

add_custom_command(
  TARGET ${PROJECT_NAME} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_CURRENT_SOURCE_DIR}/flag.png
  $<TARGET_FILE_DIR:wxWidgetsBook-flag>/flag.png)
add_custom_command(
  TARGET ${PROJECT_NAME} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory 
  ${CMAKE_CURRENT_SOURCE_DIR}/de
  $<TARGET_FILE_DIR:wxWidgetsBook-flag>/de)
add_custom_command(
  TARGET ${PROJECT_NAME} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory 
  ${CMAKE_CURRENT_SOURCE_DIR}/fr
  $<TARGET_FILE_DIR:wxWidgetsBook-flag>/fr)
