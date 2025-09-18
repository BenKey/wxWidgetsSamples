cmake_minimum_required(VERSION 3.10)
project(forty LANGUAGES CXX)

if(WIN32)
  file(GLOB SRC_FILES *.cpp *.h *.ani *.gif *.rc  *.xpm)
else()
  file(GLOB SRC_FILES *.cpp *.h *.ani *.gif *.xpm)
endif()
if(WIN32)
  add_executable(forty WIN32 ${SRC_FILES})
else()
  add_executable(forty ${SRC_FILES})
endif()
target_link_libraries(forty PRIVATE ${wxWidgets_LIBRARIES})
add_custom_command(
  TARGET forty POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_CURRENT_SOURCE_DIR}/about.htm
  ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/about.htm)
