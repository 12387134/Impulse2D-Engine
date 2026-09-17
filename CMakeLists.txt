cmake_minimum_required(VERSION 3.20)

project(Impulse2D)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SDL3 REQUIRED CONFIG)

add_executable(Impulse2D
    src/main.cpp
    src/RigidBody.cpp
    src/Game.cpp
)

target_link_libraries(Impulse2D PRIVATE SDL3::SDL3)
target_include_directories(Impulse2D PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
