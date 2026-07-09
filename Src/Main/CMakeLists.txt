
qt_standard_project_setup()


qt_add_executable(neviem
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    
)
target_link_libraries(neviem PRIVATE Qt${QT_VERSION_MAJOR}::Widgets
                                                            TCPCLIENT)

set_target_properties(neviem PROPERTIES
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS neviem
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)