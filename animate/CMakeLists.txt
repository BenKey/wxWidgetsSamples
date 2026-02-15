cmake_minimum_required(VERSION 3.25.0)
project(anitest LANGUAGES CXX)
include(GNUInstallDirs)

file(GLOB RC_FILES ${CMAKE_SOURCE_DIR}/*.rc)
file(GLOB SOURCE_FILES *.cpp *.h *.ani *.gif ${CMAKE_SOURCE_DIR}/*.xpm)
if(WIN32)
  list(APPEND SOURCE_FILES ${RC_FILES})
endif()
add_executable(${PROJECT_NAME} WIN32 ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} PRIVATE ${wxWidgets_LIBRARIES})

set(TARGET_DIR "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
add_custom_command(
  TARGET ${PROJECT_NAME} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
    ${CMAKE_CURRENT_SOURCE_DIR}/hourglass.ani
    ${TARGET_DIR}/hourglass.ani
  COMMAND ${CMAKE_COMMAND} -E copy
    ${CMAKE_CURRENT_SOURCE_DIR}/throbber.gif
    ${TARGET_DIR}/throbber.gif
  COMMAND ${CMAKE_COMMAND} -E copy
    ${CMAKE_CURRENT_SOURCE_DIR}/throbber_2x.gif
    ${TARGET_DIR}/throbber_2x.gif
	COMMENT "Copy assets to the target directory.")

install(TARGETS ${PROJECT_NAME} DESTINATION ${CMAKE_INSTALL_BINDIR})
install(
  FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/hourglass.ani
    ${CMAKE_CURRENT_SOURCE_DIR}/throbber.gif
    ${CMAKE_CURRENT_SOURCE_DIR}/throbber_2x.gif
  DESTINATION ${CMAKE_INSTALL_BINDIR})
get_filename_component(GPP_DIR ${CMAKE_CXX_COMPILER} DIRECTORY)
install(CODE "
    set(GPP_DIR [[${GPP_DIR}]])
    set(TARGET_FILE [[$<TARGET_FILE:${PROJECT_NAME}>]])
    include([[${CMAKE_SOURCE_DIR}/cmake/include/install_dependencies.cmake]])
")
