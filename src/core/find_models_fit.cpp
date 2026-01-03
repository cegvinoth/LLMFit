#include<fstream>
#include<iostream>
#include<sstream>
#include<filesystem>
#include "find_models_fit.h"
#include "available_vram.h"
#include "resource_path.h"

#define CYAN  "\033[36m"
#define RESET "\033[0m"

void FindModelsFit::modelsThatFit(int availableMemoryInGB) {
    std::string csvPath = ResourcePath::getDataFilePath("inference_models.csv");
    std::fstream inputFile(csvPath);
    std::string line;

    if(!inputFile.is_open()) {
        std::cerr << "Error: could not open file: " << csvPath << std::endl;
        std::cerr << "Data directory: " << LLMFIT_DATA_DIR << std::endl;
        return;
    }

    std::cout << CYAN << "✔ List of models that can run in your machine \n" << RESET << std::endl;

    std::cout << std::left
              << std::setw(20) << "MODEL"
              << std::setw(20) << "REQUIRED MEMORY"
              << std::setw(20) << "INFERENCE PRECISION"
              << std::endl;

    std::cout << std::string(60, '-') << std::endl;

    while(std::getline(inputFile, line)) {
       std::vector<std::string> parsedFields = FindModelsFit::stringToCSV(line);
       float requireMemory = std::stof(parsedFields[1]);
       if(requireMemory <= availableMemoryInGB) {
            std::cout << std::setw(20) << parsedFields[0]
              << std::setw(20) << parsedFields[1].append("GB")
              << std::setw(20) << parsedFields[2]
              << std::endl;
       }
    }
}

std::vector<std::string> FindModelsFit::stringToCSV(const std::string& line) {
    std::vector<std::string> fields;
    std::string field;
    std::stringstream ss(line);

    while(std::getline(ss, field, ',')) {
        fields.push_back(field);
    }

    return fields;
}
