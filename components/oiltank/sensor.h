#pragma once

#include "esphome/core/component.h"
#include "esphome/core/helpers.h"
#include "esphome/components/sensor/sensor.h"

#include "oiltank.h"

namespace esphome {
namespace oiltank {

class OilTankSensor : public sensor::Sensor, public PollingComponent {
 public:
  void update() override {
    // Get the ID of the ultrasonic sensor
    const auto sensor_id = esphome::global_esphome->component_by_name(this->sensor_name)->id();
    // Read the sensor's state
    float sensor_value = sensor_id.state;
    // Calculate the volume in gallons
    float volume = oiltank::vol_oval_h(sensor_value, this->tank_length, this->tank_width, this->tank_height);
    // Publish the state
    this->publish_state(volume);
  }
};

}  // namespace oiltank
}  // namespace esphome