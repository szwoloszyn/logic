cmake_minimum_required(VERSION 3.5)

project(logic LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(logic main.cpp
                    README.md
                    atom.h atom.cpp
                    functions.h functions.cpp
                    formula.h formula.cpp)

install(TARGETS logic
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
