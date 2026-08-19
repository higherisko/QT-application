add_library(TcpClient
            TcpClient.hpp
            TcpClient.cpp)

target_include_directories(TcpClient PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(TcpClient PUBLIC Qt6::Network)




