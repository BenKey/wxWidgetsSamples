cmake_minimum_required(VERSION 3.25.0)
project(fractal LANGUAGES CXX)
include(GNUInstallDirs)

file(GLOB RC_FILES *.rc)
file(GLOB SOURCE_FILES *.cpp *.h ${CMAKE_SOURCE_DIR}/*.xpm)
if(WIN32)
  list(APPEND SOURCE_FILES ${RC_FILES})
endif()
add_executable(${PROJECT_NAME} WIN32 ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} PRIVATE ${wxWidgets_LIBRARIES})
install(TARGETS ${PROJECT_NAME} DESTINATION ${CMAKE_INSTALL_BINDIR})

get_filename_component(GPP_DIR ${CMAKE_CXX_COMPILER} DIRECTORY)
install(CODE "
    set(GPP_DIR [[${GPP_DIR}]])
    set(TARGET_FILE [[$<TARGET_FILE:${PROJECT_NAME}>]])
    include([[${CMAKE_SOURCE_DIR}/cmake/include/install_dependencies.cmake]])
")
