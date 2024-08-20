cmake_minimum_required(VERSION 3.10)
project(config_parser VERSION 1.0 LANGUAGES CXX)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Option to enable logging
option(ENABLE_LOGGING "Enable logging feature" OFF)

# Add include directories
include_directories(${CMAKE_SOURCE_DIR}/include)

# Add the subdirectory for the library
add_subdirectory(lib)

# Create the executable with source files
add_executable(config_parser src/main.cpp src/parser.cpp)

# Link the utils library to the executable
target_link_libraries(config_parser PRIVATE utils)

# Link fmt library
find_package(fmt REQUIRED)
target_link_libraries(config_parser PRIVATE fmt::fmt)

# Add compile options
target_compile_options(config_parser PRIVATE -Wall -Wextra -Wpedantic)

# Add link options
target_link_options(config_parser PRIVATE -Wl,--as-needed)

# Conditional logging
if (ENABLE_LOGGING)
    target_compile_definitions(config_parser PRIVATE ENABLE_LOGGING)
endif()
