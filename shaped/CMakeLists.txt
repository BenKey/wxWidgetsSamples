cmake_minimum_required(VERSION 3.15)
project(shaped LANGUAGES CXX)

if(WIN32)
  file(GLOB SRC_FILES *.cpp *.h ${CMAKE_SOURCE_DIR}/*.rc  ${CMAKE_SOURCE_DIR}/*.xpm)
else()
  file(GLOB SRC_FILES *.cpp *.h ${CMAKE_SOURCE_DIR}/*.xpm)
endif()
if(WIN32)
  add_executable(shaped WIN32 ${SRC_FILES})
else()
  add_executable(shaped ${SRC_FILES})
endif()
target_link_libraries(shaped PRIVATE ${wxWidgets_LIBRARIES})
add_custom_command(
  TARGET shaped POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_CURRENT_SOURCE_DIR}/star.png
  $<TARGET_FILE_DIR:shaped>/star.png)
