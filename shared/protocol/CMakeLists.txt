file(GLOB SOURCES *.cpp)
add_library(protocol ${SOURCES})
target_include_directories(protocol PUBLIC ..)

