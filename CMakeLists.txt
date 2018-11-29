cmake_minimum_required(VERSION 3.10)
project(alandr-kattis)

set(CMAKE_CXX_STANDARD 17)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/out)

add_subdirectory(gamerank)
add_subdirectory(addingwords)
add_subdirectory(imperfectgps)
add_subdirectory(quantum)