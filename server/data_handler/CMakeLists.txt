file(GLOB SOURCES *.cpp)
add_library(data_handler_server ${SOURCES})
target_include_directories(data_handler_server PUBLIC ..)