add_library(ModbusClient
            ModbusClient.h
            ModbusClient.cpp
            )
target_include_directories(ModbusClient PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(ModbusClient PUBLIC CONVERTER 
                                          MODBUSPARSER 
                                          MODBUSHANDLER 
                                          MemoryRegisters
                                          QtToCpp)