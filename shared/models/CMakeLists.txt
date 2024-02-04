file(GLOB SOURCES *.cpp)
add_library(models ${SOURCES})

target_include_directories(models PUBLIC ..)
target_include_directories(models PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(models PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../util)