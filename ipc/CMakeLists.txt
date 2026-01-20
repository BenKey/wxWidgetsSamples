cmake_minimum_required(VERSION 3.25.0)
project(ipc LANGUAGES CXX)

file(GLOB BASEIPCCLIENT_SRC_FILES baseclient.cpp baseclient.h ipcsetup.h ${CMAKE_SOURCE_DIR}/*.xpm)
add_executable(baseipcclient ${BASEIPCCLIENT_SRC_FILES})
target_link_libraries(baseipcclient PRIVATE ${wxWidgets_LIBRARIES})

file(GLOB BASEIPCSERVER_SRC_FILES baseserver.cpp baseserver.h ipcsetup.h ${CMAKE_SOURCE_DIR}/*.xpm)
add_executable(baseipcserver ${BASEIPCSERVER_SRC_FILES})
target_link_libraries(baseipcserver PRIVATE ${wxWidgets_LIBRARIES})

file(GLOB RC_FILES ${CMAKE_SOURCE_DIR}/*.rc)

file(GLOB IPCCLIENT_SRC_FILES client.cpp client.h ipcsetup.h ${CMAKE_SOURCE_DIR}/*.xpm)
if(WIN32)
  list(APPEND IPCCLIENT_SRC_FILES ${RC_FILES})
endif()
add_executable(ipcclient WIN32 ${IPCCLIENT_SRC_FILES})
target_link_libraries(ipcclient PRIVATE ${wxWidgets_LIBRARIES})

file(GLOB IPCSERVER_SRC_FILES server.cpp server.h ipcsetup.h ${CMAKE_SOURCE_DIR}/*.xpm)
if(WIN32)
  list(APPEND IPCSERVER_SRC_FILES ${RC_FILES})
endif()

add_executable(ipcserver WIN32 ${IPCSERVER_SRC_FILES})
target_link_libraries(ipcserver PRIVATE ${wxWidgets_LIBRARIES})
