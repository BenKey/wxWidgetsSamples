cmake_minimum_required(VERSION 3.15)
project(image LANGUAGES CXX)

if(WIN32)
  file(GLOB SRC_FILES *.cpp *.h *.rc ${CMAKE_SOURCE_DIR}/*.xpm)
else()
  file(GLOB SRC_FILES *.cpp *.h ${CMAKE_SOURCE_DIR}/*.xpm)
endif()
if(WIN32)
  add_executable(image WIN32 ${SRC_FILES})
else()
  add_executable(image ${SRC_FILES})
endif()
target_link_libraries(image PRIVATE ${wxWidgets_LIBRARIES})
add_custom_command(
  TARGET image POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_CURRENT_SOURCE_DIR}/cmyk.jpg
  $<TARGET_FILE_DIR:image>/cmyk.jpg)
add_custom_command(
  TARGET image POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_CURRENT_SOURCE_DIR}/cursor.png
  $<TARGET_FILE_DIR:image>/cursor.png)
add_custom_command(
  TARGET image POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_CURRENT_SOURCE_DIR}/cursor_2x.png
  $<TARGET_FILE_DIR:image>/cursor_2x.png)
add_custom_command(
  TARGET image POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_CURRENT_SOURCE_DIR}/horse.bmp
  $<TARGET_FILE_DIR:image>/horse.bmp)
add_custom_command(
  TARGET image POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_CURRENT_SOURCE_DIR}/horse.cur
  $<TARGET_FILE_DIR:image>/horse.cur)
add_custom_command(
  TARGET image POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_CURRENT_SOURCE_DIR}/horse.gif
  $<TARGET_FILE_DIR:image>/horse.gif)
add_custom_command(
  TARGET image POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_CURRENT_SOURCE_DIR}/horse.ico
  $<TARGET_FILE_DIR:image>/horse.ico)
add_custom_command(
  TARGET image POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_CURRENT_SOURCE_DIR}/horse.jpg
  $<TARGET_FILE_DIR:image>/horse.jpg)
add_custom_command(
  TARGET image POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_CURRENT_SOURCE_DIR}/horse.pcx
  $<TARGET_FILE_DIR:image>/horse.pcx)
add_custom_command(
  TARGET image POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_CURRENT_SOURCE_DIR}/horse.png
  $<TARGET_FILE_DIR:image>/horse.png)
add_custom_command(
  TARGET image POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_CURRENT_SOURCE_DIR}/horse.pnm
  $<TARGET_FILE_DIR:image>/horse.pnm)
add_custom_command(
  TARGET image POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_CURRENT_SOURCE_DIR}/horse.svg
  $<TARGET_FILE_DIR:image>/horse.svg)
add_custom_command(
  TARGET image POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_CURRENT_SOURCE_DIR}/horse.tga
  $<TARGET_FILE_DIR:image>/horse.tga)
add_custom_command(
  TARGET image POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_CURRENT_SOURCE_DIR}/horse.tif
  $<TARGET_FILE_DIR:image>/horse.tif)
add_custom_command(
  TARGET image POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_CURRENT_SOURCE_DIR}/horse.webp
  $<TARGET_FILE_DIR:image>/horse.webp)
add_custom_command(
  TARGET image POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_CURRENT_SOURCE_DIR}/horse.xpm
  $<TARGET_FILE_DIR:image>/horse.xpm)
add_custom_command(
  TARGET image POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_CURRENT_SOURCE_DIR}/horse_ag.pnm
  $<TARGET_FILE_DIR:image>/horse_ag.pnm)
add_custom_command(
  TARGET image POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_CURRENT_SOURCE_DIR}/horse_rg.pnm
  $<TARGET_FILE_DIR:image>/horse_rg.pnm)
add_custom_command(
  TARGET image POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_CURRENT_SOURCE_DIR}/horse3.ani
  $<TARGET_FILE_DIR:image>/horse3.ani)
add_custom_command(
  TARGET image POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_CURRENT_SOURCE_DIR}/smile.xbm
  $<TARGET_FILE_DIR:image>/smile.xbm)
add_custom_command(
  TARGET image POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_CURRENT_SOURCE_DIR}/smile.xpm
  $<TARGET_FILE_DIR:image>/smile.xpm)
add_custom_command(
  TARGET image POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_CURRENT_SOURCE_DIR}/toucan.png
  $<TARGET_FILE_DIR:image>/toucan.png)
