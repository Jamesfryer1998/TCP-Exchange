file(GLOB SOURCES *.cpp)
add_library(user_management_server ${SOURCES})
target_include_directories(user_management_server PUBLIC ..)

target_include_directories(user_management_server PRIVATE ../../shared)
target_include_directories(user_management_server PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../shared/models)
target_include_directories(user_management_server PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../client/interface)

