add_library(MemoryRegisters
            MemoryRegisters.h
            MemoryRegisters.cpp)

target_include_directories(MemoryRegisters PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(MemoryRegisters PUBLIC CONVERTER MemsHandler)