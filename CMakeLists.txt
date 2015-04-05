cmake_minimum_required(VERSION 3.1)
project(queue)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(queue ${SOURCE_FILES} iterator.h iqueue.h queue.h queue.h queue.cpp queue_ui.h queue_ui.cpp app.h app.cpp)
