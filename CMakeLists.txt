cmake_minimum_required(VERSION 3.14)
project(2paint LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)
find_package(Qt6 REQUIRED COMPONENTS Gui)
find_package(Qt6 REQUIRED COMPONENTS Core)

include_directories(src/headers/ src/sources/)

file(GLOB_RECURSE sources src/main.cpp src/sources/*.cpp src/headers/*.h)

add_executable(2paint ${sources})

target_link_libraries(2paint PRIVATE Qt6::Widgets Qt6::Gui Qt6::Core)

install(TARGETS 2paint
    RUNTIME DESTINATION /usr/local/bin
)

install(CODE "file(WRITE \"/usr/local/share/applications/2paint.desktop\" [[
[Desktop Entry]
Name=2paint
Exec=2paint %F
Icon=accessories-image-editor
MimeType=text/plain;
Type=Application
Terminal=False
Categories=TextEditor;Utility;
]])
    message(STATUS \"Installed 2paint.desktop\")
")