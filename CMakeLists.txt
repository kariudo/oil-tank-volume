cmake_minimum_required(VERSION 3.5)
project(oiltank)

# Define the source file for your library
set(OILTANK_SOURCE components/oiltank/oiltank.cpp)

# Create a shared library (or static if preferred)
add_library(oiltank SHARED ${OILTANK_SOURCE})

# Specify include directories for users of the library
target_include_directories(oiltank PUBLIC . components/oiltank)

# Set version information
set_target_properties(oiltank PROPERTIES VERSION 1.0.0)

# Add an executable target for program.cpp
add_executable(test_console test_console.cpp)

# Link the executable to the liboiltank shared library
target_link_libraries(test_console oiltank)