cmake_minimum_required(VERSION 3.15)
project(wxWidgetsBook-launch LANGUAGES CXX)

file(GLOB SRC_FILES *.cpp *.h)
add_library(${PROJECT_NAME} ${SRC_FILES})
