add_library(MainWindow 
    STATIC
        # MainWindow
        mainwindow.hpp
        mainwindow.cpp

        # Custom Widgets
        widgets/credits.hpp
        widgets/credits.cpp
)

target_include_directories(MainWindow
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(MainWindow 
    PUBLIC 
        Qt6::Widgets
)