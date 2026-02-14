cmake_minimum_required(VERSION 3.25.0)
project(internat LANGUAGES CXX)

file(GLOB RC_FILES ${CMAKE_SOURCE_DIR}/*.rc)
file(GLOB SOURCE_FILES *.cpp *.h ${CMAKE_SOURCE_DIR}/*.xpm)
if(WIN32)
  list(APPEND SOURCE_FILES ${RC_FILES})
endif()
add_executable(${PROJECT_NAME} WIN32 ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} PRIVATE ${wxWidgets_LIBRARIES})

add_custom_command(
  TARGET ${PROJECT_NAME} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory 
  ${CMAKE_CURRENT_SOURCE_DIR}/ar
  $<TARGET_FILE_DIR:internat>/ar)
add_custom_command(
  TARGET ${PROJECT_NAME} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory 
  ${CMAKE_CURRENT_SOURCE_DIR}/bg
  $<TARGET_FILE_DIR:internat>/bg)
add_custom_command(
  TARGET ${PROJECT_NAME} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory 
  ${CMAKE_CURRENT_SOURCE_DIR}/cs
  $<TARGET_FILE_DIR:internat>/cs)
add_custom_command(
  TARGET ${PROJECT_NAME} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory 
  ${CMAKE_CURRENT_SOURCE_DIR}/de
  $<TARGET_FILE_DIR:internat>/de)
add_custom_command(
  TARGET ${PROJECT_NAME} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory 
  ${CMAKE_CURRENT_SOURCE_DIR}/fr
  $<TARGET_FILE_DIR:internat>/fr)
add_custom_command(
  TARGET ${PROJECT_NAME} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory 
  ${CMAKE_CURRENT_SOURCE_DIR}/it
  $<TARGET_FILE_DIR:internat>/it)
add_custom_command(
  TARGET ${PROJECT_NAME} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory 
  ${CMAKE_CURRENT_SOURCE_DIR}/ja
  $<TARGET_FILE_DIR:internat>/ja)
add_custom_command(
  TARGET ${PROJECT_NAME} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory 
  ${CMAKE_CURRENT_SOURCE_DIR}/ja_JP.EUC-JP
  $<TARGET_FILE_DIR:internat>/ja_JP.EUC-JP)
add_custom_command(
  TARGET ${PROJECT_NAME} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory 
  ${CMAKE_CURRENT_SOURCE_DIR}/ka
  $<TARGET_FILE_DIR:internat>/ka)
add_custom_command(
  TARGET ${PROJECT_NAME} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory 
  ${CMAKE_CURRENT_SOURCE_DIR}/pl
  $<TARGET_FILE_DIR:internat>/pl)
add_custom_command(
  TARGET ${PROJECT_NAME} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory 
  ${CMAKE_CURRENT_SOURCE_DIR}/ru
  $<TARGET_FILE_DIR:internat>/ru)
add_custom_command(
  TARGET ${PROJECT_NAME} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory 
  ${CMAKE_CURRENT_SOURCE_DIR}/sv
  $<TARGET_FILE_DIR:internat>/sv)
