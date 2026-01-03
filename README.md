# LLMFit

**Instantly discover which Large Language Models (LLMs) can actually run on your machine, before you download them.**

[![C++17](https://img.shields.io/badge/C%2B%2B-17-blue.svg)](https://en.wikipedia.org/wiki/C%2B%2B17)
[![CMake](https://img.shields.io/badge/CMake-3.15+-green.svg)](https://cmake.org/)
[![Platform](https://img.shields.io/badge/platform-macOS-lightgrey.svg)](https://github.com)

## Overview

Running Large Language Models locally requires significant system memory (RAM/VRAM). **LLMFit** is a lightweight command-line tool that analyzes your system's available memory and instantly shows you which LLM models will fit, along with their supported inference precisions (FP16, INT8, INT4).

No more guessing which models you can run. No more out-of-memory errors. Just run LLMFit and get a clear list of compatible models.

## The Problem LLMFit Solves

**Before LLMFit:**
- Download a 13GB model file → Out of memory error
- Search through documentation to find memory requirements
- Trial and error to find models that fit your system
- Uncertainty about which quantization levels (INT8, INT4) will work

**With LLMFit:**
```bash
$ llmfit list

✔ List of models that can run in your machine

MODEL               REQUIRED MEMORY     INFERENCE PRECISION
------------------------------------------------------------
Llama-7B            7GB                 INT8
Llama-7B            4GB                 INT4
Mistral-7B          7GB                 INT8
BERT-Base           0.42GB              FP16
...
```

Instantly know what works on your hardware.

## Features

- **Automatic Memory Detection**: Analyzes your system's available RAM/VRAM automatically
- **120+ Model Database**: Includes popular models like Llama, Mistral, Falcon, GPT-J, BERT, and more
- **Multiple Precision Support**: Shows FP16, INT8, and INT4 quantization options
- **macOS Support**: Currently optimized for macOS (Linux and Windows support planned)
- **Zero Configuration**: Just build and run
- **Fast & Lightweight**: Written in C++ for instant results

## Supported Models

LLMFit includes memory requirements for:
- **Llama family**: Llama 1, 2, 3, 3.1 (7B, 13B, 33B, 65B, 70B variants)
- **Mistral/Mixtral**: Mistral 7B, Mixtral 8x7B
- **Falcon**: 7B, 40B, 180B
- **BERT**: Base and Large variants
- **GPT**: GPT-2, GPT-J
- **StarCoder**: 15B, 3B variants
- **Qwen**: Multiple sizes
- **Phi**: Microsoft Phi models
- And many more...

## Requirements

- **CMake** 3.15 or higher
- **C++17** compatible compiler (Clang 5+ recommended for macOS)
- **Operating System**: macOS (10.13+ or later recommended)

**Note**: Linux and Windows support is planned for future releases.

## Quick Start

### Build from Source

```bash
# Clone the repository
git clone https://github.com/cegvinoth/LLMFit.git
cd LLMFit

# Configure and build
cmake -B build
cmake --build build

# Run
./build/llmfit list
```

### System-Wide Installation

```bash
# Build with installation prefix
cmake -B build -DCMAKE_INSTALL_PREFIX=/usr/local
cmake --build build

# Install (may require sudo)
sudo cmake --install build

# Run from anywhere
llmfit list
```

## Usage

### List Compatible Models

Check which models fit your current available memory:

```bash
llmfit list
```

**Example Output:**
```
✔ List of models that can run in your machine

MODEL               REQUIRED MEMORY     INFERENCE PRECISION
------------------------------------------------------------
Llama-7B            7GB                 INT8
Llama-7B            4GB                 INT4
Llama-13B           7GB                 INT4
Mistral-7B          7GB                 INT8
Mistral-7B          4GB                 INT4
BERT-Base           0.42GB              FP16
BERT-Base           0.21GB              INT8
StarCoder-15B       8GB                 INT4
...
```

The output shows:
- **MODEL**: Name and size of the LLM
- **REQUIRED MEMORY**: How much RAM/VRAM the model needs
- **INFERENCE PRECISION**: Quantization level (FP16=full precision, INT8=8-bit, INT4=4-bit)

### Understanding Inference Precision

- **FP16** (16-bit floating point): Highest quality, largest memory footprint
- **INT8** (8-bit integer): ~50% memory reduction, minimal quality loss
- **INT4** (4-bit integer): ~75% memory reduction, slight quality loss but very efficient

Lower precision = less memory = more models fit on your system!

## How It Works

1. **Detects System Memory**: Uses platform-specific APIs to query available RAM/VRAM
2. **Loads Model Database**: Reads the bundled CSV database of 120+ models and their memory requirements
3. **Filters Compatible Models**: Compares your available memory against each model's requirements
4. **Displays Results**: Shows a formatted table of models that will fit

### Technical Details

- Written in **modern C++17** for performance and portability
- Uses **CMake** build system for cross-platform compilation
- Platform abstraction layer designed to support multiple operating systems
- Currently implements macOS-specific system memory detection
- Model database stored in CSV format for easy updates

## Project Structure

```
LLMFit/
├── CMakeLists.txt              # Build configuration
├── README.md                   # This file
├── src/
│   ├── main.cpp                # Entry point
│   ├── core/                   # Core business logic
│   │   ├── find_models_fit.cpp # Model filtering logic
│   │   ├── find_models_fit.h
│   │   ├── available_vram.cpp  # Memory detection
│   │   ├── available_vram.h
│   │   └── resource_path.h     # Path resolution utility
│   ├── platform/               # Platform-specific code
│   │   └── macos/
│   │       └── system_info.cpp # macOS system queries
│   └── static/
│       └── inference_models.csv # Model database (120+ entries)
└── build/                      # Build artifacts (generated)
```

## Configuration

### Adding New Models

To add models to the database, edit `src/static/inference_models.csv`:

```csv
ModelName,MemoryInGB,Precision
Llama-7B,14,FP16
Llama-7B,7,INT8
Llama-7B,4,INT4
```

Format: `ModelName,RequiredMemoryGB,InferencePrecision`

## Roadmap

- [ ] **Linux platform support** - Add Linux memory detection implementation
- [ ] **Windows platform support** - Add Windows memory detection implementation
- [ ] GPU VRAM detection and filtering
- [ ] Model family filtering (e.g., only show Llama models)
- [ ] Model database updates

## License

Apache 2.0 License - see LICENSE file for details

## Why LLMFit?

As local LLM deployment becomes more popular, developers and researchers need quick ways to determine hardware compatibility. LLMFit was created to solve this exact problem: **quickly identify which models will run on your local machine without trial and error.**

Whether you're a researcher experimenting with different models, a developer building LLM-powered applications, or an enthusiast exploring local AI, LLMFit saves you time and frustration.

---

**Made with ❤️ for the local LLM community**
