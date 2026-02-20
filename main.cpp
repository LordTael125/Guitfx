#include <ControlEngine.hpp>
#include <DataType.hpp>
#include <iostream>

int main(int argc, char* argv[]) {
  ControlEngine engine;

  engine.LiveStatus=false;

  engine.Distortion = true;
  engine.DistortionValue = {10.0,0.5,0.5};

  // engine.Delay=true;
  // engine.setDelayMode(Delay::echoDelay);
  

  if (!engine.startEngine()) {
    std::cerr << "Failed to start the engine";  // Debug Comment
    return 1;
  }

  std::cout << "Engine Running. Press Enter to stop"; 
  std::cin.get();

  engine.stopEngine();
  return 0;
}
