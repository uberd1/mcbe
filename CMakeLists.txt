cmake_minimum_required(VERSION 3.10)
project(mcbe VERSION 1.0 LANGUAGES CXX)

add_executable(mcbe
    src/main.cpp

    # Game Logic
    src/game/block/Block.cpp
    src/game/block/StoneBlock.cpp
    src/game/options/Option.cpp
    src/game/options/IntOption.cpp
    src/game/options/FloatOption.cpp
    src/game/options/BoolOption.cpp
    src/game/options/StringOption.cpp
    src/game/options/Options.cpp

    # Minecraft Engine (mce) - Core Systems
    src/mce/core/TelemetryManager.cpp
    
    # MCE - Platform Specific
    src/mce/platform/DeviceInfo.cpp
    
    # MCE - Client Systems
    src/mce/client/ClientInstance.cpp
    
    # MCE - Sound System
    src/mce/common/sound/SoundManager.cpp
    
    # MCE - Rendering System
    src/mce/render/GraphicsDevice.cpp
    src/mce/render/ShaderManager.cpp
    
    # MCE - GUI / Screens
    src/mce/client/gui/screen/SettingsScreen.cpp
    src/mce/client/gui/screen/UIScreenFactory.cpp
)

target_include_directories(mcbe PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
)

set_property(TARGET mcbe PROPERTY CXX_STANDARD 17)
set_property(TARGET mcbe PROPERTY CXX_STANDARD_REQUIRED ON)

if(WIN32)
    set_property(TARGET mcbe PROPERTY LINK_OPTIONS "/SUBSYSTEM:CONSOLE")
endif()