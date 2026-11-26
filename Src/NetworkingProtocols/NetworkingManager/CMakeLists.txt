add_library(NetworkingManager
            NetworkingManager.hpp
            NetworkingManager.cpp)

target_include_directories(NetworkingManager PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
