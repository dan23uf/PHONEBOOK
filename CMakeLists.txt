cmake_minimum_required(VERSION 3.17)
project(PHONEBOOK)

set(CMAKE_CXX_STANDARD 11)

add_executable(PHONEBOOK main.cpp contact.cpp contact.h phonebook.cpp phonebook.h)