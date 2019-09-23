cmake_minimum_required(VERSION 3.12)
project(binary-search-tree-jonathanprieto99)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS -pthread)



add_executable(binary-search-tree-jonathanprieto99 node.h bstree.h iterator.h main.cpp tester/tester.cpp tester/tester.h mocker/mocker.cpp mocker/mocker.h)