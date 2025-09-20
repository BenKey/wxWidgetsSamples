cmake_minimum_required(VERSION 3.15)
project(griddemo LANGUAGES CXX)

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
add_custom_command(
  TARGET ${PROJECT_NAME} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_CURRENT_SOURCE_DIR}/bitmap1.bmp
  $<TARGET_FILE_DIR:griddemo>/bitmap1.bmp)
add_custom_command(
  TARGET ${PROJECT_NAME} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_CURRENT_SOURCE_DIR}/bitmap2.bmp
  $<TARGET_FILE_DIR:griddemo>/bitmap2.bmp)
