cmake_minimum_required(VERSION 3.17)
project(PHONEBOOK)

set(CMAKE_CXX_STANDARD 11)
find_package(SFML 2.5 COMPONENTS system window graphics)


add_executable(PHONEBOOK main.cpp contact.cpp contact.h phonebook.cpp phonebook.h)
target_link_libraries(PHONEBOOK sfml-system sfml-window sfml-graphics)