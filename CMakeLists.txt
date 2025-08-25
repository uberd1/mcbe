cmake_minimum_required(VERSION 3.10)
project(mcbe VERSION 1.0 LANGUAGES CXX)

add_executable(mcbe
    src/main.cpp
    src/mce/platform/DeviceInfo.cpp
    src/mce/client/gui/screen/SettingsScreen.cpp
    src/mce/common/sound/SoundManager.cpp
    src/mce/render/GraphicsDevice.cpp
)

target_include_directories(mcbe PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
)

set_property(TARGET mcbe PROPERTY CXX_STANDARD 17)
set_property(TARGET mcbe PROPERTY CXX_STANDARD_REQUIRED ON)

if(WIN32)
    set_property(TARGET mcbe PROPERTY LINK_OPTIONS "/SUBSYSTEM:CONSOLE")
endif()