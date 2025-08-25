#pragma once
#include <string>
#include <memory>

struct GraphicsInfo;
class Renderer;

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
    std::string mGpuVendorString; // <--- ÈÑÏÐÀÂËÅÍÎ Ñ mCpuBrandString
    std::string mRenderBackendName;

    char unknown_data[28];

    int mMaxTextureSize;
    int mMinTextureSize;

    std::shared_ptr<Renderer> mRenderer;
};