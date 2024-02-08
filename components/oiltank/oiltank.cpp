#include <cmath>
#include <iostream>
#include "oiltank.h"
namespace kariudo {
namespace oiltank {

/**
 * Calculate the volume of an oval-shaped object with a hole through it, given the outer height, total length, total width, and hole height.
 *
 * @param oh the oil height in inches
 * @param tl the tank length
 * @param tw the tank width
 * @param th the tank height
 *
 * @return the volume of the oval-shaped object with a hole through it
 *
 * @throws None
 */
double vol_oval_h(double oh, double tl, double tw, double th) {
  if (tl < 0 || tw < 0 || th < 0 || tw < th) {
    return 0;
  }
  double tr = th / 2;
  double mw = tw - th;

  return vol_cylinder_h(oh, tr, tl) + vol_rect(oh, tl, mw, th);
}

/**
 * Calculate the volume of a cylinder with a horizontal orientation.
 *
 * @param oh the height of the liquid in the cylinder
 * @param tr the radius of the cylinder
 * @param tl the length of the cylinder
 *
 * @return the volume of liquid in gallons
 *
 * @throws None
 */
double vol_cylinder_h(double oh, double tr, double tl) {
  if (tr < 0 || tl < 0) {
    return 0;
  }
  double depth = 2 * tr - oh;
  double gallons = 0;
  double cuInGal = 231;
  if (oh >= (tr * 2)) {
    gallons = M_PI * tr * tr * tl / cuInGal;
  } else if (oh > tr) {
    gallons = (tr * tr) * std::acos((tr - depth) / tr) - (tr - depth) * std::sqrt((2 * tr * depth) - (depth * depth));
    gallons = (tr * tr) * M_PI - gallons;
    gallons = gallons * tl / cuInGal;
  } else {
    gallons = (tr * tr) * std::acos((tr - oh) / tr) - (tr - oh) * std::sqrt((2 * tr * oh) - (oh * oh));
    gallons = gallons * tl / cuInGal;
  }
  return gallons;
}

/**
 * Calculates the volume of a rectangular object.
 *
 * @param oh the height of the object
 * @param tl the length of the object
 * @param tw the width of the object
 * @param th the maximum height of the object
 *
 * @return the volume of the rectangular object
 *
 * @throws None
 */
double vol_rect(double oh, double tl, double tw, double th) {
  if (tl < 0 || tw < 0 || th < 0) {
    return 0;
  }
  oh = std::min(oh, th);
  return std::max(tl * tw * oh / 231, 0.0);
}

}  // namespace oiltank
}  // namespace kariudo