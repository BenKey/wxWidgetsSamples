cmake_minimum_required(VERSION 3.25.0)
project(taskbar LANGUAGES CXX)

file(GLOB RC_FILES ${CMAKE_SOURCE_DIR}/*.rc)
file(GLOB SOURCE_FILES *.cpp *.h *.xpm ${CMAKE_SOURCE_DIR}/*.xpm)
if(WIN32)
  list(APPEND SOURCE_FILES ${RC_FILES})
endif()
add_executable(${PROJECT_NAME} WIN32 ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} PRIVATE ${wxWidgets_LIBRARIES})

add_custom_command(
  TARGET ${PROJECT_NAME} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_CURRENT_SOURCE_DIR}/info.svg
  $<TARGET_FILE_DIR:taskbar>/info.svg)
