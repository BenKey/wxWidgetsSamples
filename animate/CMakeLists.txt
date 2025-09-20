cmake_minimum_required(VERSION 3.15)
project(anitest LANGUAGES CXX)

if(WIN32)
  file(GLOB SRC_FILES *.cpp *.h *.ani *.gif ${CMAKE_SOURCE_DIR}/*.rc  ${CMAKE_SOURCE_DIR}/*.xpm)
else()
  file(GLOB SRC_FILES *.cpp *.h *.ani *.gif ${CMAKE_SOURCE_DIR}/*.xpm)
endif()
if(WIN32)
  add_executable(anitest WIN32 ${SRC_FILES})
else()
  add_executable(anitest ${SRC_FILES})
endif()
target_link_libraries(anitest PRIVATE ${wxWidgets_LIBRARIES})
add_custom_command(
  TARGET anitest POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_CURRENT_SOURCE_DIR}/hourglass.ani
  $<TARGET_FILE_DIR:anitest>/hourglass.ani)
add_custom_command(
  TARGET anitest POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_CURRENT_SOURCE_DIR}/throbber.gif
  $<TARGET_FILE_DIR:anitest>/throbber.gif)
add_custom_command(
  TARGET anitest POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_CURRENT_SOURCE_DIR}/throbber_2x.gif
  $<TARGET_FILE_DIR:anitest>/throbber_2x.gif)
