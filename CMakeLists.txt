cmake_minimum_required(VERSION 3.1)

# Install gtest which now lives on head.
cmake_policy(SET CMP0135 NEW)
include(FetchContent)
FetchContent_Declare(
  googletest
  # Specify the commit you depend on and update it regularly.
  URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
  FIND_PACKAGE_ARGS NAMES GTest
)
FetchContent_MakeAvailable(googletest)

# Setup CMAKE Module path for other conda packages
SET(CMAKE_MODULE_PATH $ENV{$CONDA_PREFIX}/lib/cmake)
if(DEFINED ENV{CONDA_PREFIX} AND NOT DEFINED ENV{CONDA_BUILD})
  message("Setting CMAKE_FIND_ROOT_PATH")
  set(CMAKE_FIND_ROOT_PATH $ENV{CONDA_PREFIX})
endif()

project(exchange)
set(CMAKE_CXX_FLAGS "-Wall -Werror -Wextra -Wunused-parameter")
set(CMAKE_CXX_STANDARD 23)

enable_testing()

add_subdirectory(app)
add_subdirectory(client)
add_subdirectory(database)
add_subdirectory(logs)
add_subdirectory(server)
add_subdirectory(shared)
