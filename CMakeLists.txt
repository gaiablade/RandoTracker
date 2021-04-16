cmake_minimum_required(VERSION 3.5)

project(Tracker LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_COMPILER "/usr/bin/g++")

set(CMAKE_CXX_FLAGS "${CMAKe_CXX_FLAGS} -Wall -Wextra -O3")

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check https://doc.qt.io/qt/deployment-android.html for more information.
# They need to be set before the find_package( ...) calls below.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets Gui REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

include_directories(
    vendor
    vendor/json/include
)

set(PROJECT_SOURCES
        source/main.cpp
        source/mainwindow.cpp
        source/mainwindow.h
        source/mainwindow.ui

        source/Clickable.h
        source/Clickable.cpp
        source/FileOpen.h
        source/FileOpen.cpp
        source/Tab.h
        source/Tab.cpp
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Tracker
        ${PROJECT_SOURCES}
    )
else()
    if(ANDROID)
        add_library(Tracker SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(Tracker
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(Tracker PRIVATE Qt${QT_VERSION_MAJOR}::Widgets fmt)
