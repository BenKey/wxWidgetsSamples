cmake_minimum_required(VERSION 3.15)
project(bombs LANGUAGES CXX)

if(WIN32)
  file(GLOB SRC_FILES *.cpp *.h *.ico *.rc *.xpm)
else()
  file(GLOB SRC_FILES *.cpp *.h *.ico *.xpm)
endif()
if(WIN32)
  add_executable(bombs WIN32 ${SRC_FILES})
else()
  add_executable(bombs ${SRC_FILES})
endif()
target_link_libraries(bombs PRIVATE ${wxWidgets_LIBRARIES})
add_custom_command(
  TARGET bombs POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_CURRENT_SOURCE_DIR}/bombs.ico
  $<TARGET_FILE_DIR:bombs>/bombs.ico)
add_custom_command(
  TARGET bombs POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_CURRENT_SOURCE_DIR}/bombs.xpm
  $<TARGET_FILE_DIR:bombs>/bombs.xpm)
