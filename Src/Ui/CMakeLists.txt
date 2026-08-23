add_library(MainWindow 
    STATIC
        # MainWindow
        mainwindow.hpp
        mainwindow.cpp

        # Custom Widgets
        widgets/settings.hpp
        widgets/settings.cpp

        widgets/credits.hpp
        widgets/credits.cpp

        widgets/ipportselector.hpp
        widgets/ipportselector.cpp
)

target_include_directories(MainWindow
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(MainWindow 
    PUBLIC 
        Qt6::Widgets
)