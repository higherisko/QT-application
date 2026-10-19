add_subdirectory(Memory)
add_subdirectory(MemoryTags)

add_library(Plc
            Plc.hpp
            Plc.cpp)

add_library(PlcManager
            PlcManager.hpp
            PlcManager.cpp)

target_include_directories(Plc PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(Plc PUBLIC TagsAdapter
                                 TcpClient
                                 ModbusClient
                                 )

target_include_directories(PlcManager PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(PlcManager PUBLIC Plc)