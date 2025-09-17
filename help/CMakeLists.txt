cmake_minimum_required(VERSION 3.10)
project(helpdemo LANGUAGES CXX)

if(WIN32)
    file(GLOB SRC_FILES *.cpp *.h ${CMAKE_SOURCE_DIR}/*.rc  ${CMAKE_SOURCE_DIR}/*.xpm)
else()
    file(GLOB SRC_FILES *.cpp *.h ${CMAKE_SOURCE_DIR}/*.xpm)
endif()
if(WIN32)
    add_executable(helpdemo WIN32 ${SRC_FILES})
else()
    add_executable(helpdemo ${SRC_FILES})
endif()
target_link_libraries(helpdemo PRIVATE ${wxWidgets_LIBRARIES})
add_custom_command(
    TARGET helpdemo POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    ${CMAKE_CURRENT_SOURCE_DIR}/doc.hlp
    ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/doc.hlp)
add_custom_command(
    TARGET helpdemo POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    ${CMAKE_CURRENT_SOURCE_DIR}/doc.chm
    ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/doc.chm)
add_custom_command(
    TARGET helpdemo POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    ${CMAKE_CURRENT_SOURCE_DIR}/doc.zip
    ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/doc.zip)
