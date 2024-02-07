#include <iostream>
#include "oiltank.hpp"

int main(int argc, char* argv[]) {
  double distanceToOil; // cm
  double distanceSensorEmbedded; // cm

  if (argc > 2) {
    distanceToOil = std::stod(argv[1]);
    distanceSensorEmbedded = std::stod(argv[2]);
  } else {
    distanceToOil = 28.23;
    distanceSensorEmbedded = 5.8;
  }
  std::cout << "Using distance to oil: " << distanceToOil << "cm" << std::endl;
  std::cout << "Using distance oil sensor offset of: " << distanceToOil << "cm" << std::endl;

  double airCm = distanceToOil - distanceSensorEmbedded; // cm
  double airInches = airCm * 0.39370;
  double tankHeight = 28;
  double tankLength = 72;
  double tankWidth = 44;
  double inches = tankHeight - airInches; // convert from cm
  double gallons = vol_oval_h(inches, tankLength, tankWidth, tankHeight);

  std::cout << "Inches of air: " << airInches << std::endl;
  std::cout << "Inches of oil: " << inches << std::endl;
  std::cout << "Gallons: " << gallons << std::endl;

  std::cout << "I'm expecting 236, so this is off by: " << 236 - gallons << std::endl;

  return 0;
}