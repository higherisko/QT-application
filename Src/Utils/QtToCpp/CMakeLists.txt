add_library(QtToCpp
            QtToCpp.hpp
            QtToCpp.cpp)

target_include_directories(QtToCpp PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(QtToCpp PRIVATE Qt6::Core)
target_link_libraries(QtToCpp PUBLIC ModbusClient
                                     SiemensTags)
