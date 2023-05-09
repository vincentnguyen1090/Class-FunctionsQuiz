cmake_minimum_required(VERSION 3.15)
project(review_quizv2)

set(CMAKE_CXX_STANDARD 14)

add_executable(review_quizv2 main.cpp functions.cpp functions.h tests.cpp tests.h key.txt)