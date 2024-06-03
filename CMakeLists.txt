cmake_minimum_required(VERSION 3.5)

project(qt-trading-bot-analyzer VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(QT_VERSION_MAJOR 6)


find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Gui Widgets)
find_package(Qt6 REQUIRED COMPONENTS OpenGLWidgets)
find_package(Qt6 REQUIRED COMPONENTS Network)
find_package(Qt6 REQUIRED COMPONENTS OpenGL)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/accsys)
include_directories(${OPENGL_INCLUDE_DIRS})


set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(qt-trading-bot-analyzer
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}

        mainwindow.h
        mainwindow.cpp
        mainwindow.ui

        graph/openglgraph.h 
        graph/openglgraph.cpp
        graph/utils.h
        graph/utils.cpp
        
        flask/users.csv
        
        search/ticker.json
        search/choice_dialog.h
        search/search_dialog.h
        search/search_dialog.cpp

        accsys/registerwindow.ui
        accsys/registerwindow.h
        accsys/registerwindow.cpp
        accsys/loginwindow.ui
        accsys/loginwindow.h
        accsys/loginwindow.cpp
        accsys/HttpClient.h
        accsys/HttpClient.cpp
    )
else()
    if(ANDROID)
        add_library(qt-trading-bot-analyzer SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(qt-trading-bot-analyzer
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(qt-trading-bot-analyzer PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Network)
target_link_libraries(qt-trading-bot-analyzer PRIVATE Qt6::OpenGLWidgets)
target_link_libraries(qt-trading-bot-analyzer PRIVATE Qt6::Network)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
# if(${QT_VERSION} VERSION_LESS 6.1.0)
#   set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.qt-trading-bot-analyzer)
# endif()
# set_target_properties(qt-trading-bot-analyzer PROPERTIES
#     ${BUNDLE_ID_OPTION}
#     MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
#     MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
#     MACOSX_BUNDLE TRUE
#     WIN32_EXECUTABLE TRUE
# )

include(GNUInstallDirs)
install(TARGETS qt-trading-bot-analyzer
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(qt-trading-bot-analyzer)
endif()
