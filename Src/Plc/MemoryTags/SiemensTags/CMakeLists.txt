add_library(SiemensTags
            SiemensTags.hpp
            SiemensTags.cpp)

target_include_directories(SiemensTags PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(SiemensTags PUBLIC ModbusClient)
