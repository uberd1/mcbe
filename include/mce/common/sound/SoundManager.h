#pragma once
#include <string>
#include <mutex>
#include <unordered_map>


namespace FMOD {
    class FMOD_System;
    class FMOD_Sound;
    class FMOD_Channel;
}

class SoundManager
{
private:
    struct SoundHandle {
        std::string name;
        FMOD::FMOD_Sound* fmodSound;
        FMOD::FMOD_Channel* fmodChannel;
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
    FMOD::FMOD_System* mFmodSystem;
    std::unordered_map<std::string, SoundHandle> mSoundCache;
    std::mutex mCacheMutex;
};