add_library(Aplication
            Aplication.hpp
            Aplication.cpp)

target_include_directories(Aplication PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(Aplication PUBLIC ModbusClient)
target_link_libraries(Aplication PUBLIC MainWindow )
