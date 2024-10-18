cmake_minimum_required(VERSION 3.24)
project(spiral)

# Specify paths
# set(SDL2_IMAGE_INCLUDE_DIR "/opt/homebrew/Cellar/include/SDL2")
# set(SDL2_IMAGE_LIBRARIES "/opt/homebrew/lib/libSDL2_image.dylib")

# Find SDL2
find_package(SDL2 REQUIRED)

# Include SDL2 and SDL2_image headers
include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIR})

# Add executable target
add_executable(${PROJECT_NAME} main.cpp game.cpp map.cpp)

# Link SDL2 and SDL2_image libraries
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})

# Compiler flags
target_compile_options(${PROJECT_NAME} PRIVATE -Wall)