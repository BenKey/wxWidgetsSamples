cmake_minimum_required(VERSION 3.15)
project(console LANGUAGES CXX)

file(GLOB SRC_FILES *.cpp *.h)
add_executable(console ${SRC_FILES})
target_link_libraries(console PRIVATE ${wxWidgets_LIBRARIES})
