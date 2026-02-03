#include <ControlEngine.hpp>
#include <iostream>

int main() {
  ControlEngine engine;

  engine.LiveStatus=false;

  engine.DistortionValue={10.0,0.9,0.5};
  engine.setParamDistortion(engine.DistortionValue);

  if (!engine.startDistortionEngine()) {
    std::cerr << "Failed to start the engine";
    return 1;
  }

  std::cout << "Engine Running. Press Enter to stop";
  std::cin.get();

  engine.stopDistortionEngine();
  return 0;
}
