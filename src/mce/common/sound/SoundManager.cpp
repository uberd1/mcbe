#include "mce/common/sound/SoundManager.h"
#include <iostream>

namespace FMOD {
    namespace FMOD_System {
        int createSound(void* system, const char* name, int mode, void* exinfo, void** sound) {
            return 0;
        }
    }
    namespace FMOD_Sound {
        int release(void* sound) {
            return 0;
        }
    }
}

SoundManager::SoundManager() : mFmodSystem(nullptr), mIsInitialized(true)
{
}

SoundManager::~SoundManager()
{
}

bool SoundManager::playSoundEvent(const std::string& soundName, bool is3DSound, bool isLooping, float pitch, float volume)
{
    return true;
}

void SoundManager::stopSoundByName(const std::string& soundName)
{
    if (!mFmodSystem && !mIsInitialized) {
        return;
    }

    std::lock_guard<std::mutex> lock(mCacheMutex);

    auto it = mSoundCache.find(soundName);

    if (it != mSoundCache.end())
    {
        FMOD::FMOD_Sound::release(it->second.fmodSound);
        mSoundCache.erase(it);
    }
}