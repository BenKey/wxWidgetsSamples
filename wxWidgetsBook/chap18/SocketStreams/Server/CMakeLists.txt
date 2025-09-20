cmake_minimum_required(VERSION 3.15)
project(wxWidgetsBook-SocketStreams-server LANGUAGES CXX)

cmake_path(GET CMAKE_CURRENT_SOURCE_DIR PARENT_PATH PARENT_DIR)

if(WIN32)
  file(GLOB SRC_FILES *.cpp *.h *.rc *.xpm)
else()
  file(GLOB SRC_FILES *.cpp *.h *.xpm)
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
  ${PARENT_DIR}/ReadFrom.jpg
  $<TARGET_FILE_DIR:wxWidgetsBook-SocketStreams-server>/ReadFrom.jpg)
