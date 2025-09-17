cmake_minimum_required(VERSION 3.10)
project(internat LANGUAGES CXX)

if(WIN32)
  file(GLOB SRC_FILES *.cpp *.h ${CMAKE_SOURCE_DIR}/*.rc  ${CMAKE_SOURCE_DIR}/*.xpm)
else()
  file(GLOB SRC_FILES *.cpp *.h ${CMAKE_SOURCE_DIR}/*.xpm)
endif()
if(WIN32)
  add_executable(internat WIN32 ${SRC_FILES})
else()
  add_executable(internat ${SRC_FILES})
endif()
target_link_libraries(internat PRIVATE ${wxWidgets_LIBRARIES})
add_custom_command(
  TARGET internat POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory 
  ${CMAKE_CURRENT_SOURCE_DIR}/ar
  ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/ar)
add_custom_command(
  TARGET internat POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory 
  ${CMAKE_CURRENT_SOURCE_DIR}/bg
  ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/bg)
add_custom_command(
  TARGET internat POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory 
  ${CMAKE_CURRENT_SOURCE_DIR}/cs
  ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/cs)
add_custom_command(
  TARGET internat POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory 
  ${CMAKE_CURRENT_SOURCE_DIR}/de
  ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/de)
add_custom_command(
  TARGET internat POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory 
  ${CMAKE_CURRENT_SOURCE_DIR}/fr
  ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/fr)
add_custom_command(
  TARGET internat POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory 
  ${CMAKE_CURRENT_SOURCE_DIR}/it
  ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/it)
add_custom_command(
  TARGET internat POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory 
  ${CMAKE_CURRENT_SOURCE_DIR}/ja
  ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/ja)
add_custom_command(
  TARGET internat POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory 
  ${CMAKE_CURRENT_SOURCE_DIR}/ja_JP.EUC-JP
  ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/ja_JP.EUC-JP)
add_custom_command(
  TARGET internat POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory 
  ${CMAKE_CURRENT_SOURCE_DIR}/ka
  ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/ka)
add_custom_command(
  TARGET internat POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory 
  ${CMAKE_CURRENT_SOURCE_DIR}/pl
  ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/pl)
add_custom_command(
  TARGET internat POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory 
  ${CMAKE_CURRENT_SOURCE_DIR}/ru
  ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/ru)
add_custom_command(
  TARGET internat POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory 
  ${CMAKE_CURRENT_SOURCE_DIR}/sv
  ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/sv)
