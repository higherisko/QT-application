add_library(MODBUSHANDLER
            ModbusHandler.h
            ModbusHandler.cpp)

target_include_directories(MODBUSHANDLER PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(MODBUSHANDLER PUBLIC MODBUSFRAME CONVERTER)

