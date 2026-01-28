#include <Effects/DistortionEngine.hpp>
#include <iostream>

int main() {
  GuitarDistortionEngine engine;

  engine.setDrive(10.0f);
  engine.setThreshold(0.8f);
  engine.setOutputGain(0.7f);

  if (!engine.start()) {
    std::cerr << "Failed to start the engine";
    return 1;
  }

  std::cout << "Engine Running. Press Enter to stop";
  std::cin.get();

  engine.stop();
  return 0;
}
