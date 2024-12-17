cmake_minimum_required(VERSION 3.24)

project(animation)

find_package(SDL2 CONFIG REQUIRED)
find_package(SDL2_image CONFIG REQUIRED)

# Add executable target
add_executable(${PROJECT_NAME} main.cpp game.cpp animations/lightning_animation.cpp animations/sin_animation.cpp animations/spiral_animation.cpp game_object.cpp texture_manager.cpp map.cpp)

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

