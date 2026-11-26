add_library(NetworkingManager
            NetworkingManager.hpp
            NetworkingManager.cpp)

target_include_directories(NetworkingManager PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(NetworkingManager PUBLIC MCPROTOCOL ModbusClient PlcManager)

target_link_libraries(NetworkingManager PUBLIC Qt6::Core)
