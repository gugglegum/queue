cmake_minimum_required(VERSION 3.1)
project(queue)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES src/main.cpp)
add_executable(queue ${SOURCE_FILES} src/iterator.h src/iqueue.h src/queue.h src/queue.h src/queue.cpp src/queue_ui.h src/queue_ui.cpp src/app.h src/app.cpp)
