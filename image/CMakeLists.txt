cmake_minimum_required(VERSION 3.10)
project(image LANGUAGES CXX)

if(WIN32)
    file(GLOB SRC_FILES *.cpp *.h *.rc ${CMAKE_SOURCE_DIR}/*.xpm)
else()
    file(GLOB SRC_FILES *.cpp *.h ${CMAKE_SOURCE_DIR}/*.xpm)
endif()
if(WIN32)
    add_executable(image WIN32 ${SRC_FILES})
else()
    add_executable(image ${SRC_FILES})
endif()
target_link_libraries(image PRIVATE ${wxWidgets_LIBRARIES})
add_custom_command(
    TARGET image POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    ${CMAKE_CURRENT_SOURCE_DIR}/cmyk.jpg
    ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/cmyk.jpg)
add_custom_command(
    TARGET image POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    ${CMAKE_CURRENT_SOURCE_DIR}/cursor.png
    ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/cursor.png)
add_custom_command(
    TARGET image POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    ${CMAKE_CURRENT_SOURCE_DIR}/cursor_2x.png
    ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/cursor_2x.png)
add_custom_command(
    TARGET image POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    ${CMAKE_CURRENT_SOURCE_DIR}/horse.bmp
    ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/horse.bmp)
add_custom_command(
    TARGET image POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    ${CMAKE_CURRENT_SOURCE_DIR}/horse.cur
    ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/horse.cur)
add_custom_command(
    TARGET image POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    ${CMAKE_CURRENT_SOURCE_DIR}/horse.gif
    ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/horse.gif)
add_custom_command(
    TARGET image POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    ${CMAKE_CURRENT_SOURCE_DIR}/horse.ico
    ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/horse.ico)
add_custom_command(
    TARGET image POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    ${CMAKE_CURRENT_SOURCE_DIR}/horse.jpg
    ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/horse.jpg)
add_custom_command(
    TARGET image POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    ${CMAKE_CURRENT_SOURCE_DIR}/horse.pcx
    ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/horse.pcx)
add_custom_command(
    TARGET image POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    ${CMAKE_CURRENT_SOURCE_DIR}/horse.png
    ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/horse.png)
add_custom_command(
    TARGET image POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    ${CMAKE_CURRENT_SOURCE_DIR}/horse.pnm
    ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/horse.pnm)
add_custom_command(
    TARGET image POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    ${CMAKE_CURRENT_SOURCE_DIR}/horse.svg
    ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/horse.svg)
add_custom_command(
    TARGET image POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    ${CMAKE_CURRENT_SOURCE_DIR}/horse.tga
    ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/horse.tga)
add_custom_command(
    TARGET image POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    ${CMAKE_CURRENT_SOURCE_DIR}/horse.tif
    ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/horse.tif)
add_custom_command(
    TARGET image POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    ${CMAKE_CURRENT_SOURCE_DIR}/horse.webp
    ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/horse.webp)
add_custom_command(
    TARGET image POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    ${CMAKE_CURRENT_SOURCE_DIR}/horse.xpm
    ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/horse.xpm)
add_custom_command(
    TARGET image POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    ${CMAKE_CURRENT_SOURCE_DIR}/horse_ag.pnm
    ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/horse_ag.pnm)
add_custom_command(
    TARGET image POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    ${CMAKE_CURRENT_SOURCE_DIR}/horse_rg.pnm
    ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/horse_rg.pnm)
add_custom_command(
    TARGET image POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    ${CMAKE_CURRENT_SOURCE_DIR}/horse3.ani
    ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/horse3.ani)
add_custom_command(
    TARGET image POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    ${CMAKE_CURRENT_SOURCE_DIR}/smile.xbm
    ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/smile.xbm)
add_custom_command(
    TARGET image POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    ${CMAKE_CURRENT_SOURCE_DIR}/smile.xpm
    ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/smile.xpm)
add_custom_command(
    TARGET image POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    ${CMAKE_CURRENT_SOURCE_DIR}/toucan.png
    ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/toucan.png)
