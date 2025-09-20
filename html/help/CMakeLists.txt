cmake_minimum_required(VERSION 3.15)
project(helpfilesdemo LANGUAGES CXX)

if(WIN32)
  file(GLOB SRC_FILES *.cpp *.h ${CMAKE_SOURCE_DIR}/*.rc ${CMAKE_SOURCE_DIR}/*.xpm)
else()
  file(GLOB SRC_FILES *.cpp *.h ${CMAKE_SOURCE_DIR}/*.xpm)
endif()
if(WIN32)
  add_executable(helpfilesdemo WIN32 ${SRC_FILES})
else()
  add_executable(helpfilesdemo ${SRC_FILES})
endif()
target_link_libraries(helpfilesdemo PRIVATE ${wxWidgets_LIBRARIES})
add_custom_command(
  TARGET helpfilesdemo POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory 
  ${CMAKE_CURRENT_SOURCE_DIR}/helpfiles
  $<TARGET_FILE_DIR:helpfilesdemo>/helpfiles)
