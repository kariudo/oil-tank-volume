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
    if (std::isnan(distance_reading)) {
        ESP_LOGE(TAG, "Distance Sensor State: NAN, no state will be published!");
    } else {
      ESP_LOGI(TAG, "Distance Sensor (%s) State: %f, calculating volume.", this->distance_sensor_->get_name(), distance_reading);
      if (this->volume_sensor_ != nullptr) {
        float volume = kariudo::oiltank::vol_oval_h(distance_reading - this->sensor_offset_, this->tank_length_, this->tank_width_, this->tank_height_);
        ESP_LOGI(TAG, "Volume Calculated as: %f, publishing state.", volume);
        this->volume_sensor_->publish_state(volume);
      } else {
        ESP_LOGE(TAG, "Volume Sensor State: NULL, no state will be published!");
      }
    }
  } else {
    ESP_LOGE(TAG, "Distance Sensor State: NULL, no state will be published!");
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