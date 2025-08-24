#pragma once
#include <string>
#include <mutex>
#include <unordered_map>

namespace FMOD {
    class System;
    class Sound;
    class Channel;
}

class SoundManager
{
private:
    struct SoundHandle {
        std::string name;
        FMOD::Sound* fmodSound;
        FMOD::Channel* fmodChannel;
    };

public:
    SoundManager();
    ~SoundManager();

    bool playSoundEvent(
        const std::string& soundName,
        bool is3DSound,
        bool isLooping,
        float pitch,
        float volume
    );

    void stopSoundByName(const std::string& soundName);

private:
    bool mIsInitialized;
    FMOD::System* mFmodSystem;
    std::unordered_map<std::string, SoundHandle> mSoundCache;
    std::mutex mCacheMutex;
};