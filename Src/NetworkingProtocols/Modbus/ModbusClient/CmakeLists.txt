add_library(MODBUSClient
            ModbusClient.h
            ModbusClient.cpp
            )
target_include_directories(MODBUSClient PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(MODBUSClient PUBLIC TCPCLIENT CONVERTER MODBUSPARSER MODBUSHANDLER MEMORYREGISTERS)