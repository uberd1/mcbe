#pragma once
#include <string>
// --- PLACEHOLDERS ---

class SoundManager;
class MusicManager;
class GraphicsDevice;

// --- END PLACEHOLDERS ---



class ClientInstance
{
public:


    // (offset +48) - sub_71009B5DD0
    virtual void someFunction_vtable48();

    // (offset +56) - sub_71009B5DD8
    virtual void someFunction_vtable56();

    // (offset +536) - from Client::onStart
    virtual void* getSomeOtherManager(); // PLACEHOLDER

    // (offset +560) - from Client::onStart
    virtual void* getGameStore(); // PLACEHOLDER, qword_7103266AC0

    // (offset +584) - from Client::onStart
    virtual const std::string& getDeviceModel() const;

    // (offset +624) - from Client::onStart
    virtual void* getGuiData();

    // (offset +656) - from Client::onStart
    virtual const std::string& getPlatformName() const;

    // (offset +896, +904) - from initializeRender
    virtual void* getSomePathProvider(); // PLACEHOLDER

    // (offset +936) - from Client::onStart
    virtual void setSomeTimestamp(long long timestamp);

    // (offset +968) - from Client::onStart
    virtual bool isBeta() const;

    // (offset +984) - from Client::onStart
    virtual bool isTelemetryEnabled() const;

    // (offset +1040, +1048) - from Client::onStart
    virtual void someInitFunction_vtable1040();
    virtual void someInitFunction_vtable1048();

    // (offset +1072) - from Client::onStart
    virtual void setSomeOtherManager2(void* manager); // PLACEHOLDER

    // (offset +1080) - from Client::onStart & initializeRender
    virtual int getPlatformId() const;

    // (offset +1136) - from TelemetryManager
    virtual unsigned long long getAvailableMemory() const;

    // (offset +1208) - from Client::onStart
    virtual void someInitFunction_vtable1208();

    // (offset +1248) - from TelemetryManager
    virtual bool isTablet() const;

    // (offset +1320) - from initializeRender
    virtual void someInitFunction_vtable1320();

    // (offset +1448) - from Client::onStart
    virtual void setSomethingRelatedToUser(bool value);

    // (offset +1632) - from Client::onStart
    virtual void someInitFunction_vtable1632();

   
    void initializeRender(
        void* someWindow, // Placeholder for HWND or similar
        // ... a lot of other arguments we haven't analyzed
        char a16
    );

private:

    // SoundManager* mSoundManager;
    // GraphicsDevice* mGraphicsDevice;
    
};


ClientInstance* GetClientInstance();