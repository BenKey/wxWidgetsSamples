cmake_minimum_required(VERSION 3.25.0)
project(ipc LANGUAGES CXX)

file(GLOB BASEIPCCLIENT_SOURCE_FILES baseclient.cpp baseclient.h ipcsetup.h ${CMAKE_SOURCE_DIR}/*.xpm)
add_executable(baseipcclient ${BASEIPCCLIENT_SOURCE_FILES})
target_link_libraries(baseipcclient PRIVATE ${wxWidgets_LIBRARIES})

file(GLOB BASEIPCSERVER_SOURCE_FILES baseserver.cpp baseserver.h ipcsetup.h ${CMAKE_SOURCE_DIR}/*.xpm)
add_executable(baseipcserver ${BASEIPCSERVER_SOURCE_FILES})
target_link_libraries(baseipcserver PRIVATE ${wxWidgets_LIBRARIES})

file(GLOB RC_FILES ${CMAKE_SOURCE_DIR}/*.rc)

file(GLOB IPCCLIENT_SOURCE_FILES client.cpp client.h ipcsetup.h ${CMAKE_SOURCE_DIR}/*.xpm)
if(WIN32)
  list(APPEND IPCCLIENT_SOURCE_FILES ${RC_FILES})
endif()
add_executable(ipcclient WIN32 ${IPCCLIENT_SOURCE_FILES})
target_link_libraries(ipcclient PRIVATE ${wxWidgets_LIBRARIES})

file(GLOB IPCSERVER_SOURCE_FILES server.cpp server.h ipcsetup.h ${CMAKE_SOURCE_DIR}/*.xpm)
if(WIN32)
  list(APPEND IPCSERVER_SOURCE_FILES ${RC_FILES})
endif()

add_executable(ipcserver WIN32 ${IPCSERVER_SOURCE_FILES})
target_link_libraries(ipcserver PRIVATE ${wxWidgets_LIBRARIES})
