add_library(QTTOCPP
            QtToCpp.hpp
            QtToCpp.cpp)

target_include_directories(QTTOCPP PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(QTTOCPP PRIVATE Qt6::Core)
