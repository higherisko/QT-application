cmake_minimum_required(VERSION 3.16)

project(neviem VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/Cmake")

find_package(Qt6 REQUIRED COMPONENTS Widgets Network)
add_subdirectory(Src)

include(AddGitSubModule)
add_git_submodule(External/json)

qt_standard_project_setup()