cmake_minimum_required(VERSION 3.10)
project(Guitfx VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find PortAudio
find_library(PORTAUDIO_LIB NAMES portaudio portaudio2)

if(NOT PORTAUDIO_LIB)
    message(FATAL_ERROR "PortAudio library not found! Please install portaudio19-dev or similar.")
endif()

message(STATUS "Found PortAudio: ${PORTAUDIO_LIB}")

# Source Files
set(SOURCES
    main.cpp
    src/ControlEngine.cpp
    src/DistortionEngine.cpp
    src/ReverbEngine.cpp
    src/DelayEngine.cpp
)

# Define Executable Target
add_executable(Guitfx ${SOURCES})

# Target Configuration (Must come AFTER add_executable)
target_include_directories(Guitfx PRIVATE include)
target_link_libraries(Guitfx PRIVATE ${PORTAUDIO_LIB})
