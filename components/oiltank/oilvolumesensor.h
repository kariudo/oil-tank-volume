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
  void dump_config() override;

  float get_setup_priority() const override { return setup_priority::DATA; }

  void set_tank_dimensions(float height, float length, float width) {
      tank_height_ = height;
      tank_length_ = length;
      tank_width_ = width;
  }
  void set_distance_sensor(sensor::Sensor *sensor) {
      distance_sensor_ = sensor;
  }
  void set_fill_percent_sensor(sensor::Sensor *sensor) {
      fill_percent_sensor_ = sensor;
  }
  void set_volume_sensor(sensor::Sensor *sensor) {
      volume_sensor_ = sensor;
  }
  void set_sensor_offset(float offset) {
      sensor_offset_ = offset;
  }
  void set_tank_fill_limit(float limit) {
      tank_fill_limit_ = limit;
  }


 protected:
  sensor::Sensor *volume_sensor_{nullptr};
  sensor::Sensor *fill_percent_sensor_{nullptr};
  sensor::Sensor *distance_sensor_;
  float sensor_offset_;
  float tank_height_;
  float tank_length_;
  float tank_width_;
  float tank_fill_limit_;
};

}  // namespace oiltank
}  // namespace esphome