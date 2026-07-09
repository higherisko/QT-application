add_library(TCPCLIENT
            TcpClient.hpp
            TcpClient.cpp)

target_include_directories(TCPCLIENT PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(TCPCLIENT PUBLIC Qt6::Network)




