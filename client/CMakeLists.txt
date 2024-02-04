add_subdirectory(interface)
add_subdirectory(market_data)
add_subdirectory(network)

# CMakeLists.txt in app directory
file(GLOB SOURCES *.cpp)
add_executable(client-run ${SOURCES})

# Add the include directories
target_include_directories(client-run PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../shared/models)
target_include_directories(client-run PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../client/interface)
target_include_directories(client-run PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../server/network)
target_include_directories(client-run PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../client/network)

# Link the necessary libraries (if any)
target_link_libraries(client-run PRIVATE interface)
target_link_libraries(client-run PRIVATE util)
target_link_libraries(client-run PRIVATE user_management_server)
target_link_libraries(client-run PRIVATE models)
target_link_libraries(client-run PRIVATE network_server)
target_link_libraries(client-run PRIVATE network_client)