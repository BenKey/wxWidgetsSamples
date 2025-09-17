cmake_minimum_required(VERSION 3.10)
project(penguin LANGUAGES CXX C)

if(WIN32)
    file(GLOB SRC_FILES *.c *.cpp *.h ${CMAKE_SOURCE_DIR}/*.rc  ${CMAKE_SOURCE_DIR}/*.xpm)
else()
    file(GLOB SRC_FILES *.c *.cpp *.h ${CMAKE_SOURCE_DIR}/*.xpm)
endif()
if(WIN32)
    add_executable(penguin WIN32 ${SRC_FILES})
else()
    add_executable(penguin ${SRC_FILES})
endif()
target_link_libraries(penguin PRIVATE ${wxWidgets_LIBRARIES})
add_custom_command(
    TARGET penguin POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    ${CMAKE_CURRENT_SOURCE_DIR}/penguin.dxf.gz
    ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/penguin.dxf.gz)
