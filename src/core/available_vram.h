#ifndef AVAILABLE_VRAM
#define AVAILABLE_VRAM

#include<cstdint>

class AvailableVRam {
    public:
        static float getAvailableVRamSizeInGB();
    private:
        static float convertBytesToGigaBytes(uint64_t bytes);
        static uint64_t convertMegaBytesToBytes(uint32_t megaBytes);
        static uint64_t getAllowedVRamSizeInBytes(uint64_t totalRamSizeInBytes);
};

#endif