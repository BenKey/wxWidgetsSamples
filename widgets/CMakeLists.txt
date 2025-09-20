cmake_minimum_required(VERSION 3.15)
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
if(USE_GTK)
  message(STATUS "Configuring the 'widgets' target to use GTK.")
  target_include_directories(widgets PRIVATE ${GTK_INCLUDE_DIRS})  
  target_link_directories(widgets PRIVATE ${GTK_LIBRARY_DIRS})
  target_link_libraries(widgets PRIVATE ${GTK_LIBRARIES})
endif()  
add_custom_command(
  TARGET widgets POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory 
  ${CMAKE_CURRENT_SOURCE_DIR}/icons
  $<TARGET_FILE_DIR:widgets>/icons)
