#include "mce/platform/DeviceInfo.h"

#include <cstdio>
#include <cstdarg>

namespace nn {
    namespace oe {
        void GetPseudoDeviceId(unsigned int* out_id) {
            if (out_id) {
                *out_id = 0xDEADBEEF;
            }
        }
    }
    namespace util {
        void TSNPrintf(char* buffer, size_t bufferSize, const char* format, ...) {
            va_list args;
            va_start(args, format);
            vsnprintf_s(buffer, bufferSize, _TRUNCATE, format, args);
            va_end(args);
        }
    }
}

DeviceInfo::DeviceInfo()
{
    unsigned int pseudoId = 0;
    nn::oe::GetPseudoDeviceId(&pseudoId);

    char formattedIdBuffer[40];
    nn::util::TSNPrintf(
        formattedIdBuffer,
        sizeof(formattedIdBuffer),
        "%08x-cafe-babe-d00d-%012llx",
        pseudoId,
        (long long)pseudoId * 17
    );

    this->platformName = "Nintendo";
    this->deviceId = formattedIdBuffer;
    this->ipAddress = "0.0.0.0";
}

DeviceInfo::~DeviceInfo()
{
}