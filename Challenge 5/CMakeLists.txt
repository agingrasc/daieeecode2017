cmake_minimum_required(VERSION 3.5)
project(challenge5)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_EXE_LINKER_FLAGS "-pg")

set(SOURCE_FILES main.cpp)
set_source_files_properties(${SOURCE_FILES} PROPERTIES COMPILE_FLAGS "-Wall -pg")
add_executable(challenge5 ${SOURCE_FILES})
