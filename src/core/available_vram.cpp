#include "available_vram.h"
#include "../platform/macos/system_info.h"

float AvailableVRam::getAvailableVRamSizeInGB() {
    uint64_t ramSizeInBytes = SystemInfo::getRamSizeInBytes();
    float allowedVramSizeInGB = convertBytesToGigaBytes(getAllowedVRamSizeInBytes(ramSizeInBytes));
    return allowedVramSizeInGB;
}

float AvailableVRam::convertBytesToGigaBytes(uint64_t bytes) {
    return bytes/(1024 * 1024 * 1024);
}

uint64_t AvailableVRam::convertMegaBytesToBytes(uint32_t megaBytes) {
    return megaBytes * 1024 * 1024;
}

uint64_t AvailableVRam::getAllowedVRamSizeInBytes(uint64_t totalRamSizeInBytes) {
    uint32_t gpuWiredLimitInMB = SystemInfo::getGpuWiredLimitInMB();
    uint64_t allowedVRamLimitInBytes = convertMegaBytesToBytes(gpuWiredLimitInMB);

    if (gpuWiredLimitInMB == 0) {
        return totalRamSizeInBytes * 0.75;
    } else if (allowedVRamLimitInBytes < totalRamSizeInBytes) {
        return allowedVRamLimitInBytes;
    } else {
        return totalRamSizeInBytes;
    }
}
