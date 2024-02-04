file(GLOB SOURCES *.cpp)
add_library(trading_engine_server ${SOURCES})
target_include_directories(trading_engine_server PUBLIC ..)