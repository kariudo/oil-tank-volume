#pragma once

#include "esphome/core/component.h"
#include "esphome/core/helpers.h"
#include "esphome/components/sensor/sensor.h"

#include "oiltank.h"

namespace esphome {
namespace oiltank {

class OilTankComponent : public sensor::Sensor, public PollingComponent {
 public:
  void setup() override;
  void update() override;
  void set_tank_dimensions(float height, float length, float width) {
      tank_height_ = height;
      tank_length_ = length;
      tank_width_ = width;
  }
  void set_distance_sensor(Sensor *sensor) {
      distance_sensor = sensor;
  }
  void set_volume_sensor(Sensor *sensor) {
      volume_sensor_ = sensor;
  }
  void set_sensor_offset(float offset) {
      sensor_offset_ = offset;
  }


 protected:
  Sensor *volume_sensor_;
  Sensor *distance_sensor_;
  float sensor_offset_;
  float tank_height_;
  float tank_length_;
  float tank_width_;
};

}  // namespace oiltank
}  // namespace esphome