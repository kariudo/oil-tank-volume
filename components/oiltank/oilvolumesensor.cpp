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
        ESP_LOGW(TAG, "Distance Sensor State: NAN, no state will be published!");
    } else {
      ESP_LOGI(TAG, "Distance Sensor (%s) State: %f, calculating volume.", this->distance_sensor_->get_name(), distance_reading);
      if (this->volume_sensor_ != nullptr) {
        bool us_cm = this->distance_sensor_->get_unit_of_measurement() == "cm";
        distance_reading = (distance_reading - this->sensor_offset_) * (us_cm ? 0.393701 : 1); // convert cm to inches if needed
        float height_of_oil = this->tank_height_ - distance_reading;
        float volume = kariudo::oiltank::vol_oval_h(height_of_oil, this->tank_length_, this->tank_width_, this->tank_height_);
        ESP_LOGI(TAG, "Volume Calculated as: %f, publishing state.", volume);
        this->volume_sensor_->publish_state(volume);
        float fill_percent = (volume / this->tank_fill_limit_) * 100;
        ESP_LOGI(TAG, "Tank Fill Calculated as: %f (%f/%f), publishing state.", fill_percent, volume, this->tank_fill_limit_);
        this->fill_percent_sensor_->publish_state(fill_percent);
      } else {
        ESP_LOGW(TAG, "Volume Sensor State: NULL, no state will be published!");
      }
    }
  } else {
    ESP_LOGW(TAG, "Distance Sensor State: NULL, no state will be published!");
  }
}

void OilTankComponent::dump_config() {
  ESP_LOGD(TAG, "Oil Tank:");
  LOG_SENSOR("  ", "Volume", this->volume_sensor_);
  LOG_SENSOR("  ", "Distance", this->distance_sensor_);
}

}  // namespace oiltank
}  // namespace esphome