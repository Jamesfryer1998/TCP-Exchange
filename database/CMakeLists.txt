file(GLOB SOURCES *.cpp)
add_library(database ${SOURCES})
target_include_directories(database PUBLIC ..)