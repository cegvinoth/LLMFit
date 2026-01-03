cmake_minimum_required(VERSION 3.15)
project(llmfit)

set(CMAKE_CXX_STANDARD 17)

include(GNUInstallDirs)

set(LLMFIT_DATA_DIR "${CMAKE_SOURCE_DIR}/src/static")

add_compile_definitions(LLMFIT_DATA_DIR="${LLMFIT_DATA_DIR}")

add_executable(llmfit src/main.cpp)
target_include_directories(llmfit PRIVATE ${CMAKE_SOURCE_DIR}/src)
add_subdirectory(src)

install(TARGETS llmfit
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})

install(FILES src/static/inference_models.csv
        DESTINATION ${CMAKE_INSTALL_DATADIR}/llmfit)
