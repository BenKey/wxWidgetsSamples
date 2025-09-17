cmake_minimum_required(VERSION 3.10)
project(sound LANGUAGES CXX)

if(WIN32)
    file(GLOB SRC_FILES *.cpp *.h ${CMAKE_SOURCE_DIR}/*.rc  ${CMAKE_SOURCE_DIR}/*.xpm)
else()
    file(GLOB SRC_FILES *.cpp *.h ${CMAKE_SOURCE_DIR}/*.xpm)
endif()
if(WIN32)
    add_executable(sound WIN32 ${SRC_FILES})
else()
    add_executable(sound ${SRC_FILES})
endif()
target_link_libraries(sound PRIVATE ${wxWidgets_LIBRARIES})
add_custom_command(
    TARGET sound POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    ${CMAKE_CURRENT_SOURCE_DIR}/9000g.wav
    ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/9000g.wav)
add_custom_command(
    TARGET sound POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    ${CMAKE_CURRENT_SOURCE_DIR}/cuckoo.wav
    ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/cuckoo.wav)
add_custom_command(
    TARGET sound POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    ${CMAKE_CURRENT_SOURCE_DIR}/doggrowl.wav
    ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/doggrowl.wav)
add_custom_command(
    TARGET sound POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    ${CMAKE_CURRENT_SOURCE_DIR}/tinkalink2.wav
    ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/tinkalink2.wav)
