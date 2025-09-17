cmake_minimum_required(VERSION 3.10)
project(font LANGUAGES CXX)

if(WIN32)
    file(GLOB SRC_FILES *.cpp *.h ${CMAKE_SOURCE_DIR}/*.rc  ${CMAKE_SOURCE_DIR}/*.xpm)
else()
    file(GLOB SRC_FILES *.cpp *.h ${CMAKE_SOURCE_DIR}/*.xpm)
endif()
if(WIN32)
    add_executable(font WIN32 ${SRC_FILES})
else()
    add_executable(font ${SRC_FILES})
endif()
target_link_libraries(font PRIVATE ${wxWidgets_LIBRARIES})
add_custom_command(
    TARGET font POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    ${CMAKE_CURRENT_SOURCE_DIR}/wxprivate.ttf
    ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/wxprivate.ttf)
