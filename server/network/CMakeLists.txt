file(GLOB SOURCES *.cpp)
add_library(network_server ${SOURCES})
target_include_directories(network_server PUBLIC ..)