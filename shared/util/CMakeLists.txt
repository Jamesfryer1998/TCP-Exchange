file(GLOB SOURCES *.cpp)
add_library(util ${SOURCES})
target_include_directories(util PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
        ${PROJECT_SOURCE_DIR}/client/interface)

target_include_directories(util PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../shared/models)
target_include_directories(util PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../client/interface)