#ifndef SYSTEM_INFO
#define SYSTEM_INFO

#include<string>

class SystemInfo {
    public:
        static int getNumberOfCpuCores();
        static uint64_t getRamSizeInBytes();
        static uint32_t getGpuWiredLimitInMB();
    private:
        static int getSystemInfoByName(const char * name, void * ptr, size_t * size);
};

#endif