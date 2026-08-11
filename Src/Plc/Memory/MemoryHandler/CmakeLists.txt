add_library(MEMSHANDL
            MemHandler.hpp
            MemHandler.cpp)
target_include_directories(MEMSHANDL PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(MEMSHANDL PUBLIC CONVERTER)
