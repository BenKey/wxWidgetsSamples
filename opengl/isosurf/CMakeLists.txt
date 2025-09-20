cmake_minimum_required(VERSION 3.15)
project(isosurf LANGUAGES CXX)

if(WIN32)
  file(GLOB SRC_FILES *.cpp *.h ${CMAKE_SOURCE_DIR}/*.rc  ${CMAKE_SOURCE_DIR}/*.xpm)
else()
  file(GLOB SRC_FILES *.cpp *.h ${CMAKE_SOURCE_DIR}/*.xpm)
endif()
if(WIN32)
  add_executable(isosurf WIN32 ${SRC_FILES})
else()
  add_executable(isosurf ${SRC_FILES})
endif()
target_link_libraries(isosurf PRIVATE ${wxWidgets_LIBRARIES})
add_custom_command(
  TARGET isosurf POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_CURRENT_SOURCE_DIR}/isosurf.dat.gz
  $<TARGET_FILE_DIR:isosurf>/isosurf.dat.gz)
