file(GLOB SOURCES *.cpp)
add_library(market_data_client ${SOURCES})
target_include_directories(market_data_client PUBLIC ..)