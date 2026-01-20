cmake_minimum_required(VERSION 3.25.0)
project(archive LANGUAGES CXX)

file(GLOB SRC_FILES *.cpp *.h)
add_executable(${PROJECT_NAME} ${SRC_FILES})
target_link_libraries(${PROJECT_NAME} PRIVATE ${wxWidgets_LIBRARIES})

