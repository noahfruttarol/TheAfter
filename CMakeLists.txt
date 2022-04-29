cmake_minimum_required(VERSION 3.21)
project(TheAfter)

set(CMAKE_CXX_STANDARD 20)

add_executable(TheAfter main.cpp game_state.hpp game_state.cpp item.hpp item.cpp room.hpp room.cpp player.hpp player.cpp enemy.hpp enemy.cpp)
