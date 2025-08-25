#pragma once
#include <string>
#include <memory>

// --- PLACEHOLDERS ---
struct GraphicsInfo;
class Renderer;
// --- END PLACEHOLDERS ---

class GraphicsDevice
{
public:
    GraphicsDevice();
    ~GraphicsDevice();

    bool Initialize(GraphicsInfo* graphicsInfo);

private:
    std::string mDeviceName;
    unsigned int mVendorId;
    unsigned int mDeviceId;
    unsigned int mDriverVersionMajor;
    unsigned int mDriverVersionMinor;
    unsigned long long mSomeCapabilityFlags1;
    unsigned long long mVideoMemory;
    unsigned long long mSystemMemory;
    std::string mGpuVendorString;
    std::string mRenderBackendName;

    char unknown_data[28]; // PLACEHOLDER: Unanalyzed fields between known members

    int mMaxTextureSize;
    int mMinTextureSize;

    std::shared_ptr<Renderer> mRenderer;
};