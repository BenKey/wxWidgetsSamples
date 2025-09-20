cmake_minimum_required(VERSION 3.15)
project(stctest LANGUAGES CXX)

if(wxWidgets_stc_FOUND)
  if(WIN32)
    file(GLOB SRC_FILES *.cpp *.h ${CMAKE_SOURCE_DIR}/*.rc  ${CMAKE_SOURCE_DIR}/*.xpm)
  else()
    file(GLOB SRC_FILES *.cpp *.h ${CMAKE_SOURCE_DIR}/*.xpm)
  endif()
  if(WIN32)
    add_executable(stctest WIN32 ${SRC_FILES})
  else()
    add_executable(stctest ${SRC_FILES})
  endif()
  target_link_libraries(stctest PRIVATE ${wxWidgets_LIBRARIES})
  add_custom_command(
    TARGET stctest POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    ${CMAKE_CURRENT_SOURCE_DIR}/stctest.cpp
    $<TARGET_FILE_DIR:stctest>/stctest.cpp)
endif()
