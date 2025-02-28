#pragma once
#include "esphome/core/component.h"
#include "esphome/components/uart/uart.h"
#include "esphome/components/sensor/sensor.h"

namespace esphome {
namespace dietrich {

class Dietrich : public PollingComponent, public uart::UARTDevice {
  public:
    // Settery dla poszczególnych czujników:
    void set_flow_temp_sensor(sensor::Sensor *sensor) { flow_temp_sensor_ = sensor; }
    void set_return_temp_sensor(sensor::Sensor *sensor) { return_temp_sensor_ = sensor; }
    void set_dhw_in_temp_sensor(sensor::Sensor *sensor) { dhw_in_temp_sensor_ = sensor; }
    void set_outside_temp_sensor(sensor::Sensor *sensor) { outside_temp_sensor_ = sensor; }
    void set_calorifier_temp_sensor(sensor::Sensor *sensor) { calorifier_temp_sensor_ = sensor; }
    void set_boiler_control_temp_sensor(sensor::Sensor *sensor) { boiler_control_temp_sensor_ = sensor; }
    void set_room_temp_sensor(sensor::Sensor *sensor) { room_temp_sensor_ = sensor; }
    void set_ch_setpoint_sensor(sensor::Sensor *sensor) { ch_setpoint_sensor_ = sensor; }
    void set_dhw_setpoint_sensor(sensor::Sensor *sensor) { dhw_setpoint_sensor_ = sensor; }
    void set_room_temp_setpoint_sensor(sensor::Sensor *sensor) { room_temp_setpoint_sensor_ = sensor; }
    void set_fan_speed_setpoint_sensor(sensor::Sensor *sensor) { fan_speed_setpoint_sensor_ = sensor; }
    void set_fan_speed_sensor(sensor::Sensor *sensor) { fan_speed_sensor_ = sensor; }
    void set_ionisation_current_sensor(sensor::Sensor *sensor) { ionisation_current_sensor_ = sensor; }
    void set_internal_setpoint_sensor(sensor::Sensor *sensor) { internal_setpoint_sensor_ = sensor; }
    void set_available_power_sensor(sensor::Sensor *sensor) { available_power_sensor_ = sensor; }
    void set_pump_percentage_sensor(sensor::Sensor *sensor) { pump_percentage_sensor_ = sensor; }
    void set_desired_max_power_sensor(sensor::Sensor *sensor) { desired_max_power_sensor_ = sensor; }
    void set_actual_power_sensor(sensor::Sensor *sensor) { actual_power_sensor_ = sensor; }
    void set_demand_source_bit0_sensor(sensor::Sensor *sensor) { demand_source_bit0_sensor_ = sensor; }
    void set_demand_source_bit1_sensor(sensor::Sensor *sensor) { demand_source_bit1_sensor_ = sensor; }
    void set_demand_source_bit2_sensor(sensor::Sensor *sensor) { demand_source_bit2_sensor_ = sensor; }
    void set_demand_source_bit3_sensor(sensor::Sensor *sensor) { demand_source_bit3_sensor_ = sensor; }
    void set_demand_source_bit4_sensor(sensor::Sensor *sensor) { demand_source_bit4_sensor_ = sensor; }
    void set_demand_source_bit5_sensor(sensor::Sensor *sensor) { demand_source_bit5_sensor_ = sensor; }
    void set_demand_source_bit6_sensor(sensor::Sensor *sensor) { demand_source_bit6_sensor_ = sensor; }
    void set_demand_source_bit7_sensor(sensor::Sensor *sensor) { demand_source_bit7_sensor_ = sensor; }
    void set_input_bit0_sensor(sensor::Sensor *sensor) { input_bit0_sensor_ = sensor; }
    void set_input_bit1_sensor(sensor::Sensor *sensor) { input_bit1_sensor_ = sensor; }
    void set_input_bit2_sensor(sensor::Sensor *sensor) { input_bit2_sensor_ = sensor; }
    void set_input_bit3_sensor(sensor::Sensor *sensor) { input_bit3_sensor_ = sensor; }
    void set_input_bit5_sensor(sensor::Sensor *sensor) { input_bit5_sensor_ = sensor; }
    void set_input_bit6_sensor(sensor::Sensor *sensor) { input_bit6_sensor_ = sensor; }
    void set_input_bit7_sensor(sensor::Sensor *sensor) { input_bit7_sensor_ = sensor; }
    void set_valve_bit0_sensor(sensor::Sensor *sensor) { valve_bit0_sensor_ = sensor; }
    void set_valve_bit2_sensor(sensor::Sensor *sensor) { valve_bit2_sensor_ = sensor; }
    void set_valve_bit3_sensor(sensor::Sensor *sensor) { valve_bit3_sensor_ = sensor; }
    void set_valve_bit4_sensor(sensor::Sensor *sensor) { valve_bit4_sensor_ = sensor; }
    void set_valve_bit6_sensor(sensor::Sensor *sensor) { valve_bit6_sensor_ = sensor; }
    void set_pump_bit0_sensor(sensor::Sensor *sensor) { pump_bit0_sensor_ = sensor; }
    void set_pump_bit1_sensor(sensor::Sensor *sensor) { pump_bit1_sensor_ = sensor; }
    void set_pump_bit2_sensor(sensor::Sensor *sensor) { pump_bit2_sensor_ = sensor; }
    void set_pump_bit4_sensor(sensor::Sensor *sensor) { pump_bit4_sensor_ = sensor; }
    void set_pump_bit7_sensor(sensor::Sensor *sensor) { pump_bit7_sensor_ = sensor; }
    void set_state_sensor(sensor::Sensor *sensor) { state_sensor_ = sensor; }
    void set_sub_state_sensor(sensor::Sensor *sensor) { sub_state_sensor_ = sensor; }
    void set_lockout_sensor(sensor::Sensor *sensor) { lockout_sensor_ = sensor; }
    void set_blocking_sensor(sensor::Sensor *sensor) { blocking_sensor_ = sensor; }
    void set_hydro_pressure_sensor(sensor::Sensor *sensor) { hydro_pressure_sensor_ = sensor; }
    void set_hru_sensor(sensor::Sensor *sensor) { hru_sensor_ = sensor; }
    void set_control_temp_sensor(sensor::Sensor *sensor) { control_temp_sensor_ = sensor; }
    void set_dhw_flowrate_sensor(sensor::Sensor *sensor) { dhw_flowrate_sensor_ = sensor; }
    void set_hours_run_pump_sensor(sensor::Sensor *sensor) { hours_run_pump_sensor_ = sensor; }
    void set_hours_run_3way_sensor(sensor::Sensor *sensor) { hours_run_3way_sensor_ = sensor; }
    void set_hours_run_ch_sensor(sensor::Sensor *sensor) { hours_run_ch_sensor_ = sensor; }
    void set_hours_run_dhw_sensor(sensor::Sensor *sensor) { hours_run_dhw_sensor_ = sensor; }
    void set_power_supply_avail_hours_sensor(sensor::Sensor *sensor) { power_supply_avail_hours_sensor_ = sensor; }
    void set_pump_starts_sensor(sensor::Sensor *sensor) { pump_starts_sensor_ = sensor; }
    void set_number_of_3way_valve_cycles_sensor(sensor::Sensor *sensor) { number_of_3way_valve_cycles_sensor_ = sensor; }
    void set_burner_start_dhw_sensor(sensor::Sensor *sensor) { burner_start_dhw_sensor_ = sensor; }
    void set_total_burner_start_sensor(sensor::Sensor *sensor) { total_burner_start_sensor_ = sensor; }
    void set_failed_burner_start_sensor(sensor::Sensor *sensor) { failed_burner_start_sensor_ = sensor; }
    void set_number_flame_loss_sensor(sensor::Sensor *sensor) { number_flame_loss_sensor_ = sensor; }

    void dump_config() override;
    void update() override;

  protected:
    sensor::Sensor *flow_temp_sensor_{nullptr};
    sensor::Sensor *return_temp_sensor_{nullptr};
    sensor::Sensor *dhw_in_temp_sensor_{nullptr};
    sensor::Sensor *outside_temp_sensor_{nullptr};
    sensor::Sensor *calorifier_temp_sensor_{nullptr};
    sensor::Sensor *boiler_control_temp_sensor_{nullptr};
    sensor::Sensor *room_temp_sensor_{nullptr};
    sensor::Sensor *ch_setpoint_sensor_{nullptr};
    sensor::Sensor *dhw_setpoint_sensor_{nullptr};
    sensor::Sensor *room_temp_setpoint_sensor_{nullptr};
    sensor::Sensor *fan_speed_setpoint_sensor_{nullptr};
    sensor::Sensor *fan_speed_sensor_{nullptr};
    sensor::Sensor *ionisation_current_sensor_{nullptr};
    sensor::Sensor *internal_setpoint_sensor_{nullptr};
    sensor::Sensor *available_power_sensor_{nullptr};
    sensor::Sensor *pump_percentage_sensor_{nullptr};
    sensor::Sensor *desired_max_power_sensor_{nullptr};
    sensor::Sensor *actual_power_sensor_{nullptr};
    sensor::Sensor *demand_source_bit0_sensor_{nullptr};
    sensor::Sensor *demand_source_bit1_sensor_{nullptr};
    sensor::Sensor *demand_source_bit2_sensor_{nullptr};
    sensor::Sensor *demand_source_bit3_sensor_{nullptr};
    sensor::Sensor *demand_source_bit4_sensor_{nullptr};
    sensor::Sensor *demand_source_bit5_sensor_{nullptr};
    sensor::Sensor *demand_source_bit6_sensor_{nullptr};
    sensor::Sensor *demand_source_bit7_sensor_{nullptr};
    sensor::Sensor *input_bit0_sensor_{nullptr};
    sensor::Sensor *input_bit1_sensor_{nullptr};
    sensor::Sensor *input_bit2_sensor_{nullptr};
    sensor::Sensor *input_bit3_sensor_{nullptr};
    sensor::Sensor *input_bit5_sensor_{nullptr};
    sensor::Sensor *input_bit6_sensor_{nullptr};
    sensor::Sensor *input_bit7_sensor_{nullptr};
    sensor::Sensor *valve_bit0_sensor_{nullptr};
    sensor::Sensor *valve_bit2_sensor_{nullptr};
    sensor::Sensor *valve_bit3_sensor_{nullptr};
    sensor::Sensor *valve_bit4_sensor_{nullptr};
    sensor::Sensor *valve_bit6_sensor_{nullptr};
    sensor::Sensor *pump_bit0_sensor_{nullptr};
    sensor::Sensor *pump_bit1_sensor_{nullptr};
    sensor::Sensor *pump_bit2_sensor_{nullptr};
    sensor::Sensor *pump_bit4_sensor_{nullptr};
    sensor::Sensor *pump_bit7_sensor_{nullptr};
    sensor::Sensor *state_sensor_{nullptr};
    sensor::Sensor *sub_state_sensor_{nullptr};
    sensor::Sensor *lockout_sensor_{nullptr};
    sensor::Sensor *blocking_sensor_{nullptr};
    sensor::Sensor *hydro_pressure_sensor_{nullptr};
    sensor::Sensor *hru_sensor_{nullptr};
    sensor::Sensor *control_temp_sensor_{nullptr};
    sensor::Sensor *dhw_flowrate_sensor_{nullptr};
    sensor::Sensor *hours_run_pump_sensor_{nullptr};
    sensor::Sensor *hours_run_3way_sensor_{nullptr};
    sensor::Sensor *hours_run_ch_sensor_{nullptr};
    sensor::Sensor *hours_run_dhw_sensor_{nullptr};
    sensor::Sensor *power_supply_avail_hours_sensor_{nullptr};
    sensor::Sensor *pump_starts_sensor_{nullptr};
    sensor::Sensor *number_of_3way_valve_cycles_sensor_{nullptr};
    sensor::Sensor *burner_start_dhw_sensor_{nullptr};
    sensor::Sensor *total_burner_start_sensor_{nullptr};
    sensor::Sensor *failed_burner_start_sensor_{nullptr};
    sensor::Sensor *number_flame_loss_sensor_{nullptr};

    bool sem_reading_data_{false};
    bool sem_read_all_{true};
    uint8_t counter_timer_{99};

    void getSample();
    void getCounter();
};

}  // namespace dietrich
}  // namespace esphome
