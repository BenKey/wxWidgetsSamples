cmake_minimum_required(VERSION 3.15)
project(forty LANGUAGES CXX)

if(WIN32)
  file(GLOB SRC_FILES *.cpp *.h *.ani *.gif *.rc *.xpm)
else()
  file(GLOB SRC_FILES *.cpp *.h *.ani *.gif *.xpm)
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
  ${CMAKE_CURRENT_SOURCE_DIR}/about.htm
  $<TARGET_FILE_DIR:forty>/about.htm)
