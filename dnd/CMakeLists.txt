cmake_minimum_required(VERSION 3.10)
project(dnd LANGUAGES CXX)

if(WIN32)
  file(GLOB SRC_FILES *.cpp *.h *.ani *.gif *.rc  ${CMAKE_SOURCE_DIR}/*.xpm)
else()
  file(GLOB SRC_FILES *.cpp *.h *.ani *.gif ${CMAKE_SOURCE_DIR}/*.xpm)
endif()
if(WIN32)
  add_executable(dnd WIN32 ${SRC_FILES})
else()
  add_executable(dnd ${SRC_FILES})
endif()
target_link_libraries(dnd PRIVATE ${wxWidgets_LIBRARIES})
add_custom_command(
  TARGET dnd POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_CURRENT_SOURCE_DIR}/d_and_d.txt
  ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/d_and_d.txt)
add_custom_command(
  TARGET dnd POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_CURRENT_SOURCE_DIR}/dnd_copy.cur
  ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/dnd_copy.cur)
add_custom_command(
  TARGET dnd POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_CURRENT_SOURCE_DIR}/dnd_copy.xpm
  ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/dnd_copy.xpm)
add_custom_command(
  TARGET dnd POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_CURRENT_SOURCE_DIR}/dnd_move.cur
  ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/dnd_move.cur)
add_custom_command(
  TARGET dnd POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_CURRENT_SOURCE_DIR}/dnd_move.xpm
  ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/dnd_move.xpm)
add_custom_command(
  TARGET dnd POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_CURRENT_SOURCE_DIR}/dnd_none.cur
  ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/dnd_none.cur)
add_custom_command(
  TARGET dnd POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_CURRENT_SOURCE_DIR}/dnd_none.xpm
  ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/dnd_none.xpm)
add_custom_command(
  TARGET dnd POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_CURRENT_SOURCE_DIR}/wxwin.png
  ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/wxwin.png)
