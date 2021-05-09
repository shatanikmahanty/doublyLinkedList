cmake_minimum_required(VERSION 3.19)
project(doublyLinkedList)

set(CMAKE_CXX_STANDARD 14)

add_executable(Stack Stack.cpp)

add_executable(Queue Queue.cpp)

add_executable(doublyLinkedList DoublyLinkedList.cpp)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Node.cpp
        ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/DoublyLinkedList.cpp
        ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)