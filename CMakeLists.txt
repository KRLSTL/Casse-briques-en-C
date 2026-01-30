cmake_minimum_required(VERSION 4.0)
project(HelloSDL2025 C)

set(CMAKE_C_STANDARD 23)

set(SDL2_PATH "C:\\Users\\Karl\\Desktop\\ENIGMA\\1st year\\C\\SDL2-devel-2.32.8-mingw\\SDL2-2.32.8\\x86_64-w64-mingw32")
set(SDL2_IMAGE_PATH "C:\\Users\\Karl\\Desktop\\ENIGMA\\1st year\\C\\SDL2_image-devel-2.8.6-mingw\\SDL2_image-2.8.6\\x86_64-w64-mingw32")
set(SDL2_TTF_PATH "C:\\Users\\Karl\\Desktop\\ENIGMA\\1st year\\C\\SDL2_ttf-devel-2.24.0-mingw\\SDL2_ttf-2.24.0\\x86_64-w64-mingw32")
find_package(SDL2 REQUIRED)
find_package(SDL2_ttf REQUIRED)

include_directories(${SDL2_INCLUDE_DIR})
include_directories(${SDL2_TTF_INCLUDE_DIR})

add_executable(HelloSDL2025 main.c
        ball.c
        ball.h
        text.c
        text.h
        pong.c
        pong.h
        brick.c
        brick.h)

target_link_libraries(HelloSDL2025 ${SDL2_LIBRARY} ${SDL2_TTF_LIBRARIES})