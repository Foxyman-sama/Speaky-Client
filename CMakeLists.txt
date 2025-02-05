cmake_minimum_required(VERSION 3.16..3.30)

project(Speaky-Client VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 26)

find_package(Qt6 6.5 REQUIRED COMPONENTS Quick)
find_package(Boost REQUIRED CONFIG)

qt_standard_project_setup(REQUIRES 6.5)

qt_add_executable(appSpeaky-Client
    main.cpp
)

qt_add_qml_module(appSpeaky-Client
    URI Speaky-Client
    VERSION 1.0
    QML_FILES
        Main.qml
        QML_FILES MessageBox.qml
        QML_FILES MainPage.qml
        QML_FILES Chat.qml
        QML_FILES BottomPanel.qml
        QML_FILES RegistrationForm.qml
        SOURCES network.h network.cpp
        RESOURCES .clang-format
        SOURCES chatmodel.h chatmodel.cpp
        RESOURCES
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appSpeaky-Client PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appSpeaky-Client
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appSpeaky-Client PUBLIC
    Qt6::Quick
    ${BOOST_LIBRARIES}
)

target_include_directories(appSpeaky-Client PUBLIC ${BOOST_INCLUDE_DIRS})

message(CHECK_START "${BOOST_INCLUDE_DIRS}")

include(GNUInstallDirs)
install(TARGETS appSpeaky-Client
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

list(APPEND QML_IMPORT_PATH "/usr/lib/qt/qml")
list(APPEND QML_IMPORT_PATH "/usr/lib64/qt/qml")
list(REMOVE_DUPLICATES QML_IMPORT_PATH)
set(QML_IMPORT_PATH ${QML_IMPORT_PATH}
    CACHE STRING "Qt Creator 6.8 extra qml import paths"
    FORCE
)

add_subdirectory(Packages)
