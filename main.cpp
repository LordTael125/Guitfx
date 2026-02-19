#include <ControlEngine.hpp>
#include <iostream>

int main(int argc, char* argv[]) {
  ControlEngine engine;

  engine.LiveStatus=false;

  engine.DistortionValue={8.0,1.0,1.0};
  engine.Distortion=true;
  

  if (!engine.startEngine()) {
    std::cerr << "Failed to start the engine";  // Debug Comment
    return 1;
  }

  std::cout << "Engine Running. Press Enter to stop"; 
  std::cin.get();

  engine.stopEngine();
  return 0;
}
