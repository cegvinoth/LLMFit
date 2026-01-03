#include<iostream>
#include<string>
#include "core/find_models_fit.h"
#include "core/available_vram.h"

int main(int argc, char** argv) {
    if(argc < 2) {
        std::cout << "Usage: llmfit list" << std::endl;
        return 1;
    }

    std::string cmd = argv[1];

    if(cmd == "list") {
        FindModelsFit::modelsThatFit(AvailableVRam::getAvailableVRamSizeInGB());
    } else {
        std::cout << "Unknown command" << std::endl;
        std::cout << "Usage: llmfit list" << std::endl;
        return 1;
    }
}