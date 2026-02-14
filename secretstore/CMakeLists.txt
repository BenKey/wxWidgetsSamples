cmake_minimum_required(VERSION 3.25.0)
project(secretstore LANGUAGES CXX)

if(WIN32)
  file(GLOB SOURCE_FILES *.cpp *.h ${CMAKE_SOURCE_DIR}/*.rc ${CMAKE_SOURCE_DIR}/*.xpm)
  add_executable(${PROJECT_NAME} ${SOURCE_FILES})
  target_link_libraries(${PROJECT_NAME} PRIVATE ${wxWidgets_LIBRARIES})
endif()
