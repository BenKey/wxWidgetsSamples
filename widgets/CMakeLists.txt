cmake_minimum_required(VERSION 3.25.0)
project(widgets LANGUAGES CXX)

file(GLOB RC_FILES ${CMAKE_SOURCE_DIR}/*.rc)
file(GLOB SOURCE_FILES *.cpp *.h icons/*.xpm ${CMAKE_SOURCE_DIR}/*.xpm)
if(WIN32)
  list(APPEND SOURCE_FILES ${RC_FILES})
endif()
add_executable(${PROJECT_NAME} WIN32 ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} PRIVATE ${wxWidgets_LIBRARIES})
if(USE_GTK)
  message(STATUS "Configuring the 'widgets' target to use GTK.")
  target_include_directories(${PROJECT_NAME} PRIVATE ${GTK_INCLUDE_DIRS})  
  target_link_directories(${PROJECT_NAME} PRIVATE ${GTK_LIBRARY_DIRS})
  target_link_libraries(${PROJECT_NAME} PRIVATE ${GTK_LIBRARIES})
endif()  

add_custom_command(
  TARGET ${PROJECT_NAME} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory 
  ${CMAKE_CURRENT_SOURCE_DIR}/icons
  $<TARGET_FILE_DIR:widgets>/icons)
