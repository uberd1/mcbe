#include "mce/render/GraphicsDevice.h"
#include <vector>
#include <memory>
#include <string> // Required for std::to_string

// --- PLACEHOLDERS AND HELPERS ---

struct GraphicsInfo {
    // PLACEHOLDER: Structure for raw hardware information
    std::string mDeviceName;
    char unknown_data_1[8];
    unsigned int mVendorId;
    unsigned int mDeviceId;
    unsigned int mDriverVersionMajor;
    unsigned int mDriverVersionMinor;
    unsigned long long mSomeCapabilityFlags1;
    unsigned long long mVideoMemory;
    unsigned long long mSystemMemory;
    char unknown_data_2[112];
    std::shared_ptr<Renderer> mRenderer;
};

GraphicsInfo* GetGlobalGraphicsInfo() {
    static GraphicsInfo g_globalGraphicsInfo;
    g_globalGraphicsInfo.mDeviceName = "NVIDIA GeForce RTX 7090 (Placeholder)";
    g_globalGraphicsInfo.mVendorId = 4318;
    g_globalGraphicsInfo.mVideoMemory = 8ULL * 1024 * 1024 * 1024;
    return &g_globalGraphicsInfo;
}

const char* GetRenderBackendName() {
    return "DirectX 12";
}

std::string GetGraphicsCardVendorNameFromId(unsigned int vendorId) {
    switch (vendorId) {
    case 4318:  return "nVidia";     // 0x10DE
    case 4098:  return "AMD";        // 0x1002
    case 32902: return "Intel";      // 0x8086
    case 20803: return "Qualcomm";   // 0x5143
    case 4112:  return "VideoLogic"; // 0x1010 (PowerVR)
    case 4681:
    case 4249:
    case 4291:  return "Samsung";
    case 2652:
    case 4454:  return "Broadcom";
    default:
        return std::to_string(vendorId);
    }
}
// --- END PLACEHOLDERS AND HELPERS ---


// --- GraphicsDevice Class Implementation ---

GraphicsDevice::GraphicsDevice()
{
    this->mVendorId = 0;
    this->mDeviceId = 0;
    this->mDriverVersionMajor = 0;
    this->mDriverVersionMinor = 0;
    this->mSomeCapabilityFlags1 = 0;
    this->mVideoMemory = 0;
    this->mSystemMemory = 0;
    this->mMaxTextureSize = 0;
    this->mMinTextureSize = 0;
    this->mRenderer = nullptr;
}

GraphicsDevice::~GraphicsDevice()
{
}

bool GraphicsDevice::Initialize(GraphicsInfo* graphicsInfo)
{
    this->mDeviceName = graphicsInfo->mDeviceName;
    this->mVendorId = graphicsInfo->mVendorId;
    this->mDeviceId = graphicsInfo->mDeviceId;
    this->mDriverVersionMajor = graphicsInfo->mDriverVersionMajor;
    this->mDriverVersionMinor = graphicsInfo->mDriverVersionMinor;
    this->mSomeCapabilityFlags1 = graphicsInfo->mSomeCapabilityFlags1;
    this->mVideoMemory = graphicsInfo->mVideoMemory;
    this->mSystemMemory = graphicsInfo->mSystemMemory;
    this->mRenderer = graphicsInfo->mRenderer;

    this->mGpuVendorString = GetGraphicsCardVendorNameFromId(this->mVendorId);

    this->mRenderBackendName = GetRenderBackendName();

    this->mMaxTextureSize = 16384; // PLACEHOLDER: In real code, this comes from graphicsInfo
    this->mMinTextureSize = 1;     // PLACEHOLDER: In real code, this comes from graphicsInfo

    return true;
}