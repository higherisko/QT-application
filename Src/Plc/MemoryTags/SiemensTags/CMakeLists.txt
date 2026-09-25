add_library(PlcTags
            PlcTags.hpp
            PlcTags.cpp)

target_include_directories(PlcTags PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})


target_link_libraries(PlcTags PUBLIC MemoryRegisters)
