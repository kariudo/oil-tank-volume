#pragma once
#include "esphome/core/component.h"
#include "esphome/core/helpers.h"
#include "esphome/components/sensor/sensor.h"

#include "oiltank.h"
#include "oilvolumesensor.h"

namespace esphome {
namespace oiltank {

static const char *TAG = "oiltank.sensor";

void OilTankComponent::update() override {
  // Get the ID of the ultrasonic sensor
  ESP_LOGI(TAG, "Distance Sensor: %s", this->distance_sensor->get_name());
  ESP_LOGI(TAG, "Distance Sensor State: %f", this->distance_sensor->get_state());
  // Calculate the volume in gallons
  float volume = oiltank::vol_oval_h(this->distance_sensor->get_state(), this->tank_length, this->tank_width, this->tank_height);
  // Publish the state
  this->publish_state(volume);
}


}  // namespace oiltank
}  // namespace esphome