cmake_minimum_required(VERSION 3.25.0)
project(forty LANGUAGES CXX)

file(GLOB RC_FILES *.rc)
file(GLOB SRC_FILES *.cpp *.h *.ani *.gif *.xpm)
if(WIN32)
  list(APPEND SRC_FILES ${RC_FILES})
endif()
add_executable(${PROJECT_NAME} WIN32 ${SRC_FILES})
target_link_libraries(${PROJECT_NAME} PRIVATE ${wxWidgets_LIBRARIES})

add_custom_command(
  TARGET ${PROJECT_NAME} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_CURRENT_SOURCE_DIR}/about.htm
  $<TARGET_FILE_DIR:forty>/about.htm)
