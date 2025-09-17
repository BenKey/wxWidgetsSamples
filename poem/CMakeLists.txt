cmake_minimum_required(VERSION 3.10)
project(poem LANGUAGES CXX)

if(WIN32)
    file(GLOB SRC_FILES *.cpp *.h *.rc ${CMAKE_SOURCE_DIR}/*.xpm)
else()
    file(GLOB SRC_FILES *.cpp *.h ${CMAKE_SOURCE_DIR}/*.xpm)
endif()
if(WIN32)
    add_executable(poem WIN32 ${SRC_FILES})
else()
    add_executable(poem ${SRC_FILES})
endif()
target_link_libraries(poem PRIVATE ${wxWidgets_LIBRARIES})
add_custom_command(
    TARGET poem POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    ${CMAKE_CURRENT_SOURCE_DIR}/wxpoem.dat
    ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/wxpoem.dat)
add_custom_command(
    TARGET poem POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    ${CMAKE_CURRENT_SOURCE_DIR}/wxpoem.idx
    ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/wxpoem.idx)
add_custom_command(
    TARGET poem POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    ${CMAKE_CURRENT_SOURCE_DIR}/wxpoem.txt
    ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/wxpoem.txt)
