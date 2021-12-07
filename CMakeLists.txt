cmake_minimum_required(VERSION 3.0)

project(SDL_QOI
  LANGUAGES C
  DESCRIPTION "QOI image decoding for SDL2"
  HOMEPAGE_URL "https://github.com/superzazu/SDL_QOI")

find_package(SDL2 REQUIRED)

add_library(SDL_QOI STATIC SDL_QOI.c)
target_include_directories(SDL_QOI PRIVATE ${SDL2_INCLUDE_DIRS} .)
target_link_libraries(SDL_QOI PRIVATE ${SDL2_LIBRARIES})
set_target_properties(SDL_QOI PROPERTIES C_STANDARD 99)
if (MSVC)
  target_compile_options(SDL_QOI PRIVATE /W4)
else()
  target_compile_options(SDL_QOI PRIVATE -Wall -Wextra -pedantic)
endif()

# example executable
add_executable(SDL_QOI-example example.c)
target_include_directories(SDL_QOI-example PRIVATE ${SDL2_INCLUDE_DIRS} .)
target_link_libraries(SDL_QOI-example PRIVATE ${SDL2_LIBRARIES} SDL_QOI)
set_target_properties(SDL_QOI-example PROPERTIES C_STANDARD 99)
