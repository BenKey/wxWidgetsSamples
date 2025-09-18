cmake_minimum_required(VERSION 3.10)
project(about LANGUAGES CXX)

if(WIN32)
  file(GLOB SRC_FILES *.cpp *.h ${CMAKE_SOURCE_DIR}/*.rc  ${CMAKE_SOURCE_DIR}/*.xpm)
else()
  file(GLOB SRC_FILES *.cpp *.h ${CMAKE_SOURCE_DIR}/*.xpm)
endif()
if(WIN32)
  add_executable(about WIN32 ${SRC_FILES})
else()
  add_executable(about ${SRC_FILES})
endif()
target_link_libraries(about PRIVATE ${wxWidgets_LIBRARIES})
add_custom_command(
  TARGET about POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory 
  ${CMAKE_CURRENT_SOURCE_DIR}/data
  ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/data)
