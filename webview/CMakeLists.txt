cmake_minimum_required(VERSION 3.15)
project(webview LANGUAGES CXX)

if(wxWidgets_webview_FOUND)
  if(WIN32)
    file(GLOB SRC_FILES webview.cpp *.h ${CMAKE_SOURCE_DIR}/*.rc  ${CMAKE_SOURCE_DIR}/*.xpm)
  else()
    file(GLOB SRC_FILES webview.cpp *.h ${CMAKE_SOURCE_DIR}/*.xpm)
  endif()
  if(WIN32)
    add_executable(webview WIN32 ${SRC_FILES})
  else()
    add_executable(webview ${SRC_FILES})
  endif()
  target_link_libraries(webview PRIVATE ${wxWidgets_LIBRARIES})
  add_custom_command(
    TARGET webview POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    ${CMAKE_CURRENT_SOURCE_DIR}/handler_advanced.html
    $<TARGET_FILE_DIR:webview>/handler_advanced.html)
endif()
