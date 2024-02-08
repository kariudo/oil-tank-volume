#include "esphome/core/component.h"
#include "esphome/core/helpers.h"
#include "esphome/core/log.h"
#include "esphome/components/sensor/sensor.h"

#include "oiltank.h"
#include "oilvolumesensor.h"

namespace esphome {
namespace oiltank {

static const char *TAG = "oiltank.sensor";

void OilTankComponent::setup() {}

void OilTankComponent::update() {
  float distance_reading = this->distance_sensor->get_state();
  // Get the ID of the ultrasonic sensor
  ESP_LOGI(TAG, "Distance Sensor: %s", this->distance_sensor->get_name());
  ESP_LOGI(TAG, "Distance Sensor State: %f", distance_reading);

  // TODO Re:enable this when everything isnt broken
  // // Calculate the volume in gallons
  // float volume = kariudo::oiltank::vol_oval_h(distance_reading - this->sensor_offset, this->tank_length, this->tank_width, this->tank_height);
  // // Publish the state
  // this->publish_state(volume);
}


}  // namespace oiltank
}  // namespace esphome