cmake_minimum_required(VERSION 3.10)
project(mcbe VERSION 1.0 LANGUAGES CXX)

add_executable(mcbe
    src/main.cpp
    src/game/block/Block.cpp
    src/game/block/StoneBlock.cpp
    src/mce/client/ClientInstance.cpp
    src/mce/client/gui/screen/SettingsScreen.cpp
    src/mce/client/gui/screen/UIScreenFactory.cpp
    src/mce/common/sound/SoundManager.cpp
    src/mce/core/TelemetryManager.cpp
    src/mce/platform/DeviceInfo.cpp
    src/mce/render/GraphicsDevice.cpp
    src/mce/render/ShaderManager.cpp
)

target_include_directories(mcbe PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
)

set_property(TARGET mcbe PROPERTY CXX_STANDARD 17)
set_property(TARGET mcbe PROPERTY CXX_STANDARD_REQUIRED ON)

if(WIN32)
    set_property(TARGET mcbe PROPERTY LINK_OPTIONS "/SUBSYSTEM:CONSOLE")
endif()