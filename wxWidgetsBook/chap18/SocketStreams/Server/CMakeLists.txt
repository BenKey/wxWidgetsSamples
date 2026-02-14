cmake_minimum_required(VERSION 3.25.0)
project(wxWidgetsBook-SocketStreams-server LANGUAGES CXX)

cmake_path(GET CMAKE_CURRENT_SOURCE_DIR PARENT_PATH PARENT_DIR)

file(GLOB RC_FILES *.rc)
file(GLOB SOURCE_FILES *.cpp *.h *.xpm)
if(WIN32)
  list(APPEND SOURCE_FILES ${RC_FILES})
endif()
add_executable(${PROJECT_NAME} WIN32 ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} PRIVATE ${wxWidgets_LIBRARIES})

add_custom_command(
  TARGET ${PROJECT_NAME} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  ${PARENT_DIR}/ReadFrom.jpg
  $<TARGET_FILE_DIR:wxWidgetsBook-SocketStreams-server>/ReadFrom.jpg)
