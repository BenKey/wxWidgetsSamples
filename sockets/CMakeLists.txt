cmake_minimum_required(VERSION 3.25.0)
project(sockets LANGUAGES CXX)

file(GLOB BASESOCKETSCLIENT_SOURCE_FILES baseclient.cpp baseclient.h ${CMAKE_SOURCE_DIR}/*.xpm)
add_executable(basesocketsclient ${BASESOCKETSCLIENT_SOURCE_FILES})
target_link_libraries(basesocketsclient PRIVATE ${wxWidgets_LIBRARIES})

file(GLOB BASESOCKETSSERVER_SOURCE_FILES baseserver.cpp baseserver.h ${CMAKE_SOURCE_DIR}/*.xpm)
add_executable(basesocketsserver ${BASESOCKETSSERVER_SOURCE_FILES})
target_link_libraries(basesocketsserver PRIVATE ${wxWidgets_LIBRARIES})

file(GLOB RC_FILES ${CMAKE_SOURCE_DIR}/*.rc)

file(GLOB SOCKETSCLIENT_SOURCE_FILES client.cpp client.h ${CMAKE_SOURCE_DIR}/*.xpm)
if(WIN32)
  list(APPEND SOCKETSCLIENT_SOURCE_FILES ${RC_FILES})
endif()
add_executable(socketsclient WIN32 ${SOCKETSCLIENT_SOURCE_FILES})
target_link_libraries(socketsclient PRIVATE ${wxWidgets_LIBRARIES})

file(GLOB SOCKETSSERVER_SOURCE_FILES server.cpp server.h ${CMAKE_SOURCE_DIR}/*.xpm)
if(WIN32)
  list(APPEND SOCKETSSERVER_SOURCE_FILES ${RC_FILES})
endif()
add_executable(socketsserver WIN32 ${SOCKETSSERVER_SOURCE_FILES})
target_link_libraries(socketsserver PRIVATE ${wxWidgets_LIBRARIES})
