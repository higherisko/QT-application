add_library(TagsAdapter
            TagsAdapter.hpp
            TagsAdapter.cpp)

target_include_directories(TagsAdapter PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(TagsAdapter PUBLIC PlcTags MemoryRegisters)

