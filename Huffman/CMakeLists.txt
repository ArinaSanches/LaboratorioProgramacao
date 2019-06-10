cmake_minimum_required(VERSION 3.13)
project(Huffman)

set(CMAKE_CXX_STANDARD 14)

add_executable(Huffman main.cpp Heap.cpp Heap.h)