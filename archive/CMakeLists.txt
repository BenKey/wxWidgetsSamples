cmake_minimum_required(VERSION 3.10)
project(archive LANGUAGES CXX)

file(GLOB SRC_FILES *.cpp *.h)
add_executable(archive ${SRC_FILES})
target_link_libraries(archive PRIVATE ${wxWidgets_LIBRARIES})

