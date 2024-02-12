file(GLOB SOURCES *.cpp)
add_library(interface ${SOURCES})
target_include_directories(interface PUBLIC ..)

target_include_directories(interface PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../shared/models)
target_include_directories(interface PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../shared/util)
target_include_directories(interface PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../server/user_management)
target_include_directories(interface PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../server/trading_engine)
target_include_directories(interface PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../client/network)