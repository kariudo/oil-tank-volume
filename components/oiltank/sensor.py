import esphome.codegen as cg
from esphome.components import sensor
from esphome.const import (
    CONF_ID,
    UNIT_PERCENT,
    STATE_CLASS_MEASUREMENT,
    DEVICE_CLASS_VOLUME_STORAGE,
)
import esphome.config_validation as cv

CODEOWNERS = ["@kariudo"]
DEPENDENCIES = []

AUTO_LOAD = ["sensor"]

CONF_REMAINING_VOLUME = "remaining_volume"
CONF_TANK_HEIGHT = "tank_height"
CONF_TANK_WIDTH = "tank_width"
CONF_TANK_LENGTH = "tank_length"
CONF_SENSOR_OFFSET = "sensor_offset"
CONF_DISTANCE_SENSOR = "distance_sensor_id"

ICON_STORAGE_TANK = "mdi:storage-tank"
UNIT_GAL = "gal"

oiltank_ns = cg.esphome_ns.namespace("oiltank")
OilTankComponent = oiltank_ns.class_(
    "OilTankComponent", sensor.Sensor, cg.Component
)

CONFIG_SCHEMA = sensor.sensor_schema(OilTankComponent).extend(
        {
            # cv.GenerateID(): cv.declare_id(OilTankComponent),
            
            cv.Optional(CONF_TANK_HEIGHT, default=27.0): cv.positive_float,  # inches
            cv.Optional(CONF_TANK_WIDTH, default=44.0): cv.positive_float,   # inches
            cv.Optional(CONF_TANK_LENGTH, default=60.0): cv.positive_float,  # inches
            cv.Optional(CONF_SENSOR_OFFSET, default=2.0): cv.positive_float, # cm
            cv.Required(CONF_DISTANCE_SENSOR): cv.use_id(sensor.Sensor),     # name of the ultrasonic sensor
            
            # Sensor component config
            cv.Optional(CONF_REMAINING_VOLUME): sensor.sensor_schema(
                OilTankComponent,
                unit_of_measurement=UNIT_GAL,
                icon=ICON_STORAGE_TANK,
                accuracy_decimals=2,
                state_class=STATE_CLASS_MEASUREMENT,
                device_class=DEVICE_CLASS_VOLUME_STORAGE,
            )
        }
    )#.extend(cv.polling_component_schema("60s"))



async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    await cg.register_component(var, config)
    
    if remaining_volume_config := config.get(CONF_REMAINING_VOLUME):
        sens = await sensor.new_sensor(remaining_volume_config)
        cg.add(var.set_volume_sensor(sens))
        
        distsensor = await cg.get_variable(config[CONF_DISTANCE_SENSOR])
        cg.add(var.set_distance_sensor(distsensor))
        
        cg.add(var.set_sensor_offset(config[CONF_SENSOR_OFFSET]))
        cg.add(var.set_tank_dimensions(config[CONF_TANK_HEIGHT], config[CONF_TANK_LENGTH], config[CONF_TANK_WIDTH]))