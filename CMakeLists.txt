cmake_minimum_required(VERSION 3.5)
project(oiltank)

# Define the source file for your library
set(OILTANK_SOURCE oiltank.cpp)

# Create a shared library (or static if preferred)
add_library(oiltank SHARED ${OILTANK_SOURCE})

# Specify include directories for users of the library
target_include_directories(oiltank PUBLIC .)

# Optionally, install the library and header file
install(TARGETS oiltank DESTINATION lib)
install(FILES oiltank.hpp DESTINATION include)

# Optionally, set additional properties for the library
# You can find more options in the CMake documentation

### Examples:

# Set version information
set_target_properties(oiltank PROPERTIES VERSION 1.0.0)

# Link against external libraries
# target_link_libraries(oiltank ...)

# Add an executable target for program.cpp
add_executable(test_console test_console.cpp)

# Link the executable to the liboiltank shared library
target_link_libraries(test_console oiltank)