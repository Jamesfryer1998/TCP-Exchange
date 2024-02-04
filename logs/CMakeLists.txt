file(GLOB SOURCES *.cpp)
add_library(logs ${SOURCES})
target_include_directories(logs PUBLIC ..)