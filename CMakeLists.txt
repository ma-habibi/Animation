cmake_minimum_required(VERSION 3.24)

project(animation)

set(CMAKE_CXX_STANDARD 20)

find_package(SDL2 CONFIG REQUIRED)
find_package(SDL2_image CONFIG REQUIRED)
find_package(sdl2-gfx CONFIG REQUIRED)
find_package(argparse CONFIG REQUIRED)

# Add executable target
add_executable(${PROJECT_NAME} main.cpp game.cpp animations/lightning_animation.cpp animations/sin_animation.cpp animations/spiral_animation.cpp animations/road_animation.cpp)

# Compiler flags
target_compile_options(${PROJECT_NAME} PRIVATE -Wall)

target_link_libraries(animation
    PRIVATE
    $<TARGET_NAME_IF_EXISTS:SDL2::SDL2main>
    $<IF:$<TARGET_EXISTS:SDL2::SDL2>,SDL2::SDL2,SDL2::SDL2-static>
)

target_link_libraries(animation
  PRIVATE
  $<IF:$<TARGET_EXISTS:SDL2_image::SDL2_image>,SDL2_image::SDL2_image,SDL2_image::SDL2_image-static>)

target_link_libraries(animation
        PRIVATE
        argparse::argparse
)

target_link_libraries(animation PRIVATE SDL2::SDL2_gfx)
