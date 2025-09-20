cmake_minimum_required(VERSION 3.15)
project(wxWidgetsBook-fontctrl LANGUAGES CXX)

file(GLOB SRC_FILES *.cpp *.h *.xpm)
add_library(${PROJECT_NAME} ${SRC_FILES})
