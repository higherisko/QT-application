add_library(MainWindow 
    STATIC
        mainwindow.hpp
        mainwindow.cpp
)

target_include_directories(MainWindow
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(MainWindow 
    PUBLIC 
        Qt6::Widgets
)