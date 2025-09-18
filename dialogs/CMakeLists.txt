cmake_minimum_required(VERSION 3.10)
project(dialogs LANGUAGES CXX)

if(WIN32)
  file(GLOB SRC_FILES *.cpp *.h ${CMAKE_SOURCE_DIR}/*.rc  ${CMAKE_SOURCE_DIR}/*.xpm)
else()
  file(GLOB SRC_FILES *.cpp *.h ${CMAKE_SOURCE_DIR}/*.xpm)
endif()
if(WIN32)
  add_executable(dialogs WIN32 ${SRC_FILES})
else()
  add_executable(dialogs ${SRC_FILES})
endif()
target_link_libraries(dialogs PRIVATE ${wxWidgets_LIBRARIES})
add_custom_command(
  TARGET dialogs POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_CURRENT_SOURCE_DIR}/tip.xpm
  ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/tip.xpm)
add_custom_command(
  TARGET dialogs POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_CURRENT_SOURCE_DIR}/tips.txt
  ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/tips.txt)
