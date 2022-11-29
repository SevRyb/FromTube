cmake_minimum_required(VERSION 3.18)

project(FromTube VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)
find_package(QT NAMES Qt6 Qt5 COMPONENTS Multimedia REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Multimedia REQUIRED)
find_package(QT NAMES Qt6 Qt5 COMPONENTS MultimediaWidgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS MultimediaWidgets REQUIRED)

SET(QT_USE_QTMULTIMEDIA TRUE)
SET(QT_USE_QTMULTIMEDIAWIDGETS TRUE)

set(EXTERNALS "${CMAKE_SOURCE_DIR}/ext")

# Pybind11
add_subdirectory(${EXTERNALS}/pybind11)

### Change it
ADD_DEFINITIONS(-DQT_NO_KEYWORDS)

#========== Project Files ==========#
set(INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")
set(SOURCE_DIR "${CMAKE_SOURCE_DIR}/src")

include_directories(${INCLUDE_DIR})
include_directories(${SOURCE_DIR})

file(GLOB_RECURSE PROJECT_SOURCES
    "${INCLUDE_DIR}/*.h"
    "${SOURCE_DIR}/*.cpp"
)


#========== Setup Executable ==========#
#file(COPY "python/" DESTINATION "scripts")

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(FromTube
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET FromTube APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(FromTube SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(FromTube
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_include_directories(FromTube PRIVATE ${INCLUDE_DIR})
target_include_directories(FromTube PRIVATE ${SOURCE_DIR})

target_link_libraries(FromTube PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(FromTube PRIVATE Qt${QT_VERSION_MAJOR}::Multimedia)
target_link_libraries(FromTube PRIVATE Qt${QT_VERSION_MAJOR}::MultimediaWidgets)

target_link_libraries(FromTube PRIVATE
    pybind11::embed pybind11::module pybind11::pybind11
)

set_target_properties(FromTube PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(FromTube)
endif()
