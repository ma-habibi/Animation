cmake_minimum_required(VERSION 3.24)
project(animation)

# Find SDL2
find_package(SDL2 REQUIRED)

# Manually find SDLIMAGE
set(SDL2_IMAGE_INCLUDE_DIR "/opt/homebrew/include/SDL2")
set(SDL2_IMAGE_LIBRARIES "/opt/homebrew/lib/libSDL2_image.dylib")

# Include SDL2 and SDL2_image headers
include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIR})

# Add executable target
add_executable(${PROJECT_NAME} main.cpp game.cpp animations/spiral_animation.cpp game_object.cpp texture_manager.cpp map.cpp)

# Link SDL2 and SDL2_image libraries
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})

# Compiler flags
target_compile_options(${PROJECT_NAME} PRIVATE -Wall)
