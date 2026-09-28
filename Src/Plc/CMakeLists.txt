add_subdirectory(Memory)
add_subdirectory(MemoryTags)

add_library(Plc
            Plc.hpp
            Plc.cpp)

target_include_directories(Plc PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(Plc PUBLIC TagsAdapter
                                 TcpClient
                                 ModbusClient
                                 )