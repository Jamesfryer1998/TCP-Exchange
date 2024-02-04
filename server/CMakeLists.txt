add_subdirectory(data_handler)
add_subdirectory(network)
add_subdirectory(trading_engine)
add_subdirectory(user_management)

# CMakeLists.txt in app directory
file(GLOB SOURCES *.cpp)
add_executable(server-run ${SOURCES})

# Add the include directories
target_include_directories(server-run PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../shared/models)
target_include_directories(server-run PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../client/interface)
target_include_directories(server-run PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../server/network)
target_include_directories(server-run PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../client/network)

# Link the necessary libraries (if any)
target_link_libraries(server-run PRIVATE interface)
target_link_libraries(server-run PRIVATE util)
target_link_libraries(server-run PRIVATE user_management_server)
target_link_libraries(server-run PRIVATE models)
target_link_libraries(server-run PRIVATE network_server)
target_link_libraries(server-run PRIVATE network_client)