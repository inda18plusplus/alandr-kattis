cmake_minimum_required(VERSION 3.10)
project(alandr-kattis)

set(CMAKE_CXX_STANDARD 17)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/out)

set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g")

add_subdirectory(gamerank)
add_subdirectory(addingwords)
add_subdirectory(imperfectgps)
add_subdirectory(quantum)
add_subdirectory(trainsorting)
add_subdirectory(entertainmentbox)
add_subdirectory(bond)
add_subdirectory(minimumscalar)
add_subdirectory(orders)
add_subdirectory(guessthedatastructure)
add_subdirectory(fenwick)
add_subdirectory(kotid)
add_subdirectory(almostunionfind)
add_subdirectory(shortestpath1)