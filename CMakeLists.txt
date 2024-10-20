cmake_minimum_required(VERSION 3.24)
project(spiral)

# Find SDL2
find_package(SDL2 REQUIRED)

# Include SDL2 and SDL2_image headers
include_directories(${SDL2_INCLUDE_DIRS})

# Add executable target
add_executable(${PROJECT_NAME} main.cpp game.cpp spiral_animation.cpp)

# Link SDL2 and SDL2_image libraries
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})

# Compiler flags
target_compile_options(${PROJECT_NAME} PRIVATE -Wall)
