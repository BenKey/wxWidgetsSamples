cmake_minimum_required(VERSION 3.10)
project(dragimag LANGUAGES CXX)

if(WIN32)
    file(GLOB SRC_FILES *.cpp *.h *.rc  *.xpm)
else()
    file(GLOB SRC_FILES *.cpp *.h *.xpm)
endif()
if(WIN32)
    add_executable(dragimag WIN32 ${SRC_FILES})
else()
    add_executable(dragimag ${SRC_FILES})
endif()
target_link_libraries(dragimag PRIVATE ${wxWidgets_LIBRARIES})
add_custom_command(
    TARGET dragimag POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    ${CMAKE_CURRENT_SOURCE_DIR}/backgrnd.png
    ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/backgrnd.png)
add_custom_command(
    TARGET dragimag POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    ${CMAKE_CURRENT_SOURCE_DIR}/dragicon.ico
    ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/dragicon.ico)
add_custom_command(
    TARGET dragimag POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    ${CMAKE_CURRENT_SOURCE_DIR}/dragicon.xpm
    ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/dragicon.xpm)
add_custom_command(
    TARGET dragimag POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    ${CMAKE_CURRENT_SOURCE_DIR}/shape01.png
    ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/shape01.png)
add_custom_command(
    TARGET dragimag POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    ${CMAKE_CURRENT_SOURCE_DIR}/shape02.png
    ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/shape02.png)
add_custom_command(
    TARGET dragimag POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    ${CMAKE_CURRENT_SOURCE_DIR}/shape03.png
    ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/shape03.png)
