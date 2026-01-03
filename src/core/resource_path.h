#ifndef RESOURCE_PATH_H
#define RESOURCE_PATH_H

#include <filesystem>
#include <string>

namespace ResourcePath {
    inline std::string getDataFilePath(const std::string& filename) {
        std::filesystem::path dataDir(LLMFIT_DATA_DIR);
        std::filesystem::path fullPath = dataDir / filename;

        return fullPath.string();
    }
}

#endif
