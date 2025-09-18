cmake_minimum_required(VERSION 3.10)
project(widgets LANGUAGES CXX)

if(WIN32)
  file(GLOB SRC_FILES *.cpp *.h ${CMAKE_SOURCE_DIR}/*.rc  ${CMAKE_SOURCE_DIR}/*.xpm)
else()
  file(GLOB SRC_FILES *.cpp *.h ${CMAKE_SOURCE_DIR}/*.xpm)
endif()
if(WIN32)
  add_executable(widgets WIN32 ${SRC_FILES})
else()
  add_executable(widgets ${SRC_FILES})
endif()
target_link_libraries(widgets PRIVATE ${wxWidgets_LIBRARIES})
if (GTK4_FOUND)
  message(STATUS "Adding GTK libraries for the target 'widgets'.")
  target_link_libraries(widgets PRIVATE ${GTK4_LIBRARIES})
endif()  
add_custom_command(
  TARGET widgets POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory 
  ${CMAKE_CURRENT_SOURCE_DIR}/icons
  ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/icons)
