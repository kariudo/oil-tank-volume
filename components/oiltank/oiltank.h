#pragma once

#include <cmath>

namespace kariudo {
namespace oiltank {

double vol_oval_h(double oh, double tl, double tw, double th);
double vol_cylinder_h(double oh, double tr, double tl);
double vol_rect(double oh, double tl, double tw, double th);

}  // namespace oiltank
}  // namespace kariudo