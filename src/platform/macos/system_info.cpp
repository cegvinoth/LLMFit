#include "system_info.h"
#include<sys/sysctl.h>

int SystemInfo::getNumberOfCpuCores() {
    int cores;
    size_t size = sizeof(cores);
    int result = getSystemInfoByName("hw.ncpu", &cores, &size);
    return (result == 0) ? cores : 0;
}

uint64_t SystemInfo::getRamSizeInBytes() {
    uint64_t ramSize;
    size_t size = sizeof(ramSize);
    int result = getSystemInfoByName("hw.memsize", &ramSize, &size);
    return (result == 0) ? ramSize : 0;
}

uint32_t SystemInfo::getGpuWiredLimitInMB() {
    uint32_t gpuVRamSize;
    size_t size = sizeof(gpuVRamSize);
    int result = getSystemInfoByName("iogpu.wired_limit_mb", &gpuVRamSize, &size);
    return (result == 0) ? gpuVRamSize : 0;
}

int SystemInfo::getSystemInfoByName(const char * name, void * ptr, size_t * size) {
    return sysctlbyname(name, ptr, size, nullptr, 0);
}
