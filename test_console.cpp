#include <iostream>
#include "oiltank.h"

/**
 * Test calculation of oil tank gallons based on distance sensor readings.
 *
 * @param argc number of command line arguments
 * @param argv array of command line arguments
 *
 * @return integer representing the exit status
 *
 * @throws None
 */
int main(int argc, char* argv[]) {
  double distanceToOil; // cm
  double distanceSensorEmbedded; // cm

  if (argc > 2) {
    distanceToOil = std::stod(argv[1]);
    distanceSensorEmbedded = std::stod(argv[2]);
  } else {
    distanceToOil = 13.00;
    distanceSensorEmbedded = 2.0;
  }
  std::cout << "Using distance to oil: " << distanceToOil << "cm" << std::endl;
  std::cout << "Using distance oil sensor offset of: " << distanceToOil << "cm" << std::endl;

  double airCm = distanceToOil - distanceSensorEmbedded; // cm
  double airInches = airCm * 0.39370;
  double tankHeight = 27.0;
  double tankLength = 60.5;
  double tankWidth = 44;
  double inches = tankHeight - airInches; // convert from cm
  double gallons = kariudo::oiltank::vol_oval_h(inches, tankLength, tankWidth, tankHeight);

  std::cout << "Inches of air: " << airInches << std::endl;
  std::cout << "Inches of oil: " << inches << std::endl;
  std::cout << "Gallons: " << gallons << std::endl;

  std::cout << "I'm expecting 236, so this is off by: " << 236 - gallons << std::endl;

  return 0;
}