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
  if (this->distance_sensor_->has_state()) {
    float distance_reading = this->distance_sensor_->get_state();
    // Get the ID of the ultrasonic sensor
    //ESP_LOGI(TAG, "Distance Sensor: %s", this->distance_sensor_->get_name());
    ESP_LOGI(TAG, "Distance Sensor State: %f", distance_reading);
  } else {
    ESP_LOGE(TAG, "Distance Sensor State: NULL");
  }
  // TODO Re:enable this when everything isnt broken
  // // Calculate the volume in gallons
  // // Publish the state
  if (this->volume_sensor_ != nullptr) {
  // float volume = kariudo::oiltank::vol_oval_h(distance_reading - this->sensor_offset, this->tank_length, this->tank_width, this->tank_height);
    float volume = 69.69;
    this->volume_sensor_->publish_state(volume);
  }
}

void OilTankComponent::dump_config() {
  ESP_LOGD(TAG, "Oil Tank:");
  LOG_SENSOR("  ", "Volume", this->volume_sensor_);
  LOG_SENSOR("  ", "Distance", this->distance_sensor_);
  LOG_SENSOR("", "Oil Tank", this);
}

}  // namespace oiltank
}  // namespace esphome