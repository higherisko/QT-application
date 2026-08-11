add_library(MODBUSPARSER
            ModbusParser.h
            ModbusParser.cpp)
add_library(MODBUSFRAME
            ModbusFrame.h
            ModbusFrame.cpp)

target_include_directories(MODBUSPARSER PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})          
target_include_directories(MODBUSFRAME PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(MODBUSFRAME PUBLIC CONVERTER)
target_link_libraries(MODBUSPARSER PUBLIC CONVERTER MODBUSFRAME) 