cmake_minimum_required(VERSION 3.20)

project(Impulse2D)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Impulse2D
    src/main.cpp
    src/RigidBody.cpp
)