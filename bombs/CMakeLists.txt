cmake_minimum_required(VERSION 3.25.0)
project(bombs LANGUAGES CXX)

file(GLOB RC_FILES *.rc)
file(GLOB SRC_FILES *.cpp *.h *.ico *.xpm)
if(WIN32)
  list(APPEND SRC_FILES ${RC_FILES})
endif()
add_executable(${PROJECT_NAME} WIN32 ${SRC_FILES})
target_link_libraries(${PROJECT_NAME} PRIVATE ${wxWidgets_LIBRARIES})

add_custom_command(
  TARGET ${PROJECT_NAME} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_CURRENT_SOURCE_DIR}/bombs.ico
  $<TARGET_FILE_DIR:bombs>/bombs.ico)
add_custom_command(
  TARGET ${PROJECT_NAME} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_CURRENT_SOURCE_DIR}/bombs.xpm
  $<TARGET_FILE_DIR:bombs>/bombs.xpm)
