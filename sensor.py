import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import sensor, uart
from esphome.const import (
  CONF_ID,
  UNIT_CELSIUS,
  UNIT_PERCENT,
  ICON_EMPTY,
  DEVICE_CLASS_TEMPERATURE,
  DEVICE_CLASS_PRESSURE,
  DEVICE_CLASS_EMPTY,
)

DEPENDENCIES = ["uart"]

# Utworzenie przestrzeni nazw i klasy komponentu Dietrich
dietrich_ns = cg.esphome_ns.namespace("dietrich")
Dietrich = dietrich_ns.class_("Dietrich", cg.PollingComponent, uart.UARTDevice)

# Definicja schematu konfiguracji z wykorzystaniem keyword arguments dla sensor_schema
CONFIG_SCHEMA = cv.Schema({
  cv.GenerateID(): cv.declare_id(Dietrich),
  cv.Optional("flow_temp"): sensor.sensor_schema(
      unit_of_measurement=UNIT_CELSIUS,
      icon=ICON_EMPTY,
      accuracy_decimals=2,
      device_class=DEVICE_CLASS_TEMPERATURE
  ),
  cv.Optional("return_temp"): sensor.sensor_schema(
      unit_of_measurement=UNIT_CELSIUS,
      icon=ICON_EMPTY,
      accuracy_decimals=2,
      device_class=DEVICE_CLASS_TEMPERATURE
  ),
  cv.Optional("outside_temp"): sensor.sensor_schema(
      unit_of_measurement=UNIT_CELSIUS,
      icon=ICON_EMPTY,
      accuracy_decimals=2,
      device_class=DEVICE_CLASS_TEMPERATURE
  ),
  cv.Optional("calorifier_temp"): sensor.sensor_schema(
      unit_of_measurement=UNIT_CELSIUS,
      icon=ICON_EMPTY,
      accuracy_decimals=2,
      device_class=DEVICE_CLASS_TEMPERATURE
  ),
  cv.Optional("boiler_control_temp"): sensor.sensor_schema(
      unit_of_measurement=UNIT_CELSIUS,
      icon=ICON_EMPTY,
      accuracy_decimals=2,
      device_class=DEVICE_CLASS_TEMPERATURE
  ),
  cv.Optional("room_temp"): sensor.sensor_schema(
      unit_of_measurement=UNIT_CELSIUS,
      icon=ICON_EMPTY,
      accuracy_decimals=2,
      device_class=DEVICE_CLASS_TEMPERATURE
  ),
  cv.Optional("ch_setpoint"): sensor.sensor_schema(
      unit_of_measurement=UNIT_CELSIUS,
      icon=ICON_EMPTY,
      accuracy_decimals=2,
      device_class=DEVICE_CLASS_TEMPERATURE
  ),
  cv.Optional("dhw_setpoint"): sensor.sensor_schema(
      unit_of_measurement=UNIT_CELSIUS,
      icon=ICON_EMPTY,
      accuracy_decimals=2,
      device_class=DEVICE_CLASS_TEMPERATURE
  ),
  cv.Optional("room_temp_setpoint"): sensor.sensor_schema(
      unit_of_measurement=UNIT_CELSIUS,
      icon=ICON_EMPTY,
      accuracy_decimals=2,
      device_class=DEVICE_CLASS_TEMPERATURE
  ),
  cv.Optional("fan_speed_setpoint"): sensor.sensor_schema(
      unit_of_measurement="rpm",
      icon=ICON_EMPTY,
      accuracy_decimals=0,
      device_class=DEVICE_CLASS_EMPTY
  ),
  cv.Optional("fan_speed"): sensor.sensor_schema(
      unit_of_measurement="rpm",
      icon=ICON_EMPTY,
      accuracy_decimals=0,
      device_class=DEVICE_CLASS_EMPTY
  ),
  cv.Optional("ionisation_current"): sensor.sensor_schema(
      unit_of_measurement="µA",
      icon=ICON_EMPTY,
      accuracy_decimals=1,
      device_class=DEVICE_CLASS_EMPTY
  ),
  cv.Optional("internal_setpoint"): sensor.sensor_schema(
      unit_of_measurement=UNIT_PERCENT,
      icon=ICON_EMPTY,
      accuracy_decimals=0,
      device_class=DEVICE_CLASS_EMPTY
  ),
  cv.Optional("available_power"): sensor.sensor_schema(
      unit_of_measurement=UNIT_PERCENT,
      icon=ICON_EMPTY,
      accuracy_decimals=0,
      device_class=DEVICE_CLASS_EMPTY
  ),
  cv.Optional("pump_percentage"): sensor.sensor_schema(
      unit_of_measurement=UNIT_PERCENT,
      icon=ICON_EMPTY,
      accuracy_decimals=0,
      device_class=DEVICE_CLASS_EMPTY
  ),
  cv.Optional("desired_max_power"): sensor.sensor_schema(
      unit_of_measurement=UNIT_PERCENT,
      icon=ICON_EMPTY,
      accuracy_decimals=0,
      device_class=DEVICE_CLASS_EMPTY
  ),
  cv.Optional("actual_power"): sensor.sensor_schema(
      unit_of_measurement=UNIT_PERCENT,
      icon=ICON_EMPTY,
      accuracy_decimals=0,
      device_class=DEVICE_CLASS_EMPTY
  ),
  # Statusy, bity i inne sygnały
  cv.Optional("demand_source_bit0"): sensor.sensor_schema(
      unit_of_measurement="",
      icon=ICON_EMPTY,
      accuracy_decimals=0,
      device_class=DEVICE_CLASS_EMPTY
  ),
  cv.Optional("demand_source_bit1"): sensor.sensor_schema(
      unit_of_measurement="",
      icon=ICON_EMPTY,
      accuracy_decimals=0,
      device_class=DEVICE_CLASS_EMPTY
  ),
  cv.Optional("demand_source_bit2"): sensor.sensor_schema(
      unit_of_measurement="",
      icon=ICON_EMPTY,
      accuracy_decimals=0,
      device_class=DEVICE_CLASS_EMPTY
  ),
  cv.Optional("demand_source_bit3"): sensor.sensor_schema(
      unit_of_measurement="",
      icon=ICON_EMPTY,
      accuracy_decimals=0,
      device_class=DEVICE_CLASS_EMPTY
  ),
  cv.Optional("demand_source_bit4"): sensor.sensor_schema(
      unit_of_measurement="",
      icon=ICON_EMPTY,
      accuracy_decimals=0,
      device_class=DEVICE_CLASS_EMPTY
  ),
  cv.Optional("demand_source_bit5"): sensor.sensor_schema(
      unit_of_measurement="",
      icon=ICON_EMPTY,
      accuracy_decimals=0,
      device_class=DEVICE_CLASS_EMPTY
  ),
  cv.Optional("demand_source_bit6"): sensor.sensor_schema(
      unit_of_measurement="",
      icon=ICON_EMPTY,
      accuracy_decimals=0,
      device_class=DEVICE_CLASS_EMPTY
  ),
  cv.Optional("demand_source_bit7"): sensor.sensor_schema(
      unit_of_measurement="",
      icon=ICON_EMPTY,
      accuracy_decimals=0,
      device_class=DEVICE_CLASS_EMPTY
  ),
  cv.Optional("state"): sensor.sensor_schema(
      unit_of_measurement="",
      icon=ICON_EMPTY,
      accuracy_decimals=0,
      device_class=DEVICE_CLASS_EMPTY
  ),
  cv.Optional("sub_state"): sensor.sensor_schema(
      unit_of_measurement="",
      icon=ICON_EMPTY,
      accuracy_decimals=0,
      device_class=DEVICE_CLASS_EMPTY
  ),
  cv.Optional("lockout"): sensor.sensor_schema(
      unit_of_measurement="",
      icon=ICON_EMPTY,
      accuracy_decimals=0,
      device_class=DEVICE_CLASS_EMPTY
  ),
  cv.Optional("blocking"): sensor.sensor_schema(
      unit_of_measurement="",
      icon=ICON_EMPTY,
      accuracy_decimals=0,
      device_class=DEVICE_CLASS_EMPTY
  ),
  cv.Optional("hydro_pressure"): sensor.sensor_schema(
      unit_of_measurement="bar",
      icon=ICON_EMPTY,
      accuracy_decimals=2,
      device_class=DEVICE_CLASS_PRESSURE
  ),
  cv.Optional("control_temp"): sensor.sensor_schema(
      unit_of_measurement=UNIT_CELSIUS,
      icon=ICON_EMPTY,
      accuracy_decimals=2,
      device_class=DEVICE_CLASS_TEMPERATURE
  ),
  cv.Optional("dhw_flowrate"): sensor.sensor_schema(
      unit_of_measurement="l/m",
      icon=ICON_EMPTY,
      accuracy_decimals=0,
      device_class=DEVICE_CLASS_EMPTY
  ),
  cv.Optional("hours_run_pump"): sensor.sensor_schema(
      unit_of_measurement="h",
      icon=ICON_EMPTY,
      accuracy_decimals=0,
      device_class=DEVICE_CLASS_EMPTY
  ),
  cv.Optional("hours_run_3way"): sensor.sensor_schema(
      unit_of_measurement="h",
      icon=ICON_EMPTY,
      accuracy_decimals=0,
      device_class=DEVICE_CLASS_EMPTY
  ),
  cv.Optional("hours_run_ch"): sensor.sensor_schema(
      unit_of_measurement="h",
      icon=ICON_EMPTY,
      accuracy_decimals=0,
      device_class=DEVICE_CLASS_EMPTY
  ),
  cv.Optional("hours_run_dhw"): sensor.sensor_schema(
      unit_of_measurement="h",
      icon=ICON_EMPTY,
      accuracy_decimals=0,
      device_class=DEVICE_CLASS_EMPTY
  ),
  cv.Optional("power_supply_avail_hours"): sensor.sensor_schema(
      unit_of_measurement="h",
      icon=ICON_EMPTY,
      accuracy_decimals=0,
      device_class=DEVICE_CLASS_EMPTY
  ),
  cv.Optional("pump_starts"): sensor.sensor_schema(
      unit_of_measurement="",
      icon=ICON_EMPTY,
      accuracy_decimals=0,
      device_class=DEVICE_CLASS_EMPTY
  ),
  cv.Optional("number_of_3way_valve_cycles"): sensor.sensor_schema(
      unit_of_measurement="",
      icon=ICON_EMPTY,
      accuracy_decimals=0,
      device_class=DEVICE_CLASS_EMPTY
  ),
  cv.Optional("burner_start_dhw"): sensor.sensor_schema(
      unit_of_measurement="",
      icon=ICON_EMPTY,
      accuracy_decimals=0,
      device_class=DEVICE_CLASS_EMPTY
  ),
  cv.Optional("total_burner_start"): sensor.sensor_schema(
      unit_of_measurement="",
      icon=ICON_EMPTY,
      accuracy_decimals=0,
      device_class=DEVICE_CLASS_EMPTY
  ),
  cv.Optional("failed_burner_start"): sensor.sensor_schema(
      unit_of_measurement="",
      icon=ICON_EMPTY,
      accuracy_decimals=0,
      device_class=DEVICE_CLASS_EMPTY
  ),
  cv.Optional("number_flame_loss"): sensor.sensor_schema(
      unit_of_measurement="",
      icon=ICON_EMPTY,
      accuracy_decimals=0,
      device_class=DEVICE_CLASS_EMPTY
  ),
}).extend(cv.polling_component_schema("15s")).extend(uart.UART_DEVICE_SCHEMA)

async def to_code(config):
  var = cg.new_Pvariable(config[CONF_ID])
  await cg.register_component(var, config)
  await uart.register_uart_device(var, config)
  
  if "flow_temp" in config:
    sens = await sensor.new_sensor(config["flow_temp"])
    cg.add(var.set_flow_temp_sensor(sens))
  if "return_temp" in config:
    sens = await sensor.new_sensor(config["return_temp"])
    cg.add(var.set_return_temp_sensor(sens))
  if "outside_temp" in config:
    sens = await sensor.new_sensor(config["outside_temp"])
    cg.add(var.set_outside_temp_sensor(sens))
  if "calorifier_temp" in config:
    sens = await sensor.new_sensor(config["calorifier_temp"])
    cg.add(var.set_calorifier_temp_sensor(sens))
  if "boiler_control_temp" in config:
    sens = await sensor.new_sensor(config["boiler_control_temp"])
    cg.add(var.set_boiler_control_temp_sensor(sens))
  if "room_temp" in config:
    sens = await sensor.new_sensor(config["room_temp"])
    cg.add(var.set_room_temp_sensor(sens))
  if "ch_setpoint" in config:
    sens = await sensor.new_sensor(config["ch_setpoint"])
    cg.add(var.set_ch_setpoint_sensor(sens))
  if "dhw_setpoint" in config:
    sens = await sensor.new_sensor(config["dhw_setpoint"])
    cg.add(var.set_dhw_setpoint_sensor(sens))
  if "room_temp_setpoint" in config:
    sens = await sensor.new_sensor(config["room_temp_setpoint"])
    cg.add(var.set_room_temp_setpoint_sensor(sens))
  if "fan_speed_setpoint" in config:
    sens = await sensor.new_sensor(config["fan_speed_setpoint"])
    cg.add(var.set_fan_speed_setpoint_sensor(sens))
  if "fan_speed" in config:
    sens = await sensor.new_sensor(config["fan_speed"])
    cg.add(var.set_fan_speed_sensor(sens))
  if "ionisation_current" in config:
    sens = await sensor.new_sensor(config["ionisation_current"])
    cg.add(var.set_ionisation_current_sensor(sens))
  if "internal_setpoint" in config:
    sens = await sensor.new_sensor(config["internal_setpoint"])
    cg.add(var.set_internal_setpoint_sensor(sens))
  if "available_power" in config:
    sens = await sensor.new_sensor(config["available_power"])
    cg.add(var.set_available_power_sensor(sens))
  if "pump_percentage" in config:
    sens = await sensor.new_sensor(config["pump_percentage"])
    cg.add(var.set_pump_percentage_sensor(sens))
  if "desired_max_power" in config:
    sens = await sensor.new_sensor(config["desired_max_power"])
    cg.add(var.set_desired_max_power_sensor(sens))
  if "actual_power" in config:
    sens = await sensor.new_sensor(config["actual_power"])
    cg.add(var.set_actual_power_sensor(sens))
  if "demand_source_bit0" in config:
    sens = await sensor.new_sensor(config["demand_source_bit0"])
    cg.add(var.set_demand_source_bit0_sensor(sens))
  if "demand_source_bit1" in config:
    sens = await sensor.new_sensor(config["demand_source_bit1"])
    cg.add(var.set_demand_source_bit1_sensor(sens))
  if "demand_source_bit2" in config:
    sens = await sensor.new_sensor(config["demand_source_bit2"])
    cg.add(var.set_demand_source_bit2_sensor(sens))
  if "demand_source_bit3" in config:
    sens = await sensor.new_sensor(config["demand_source_bit3"])
    cg.add(var.set_demand_source_bit3_sensor(sens))
  if "demand_source_bit4" in config:
    sens = await sensor.new_sensor(config["demand_source_bit4"])
    cg.add(var.set_demand_source_bit4_sensor(sens))
  if "demand_source_bit5" in config:
    sens = await sensor.new_sensor(config["demand_source_bit5"])
    cg.add(var.set_demand_source_bit5_sensor(sens))
  if "demand_source_bit6" in config:
    sens = await sensor.new_sensor(config["demand_source_bit6"])
    cg.add(var.set_demand_source_bit6_sensor(sens))
  if "demand_source_bit7" in config:
    sens = await sensor.new_sensor(config["demand_source_bit7"])
    cg.add(var.set_demand_source_bit7_sensor(sens))
  if "state" in config:
    sens = await sensor.new_sensor(config["state"])
    cg.add(var.set_state_sensor(sens))
  if "sub_state" in config:
    sens = await sensor.new_sensor(config["sub_state"])
    cg.add(var.set_sub_state_sensor(sens))
  if "lockout" in config:
    sens = await sensor.new_sensor(config["lockout"])
    cg.add(var.set_lockout_sensor(sens))
  if "blocking" in config:
    sens = await sensor.new_sensor(config["blocking"])
    cg.add(var.set_blocking_sensor(sens))
  if "hydro_pressure" in config:
    sens = await sensor.new_sensor(config["hydro_pressure"])
    cg.add(var.set_hydro_pressure_sensor(sens))
  if "control_temp" in config:
    sens = await sensor.new_sensor(config["control_temp"])
    cg.add(var.set_control_temp_sensor(sens))
  if "dhw_flowrate" in config:
    sens = await sensor.new_sensor(config["dhw_flowrate"])
    cg.add(var.set_dhw_flowrate_sensor(sens))
  if "hours_run_pump" in config:
    sens = await sensor.new_sensor(config["hours_run_pump"])
    cg.add(var.set_hours_run_pump_sensor(sens))
  if "hours_run_3way" in config:
    sens = await sensor.new_sensor(config["hours_run_3way"])
    cg.add(var.set_hours_run_3way_sensor(sens))
  if "hours_run_ch" in config:
    sens = await sensor.new_sensor(config["hours_run_ch"])
    cg.add(var.set_hours_run_ch_sensor(sens))
  if "hours_run_dhw" in config:
    sens = await sensor.new_sensor(config["hours_run_dhw"])
    cg.add(var.set_hours_run_dhw_sensor(sens))
  if "power_supply_avail_hours" in config:
    sens = await sensor.new_sensor(config["power_supply_avail_hours"])
    cg.add(var.set_power_supply_avail_hours_sensor(sens))
  if "pump_starts" in config:
    sens = await sensor.new_sensor(config["pump_starts"])
    cg.add(var.set_pump_starts_sensor(sens))
  if "number_of_3way_valve_cycles" in config:
    sens = await sensor.new_sensor(config["number_of_3way_valve_cycles"])
    cg.add(var.set_number_of_3way_valve_cycles_sensor(sens))
  if "burner_start_dhw" in config:
    sens = await sensor.new_sensor(config["burner_start_dhw"])
    cg.add(var.set_burner_start_dhw_sensor(sens))
  if "total_burner_start" in config:
    sens = await sensor.new_sensor(config["total_burner_start"])
    cg.add(var.set_total_burner_start_sensor(sens))
  if "failed_burner_start" in config:
    sens = await sensor.new_sensor(config["failed_burner_start"])
    cg.add(var.set_failed_burner_start_sensor(sens))
  if "number_flame_loss" in config:
    sens = await sensor.new_sensor(config["number_flame_loss"])
    cg.add(var.set_number_flame_loss_sensor(sens))
