file(GLOB SOURCES *.cpp)
add_library(network_client ${SOURCES})
target_include_directories(network_client PUBLIC ..)