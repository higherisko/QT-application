add_library(Style
            Style.hpp)
target_include_directories(Style PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(Style PUBLIC Qt6::Core)