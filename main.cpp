#include <ControlEngine.hpp>
#include <iostream>

int main() {
  ControlEngine engine;

  engine.LiveStatus=false;

  engine.DistortionValue={1.0,1.0,1.0};
  engine.setDistortionParam(engine.DistortionValue);

  if (!engine.startDistortionEngine()) {
    std::cerr << "Failed to start the engine";
    return 1;
  }

  std::cout << "Engine Running. Press Enter to stop";
  std::cin.get();

  engine.stopDistortionEngine();
  return 0;
}
