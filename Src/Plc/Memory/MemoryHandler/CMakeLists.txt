add_library(MemsHandler
            MemHandler.hpp
            MemHandler.cpp)
target_include_directories(MemsHandler PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(MemsHandler PUBLIC CONVERTER)
