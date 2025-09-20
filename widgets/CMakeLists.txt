cmake_minimum_required(VERSION 3.15)
project(widgets LANGUAGES CXX)

if(WIN32)
  file(GLOB SRC_FILES *.cpp *.h ${CMAKE_SOURCE_DIR}/*.rc ${CMAKE_SOURCE_DIR}/*.xpm)
else()
  file(GLOB SRC_FILES *.cpp *.h ${CMAKE_SOURCE_DIR}/*.xpm)
endif()
if(WIN32)
  add_executable(${PROJECT_NAME} WIN32 ${SRC_FILES})
else()
  add_executable(${PROJECT_NAME} ${SRC_FILES})
endif()
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
