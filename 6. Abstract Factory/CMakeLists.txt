# CMakeList.txt : CMake project for 6. Abstract Factory, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.18)

project ("6. Abstract Factory")

# Add source to this project's executable.
add_executable (AbstractFactory 
main.cpp
RandomShuffle.cpp 
RandomShuffleSorted.cpp
Iota.cpp
)

# TODO: Add tests and install targets if needed.
