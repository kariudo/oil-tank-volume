#pragma once

#include "esphome/core/component.h"
#include "esphome/core/helpers.h"
#include "esphome/components/sensor/sensor.h"

#include "oiltank.h"

namespace esphome {
namespace oiltank {

class OilTankComponent : public sensor::Sensor, public PollingComponent {
 public:
  void update() override;
  void set_tank_dimensions(float height, float length, float width) {
      tank_height = height;
      tank_length = length;
      tank_width = width;
  }
  void set_distance_sensor(Sensor *sensor) {
      distance_sensor = sensor;
  }
  Sensor *get_distance_sensor() {
      return distance_sensor;
  }
  void set_volume_sensor(Sensor *sensor) {
      volume_sensor = sensor;
  }
  Sensor *get_volume_sensor() {
      return volume_sensor;
  }
  void set_sensor_offset(float offset) {
      sensor_offset = offset;
  }
  float get_sensor_offset() {
      return sensor_offset;
  }

 protected:
  Sensor *volume_sensor;
  Sensor *distance_sensor;
  float sensor_offset;
  float tank_height;
  float tank_length;
  float tank_width;
};

}  // namespace oiltank
}  // namespace esphome