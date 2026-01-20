cmake_minimum_required(VERSION 3.25.0)
project(sockets LANGUAGES CXX)

file(GLOB BASESOCKETSCLIENT_SRC_FILES baseclient.cpp baseclient.h ${CMAKE_SOURCE_DIR}/*.xpm)
add_executable(basesocketsclient ${BASESOCKETSCLIENT_SRC_FILES})
target_link_libraries(basesocketsclient PRIVATE ${wxWidgets_LIBRARIES})

file(GLOB BASESOCKETSSERVER_SRC_FILES baseserver.cpp baseserver.h ${CMAKE_SOURCE_DIR}/*.xpm)
add_executable(basesocketsserver ${BASESOCKETSSERVER_SRC_FILES})
target_link_libraries(basesocketsserver PRIVATE ${wxWidgets_LIBRARIES})

file(GLOB RC_FILES ${CMAKE_SOURCE_DIR}/*.rc)

file(GLOB SOCKETSCLIENT_SRC_FILES client.cpp client.h ${CMAKE_SOURCE_DIR}/*.xpm)
if(WIN32)
  list(APPEND SOCKETSCLIENT_SRC_FILES ${RC_FILES})
endif()
add_executable(socketsclient WIN32 ${SOCKETSCLIENT_SRC_FILES})
target_link_libraries(socketsclient PRIVATE ${wxWidgets_LIBRARIES})

file(GLOB SOCKETSSERVER_SRC_FILES server.cpp server.h ${CMAKE_SOURCE_DIR}/*.xpm)
if(WIN32)
  list(APPEND SOCKETSSERVER_SRC_FILES ${RC_FILES})
endif()
add_executable(socketsserver WIN32 ${SOCKETSSERVER_SRC_FILES})
target_link_libraries(socketsserver PRIVATE ${wxWidgets_LIBRARIES})
