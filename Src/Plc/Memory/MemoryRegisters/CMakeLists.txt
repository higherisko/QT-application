add_library(MEMORYREGISTERS
            MemoryRegisters.h
            MemoryRegisters.cpp)

target_include_directories(MEMORYREGISTERS PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(MEMORYREGISTERS PUBLIC CONVERTER MEMSHANDL)