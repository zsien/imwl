cmake_minimum_required(VERSION 3.16)
project(imwl LANGUAGES CXX C)

set(CMAKE_AUTOMOC ON)

find_package(PkgConfig REQUIRED)
find_package(Qt6 REQUIRED COMPONENTS Core Gui WaylandCompositor)

pkg_check_modules(xcb REQUIRED IMPORTED_TARGET xcb)
pkg_check_modules(xcb-xinput REQUIRED IMPORTED_TARGET xcb-xinput)

qt_add_executable(minimal-cpp
    main.cpp
    Compositor.cpp Compositor.h
    TextInputManagerV3.cpp TextInputManagerV3.h
    TextInputV3.cpp TextInputV3.h
    InputMethodManagerV2.cpp InputMethodManagerV2.h
    InputMethodV2.cpp InputMethodV2.h
    InputMethodKeyboardGrabV2.cpp InputMethodKeyboardGrabV2.h
    VirtualKeyboardManagerV1.cpp VirtualKeyboardManagerV1.h
    VirtualKeyboardV1.cpp VirtualKeyboardV1.h
)

qt6_generate_wayland_protocol_server_sources(minimal-cpp
    FILES
        ${CMAKE_CURRENT_SOURCE_DIR}/misc/wayland-protocols/text-input-unstable-v3.xml
        ${CMAKE_CURRENT_SOURCE_DIR}/misc/wayland-protocols/input-method-unstable-v2.xml
        ${CMAKE_CURRENT_SOURCE_DIR}/misc/wayland-protocols/virtual-keyboard-unstable-v1.xml
)

target_link_libraries(minimal-cpp PUBLIC
    Qt::Core
    Qt::Gui
    Qt::WaylandCompositor
    PkgConfig::xcb
    PkgConfig::xcb-xinput
)

install(TARGETS minimal-cpp
    BUNDLE BUNDLE DESTINATION .
)
