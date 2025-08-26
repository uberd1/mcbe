#include "game/options/Options.h"
#include "game/options/StringOption.h"
#include "game/options/IntOption.h"
#include "game/options/FloatOption.h"
#include "game/options/BoolOption.h"

// This is the complete recreation of the InitializeGameOptions function.
// It creates and registers every single game option with its default value.
Options::Options()
{
    // ====================================================================
    // == Profile & General
    // ====================================================================
    mOptions.push_back(std::make_unique<StringOption>("options.name", "mp_username", "Steve"));
    mOptions.push_back(std::make_unique<StringOption>("options.language", "game_language", "en_US"));
    mOptions.push_back(std::make_unique<IntOption>("options.filelocation.title", "dvce_filestoragelocation", 1, 0, 1));

    // ====================================================================
    // == Gameplay
    // ====================================================================
    mOptions.push_back(std::make_unique<IntOption>("options.difficulty", "game_difficulty_new", 2, 0, 3));
    mOptions.push_back(std::make_unique<BoolOption>("options.servervisible", "mp_server_visible", true));
    mOptions.push_back(std::make_unique<BoolOption>("options.xboxlivevisible", "mp_xboxlive_visible", true));

    // ====================================================================
    // == Controls (Keyboard, Controller, Touch)
    // ====================================================================
    mOptions.push_back(std::make_unique<FloatOption>("options.sensitivity", "ctrl_sensitivity2", 0.5f, 0.0f, 1.0f));
    mOptions.push_back(std::make_unique<BoolOption>("options.invertYAxis", "ctrl_invertmouse", false));
    mOptions.push_back(std::make_unique<BoolOption>("options.lefthanded", "ctrl_islefthanded", false));
    mOptions.push_back(std::make_unique<BoolOption>("options.autojump", "ctrl_autojump", true));
    mOptions.push_back(std::make_unique<BoolOption>("options.swapJumpAndSneak", "ctrl_swapjumpandsneak", false));
    mOptions.push_back(std::make_unique<BoolOption>("options.destroyvibration", "feedback_vibration", true));
    mOptions.push_back(std::make_unique<BoolOption>("options.toggleCrouch", "ctrl_togglecrouch", false));
    mOptions.push_back(std::make_unique<BoolOption>("options.hotbarOnlyTouch", "ctrl_hotbarOnlyTouch", true));
    mOptions.push_back(std::make_unique<BoolOption>("options.usetouchpad", "ctrl_usetouchjoypad", false));
    mOptions.push_back(std::make_unique<FloatOption>("options.buttonSize", "gfx_dpadscale", 0.5f, 0.0f, 1.0f));

    // ====================================================================
    // == Graphics
    // ====================================================================
    mOptions.push_back(std::make_unique<IntOption>("options.renderDistance", "gfx_viewdistance", 16, 2, 96));
    mOptions.push_back(std::make_unique<FloatOption>("options.particleRenderDistance", "gfx_particleviewdistance", 0.5f, 0.0f, 1.0f));
    mOptions.push_back(std::make_unique<BoolOption>("options.viewBobbing", "gfx_viewbobbing", true));
    mOptions.push_back(std::make_unique<BoolOption>("options.graphics", "gfx_fancygraphics", true));
    mOptions.push_back(std::make_unique<BoolOption>("options.smoothlighting", "gfx_smoothlighting", true));
    mOptions.push_back(std::make_unique<BoolOption>("options.fancyskies", "gfx_fancyskies", true));
    mOptions.push_back(std::make_unique<BoolOption>("options.toggleclouds", "gfx_toggleclouds", true));
    mOptions.push_back(std::make_unique<BoolOption>("options.transparentleaves", "gfx_transparentleaves", true));
    mOptions.push_back(std::make_unique<FloatOption>("options.gamma", "gfx_gamma", 0.5f, 0.0f, 1.0f));
    mOptions.push_back(std::make_unique<IntOption>("options.maxFramerate", "gfx_max_framerate", 0, 0, 25));
    mOptions.push_back(std::make_unique<BoolOption>("options.fullscreen", "gfx_fullscreen", false));
    mOptions.push_back(std::make_unique<IntOption>("options.guiScale.optionName", "gfx_guiscale_offset", 0, -1, 1));
    mOptions.push_back(std::make_unique<BoolOption>("options.hidehud", "gfx_hidehud", false));
    mOptions.push_back(std::make_unique<BoolOption>("options.hidehand", "gfx_hidehand", false));
    mOptions.push_back(std::make_unique<BoolOption>("options.hidepaperdoll", "gfx_hidepaperdoll", false));
    mOptions.push_back(std::make_unique<BoolOption>("options.showautosaveicon", "gfx_showautosaveicon", true));
    mOptions.push_back(std::make_unique<BoolOption>("options.splitscreen", "gfx_splitscreen", false)); // Placeholder for a more complex option
    mOptions.push_back(std::make_unique<FloatOption>("options.interfaceOpacity", "gfx_interface_opacity", 0.9f, 0.0f, 1.0f));
    mOptions.push_back(std::make_unique<FloatOption>("options.splitscreenInterfaceOpacity", "gfx_splitscreen_interface_opacity", 0.9f, 0.0f, 1.0f));
    mOptions.push_back(std::make_unique<IntOption>("options.msaa", "gfx_msaa", 2, 0, 5));
    mOptions.push_back(std::make_unique<BoolOption>("options.texelAA", "gfx_texel_aa_2", true));

    // ====================================================================
    // == Audio
    // ====================================================================
    mOptions.push_back(std::make_unique<FloatOption>("options.sound", "audio_sound", 1.0f, 0.0f, 1.0f));
    mOptions.push_back(std::make_unique<FloatOption>("options.music", "audio_music", 1.0f, 0.0f, 1.0f));

    // ====================================================================
    // == VR Settings
    // ====================================================================
    mOptions.push_back(std::make_unique<FloatOption>("options.vrSensitivity", "vr_sensitivity", 80.0f, 0.0f, 100.0f));
    mOptions.push_back(std::make_unique<FloatOption>("options.vrGamma", "vr_gamma", 0.5f, 0.0f, 1.0f));
    mOptions.push_back(std::make_unique<BoolOption>("options.StutterTurn", "vr_stutter_turn", true));
    mOptions.push_back(std::make_unique<BoolOption>("options.vrHideHud", "vr_hide_hud", false));
    mOptions.push_back(std::make_unique<BoolOption>("options.vrHideHand", "vr_hide_hand", false));
    mOptions.push_back(std::make_unique<BoolOption>("options.vrAutojump", "vr_autojump", true));
    mOptions.push_back(std::make_unique<BoolOption>("options.vrLinearMotion", "vr_head_steering", true));
    mOptions.push_back(std::make_unique<BoolOption>("options.3DRendering", "vr_stereorendering", true));
    mOptions.push_back(std::make_unique<BoolOption>("options.vrMirrorTexture", "vr_mirror_texture", true));
    mOptions.push_back(std::make_unique<BoolOption>("options.vrHudDrifts", "vr_hud_drift", true));
    mOptions.push_back(std::make_unique<BoolOption>("options.vrLivingRoomCursorCentered", "vr_living_room_cursor_centered", false));
    mOptions.push_back(std::make_unique<BoolOption>("options.vrLinearJump", "vr_linear_jump", true));

    // ====================================================================
    // == Developer & Hidden Options
    // ====================================================================
    mOptions.push_back(std::make_unique<BoolOption>("options.dev_showChunkMap", "dev_showchunkmap", false));
    mOptions.push_back(std::make_unique<BoolOption>("options.dev_serverInstanceThread", "dev_serverInstanceThread_2", true));
    mOptions.push_back(std::make_unique<BoolOption>("options.dev_enableProfiler", "dev_enable_profiler", false));
    mOptions.push_back(std::make_unique<BoolOption>("options.dev_achievementsAlwaysEnabled", "dev_achievements_always_enabled", false));
    mOptions.push_back(std::make_unique<BoolOption>("options.dev_useRetailXboxSandbox", "dev_use_retail_xbox_sandbox", true));
}

Options::~Options()
{
}