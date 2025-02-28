#include "dietrich.h"
#include "esphome/core/log.h"

namespace esphome {
namespace dietrich {

static const char *TAG = "dietrich";

static const uint8_t SAMPLE_CMD[10] = {0x02, 0xFE, 0x01, 0x05, 0x08, 0x02, 0x01, 0x69, 0xAB, 0x03};
static const uint8_t COUNTER1_CMD[10] = {0x02, 0xFE, 0x00, 0x05, 0x08, 0x10, 0x1C, 0x98, 0xC2, 0x03};
static const uint8_t COUNTER2_CMD[10] = {0x02, 0xFE, 0x00, 0x05, 0x08, 0x10, 0x1D, 0x59, 0x02, 0x03};

void Dietrich::dump_config() {
    ESP_LOGCONFIG(TAG, "Dietrich component:");
    ESP_LOGCONFIG(TAG, "  Update Interval: %u ms", this->get_update_interval());
}

void Dietrich::getSample() {
    uint8_t readdata[80];
    char str[161];
    // Wyślij żądanie danych bieżących (sample)
    this->write_array(SAMPLE_CMD, sizeof(SAMPLE_CMD));
    delay(250);
    uint8_t n = 0;
    while (this->available()) {
        readdata[n++] = this->read();
    }
    if (readdata[0] == 2 && readdata[1] == 1 && readdata[2] == 254) {
        // Parsowanie odebranych danych
        if (this->flow_temp_sensor_ != nullptr) {
            int16_t raw = (int16_t)(((uint16_t) readdata[8] << 8) | readdata[7]);
            this->flow_temp_sensor_->publish_state(raw * 0.01f);
        }
        if (this->return_temp_sensor_ != nullptr) {
            int16_t raw = (int16_t)(((uint16_t) readdata[10] << 8) | readdata[9]);
            this->return_temp_sensor_->publish_state(raw * 0.01f);
        }
        if (this->dhw_in_temp_sensor_ != nullptr) {
            int16_t raw = (int16_t)(((uint16_t) readdata[12] << 8) | readdata[11]);
            this->dhw_in_temp_sensor_->publish_state(raw * 0.01f);
        }
        if (this->outside_temp_sensor_ != nullptr) {
            int16_t raw = (int16_t)(((uint16_t) readdata[14] << 8) | readdata[13]);
            this->outside_temp_sensor_->publish_state(raw * 0.01f);
        }
        if (this->calorifier_temp_sensor_ != nullptr) {
            int16_t raw = (int16_t)(((uint16_t) readdata[16] << 8) | readdata[15]);
            this->calorifier_temp_sensor_->publish_state(raw * 0.01f);
        }
        if (this->boiler_control_temp_sensor_ != nullptr) {
            int16_t raw = (int16_t)(((uint16_t) readdata[20] << 8) | readdata[19]);
            this->boiler_control_temp_sensor_->publish_state(raw * 0.01f);
        }
        if (this->room_temp_sensor_ != nullptr) {
            int16_t raw = (int16_t)(((uint16_t) readdata[22] << 8) | readdata[21]);
            this->room_temp_sensor_->publish_state(raw * 0.01f);
        }
        if (this->ch_setpoint_sensor_ != nullptr) {
            int16_t raw = (int16_t)(((uint16_t) readdata[24] << 8) | readdata[23]);
            this->ch_setpoint_sensor_->publish_state(raw * 0.01f);
        }
        if (this->dhw_setpoint_sensor_ != nullptr) {
            int16_t raw = (int16_t)(((uint16_t) readdata[26] << 8) | readdata[25]);
            this->dhw_setpoint_sensor_->publish_state(raw * 0.01f);
        }
        if (this->room_temp_setpoint_sensor_ != nullptr) {
            int16_t raw = (int16_t)(((uint16_t) readdata[28] << 8) | readdata[27]);
            this->room_temp_setpoint_sensor_->publish_state(raw * 0.01f);
        }
        if (this->sem_read_all_) {
            if (this->fan_speed_setpoint_sensor_ != nullptr) {
                int16_t raw = (int16_t)(((uint16_t) readdata[30] << 8) | readdata[29]);
                this->fan_speed_setpoint_sensor_->publish_state(raw);
            }
            if (this->fan_speed_sensor_ != nullptr) {
                int16_t raw = (int16_t)(((uint16_t) readdata[32] << 8) | readdata[31]);
                this->fan_speed_sensor_->publish_state(raw);
            }
            if (this->ionisation_current_sensor_ != nullptr) {
                this->ionisation_current_sensor_->publish_state(readdata[33]);
            }
            if (this->internal_setpoint_sensor_ != nullptr) {
                int16_t raw = (int16_t)(((uint16_t) readdata[35] << 8) | readdata[34]);
                this->internal_setpoint_sensor_->publish_state(raw * 0.01f);
            }
            if (this->available_power_sensor_ != nullptr) {
                this->available_power_sensor_->publish_state(readdata[36]);
            }
            if (this->pump_percentage_sensor_ != nullptr) {
                this->pump_percentage_sensor_->publish_state(readdata[37]);
            }
            if (this->desired_max_power_sensor_ != nullptr) {
                this->desired_max_power_sensor_->publish_state(readdata[39]);
            }
            if (this->actual_power_sensor_ != nullptr) {
                this->actual_power_sensor_->publish_state(readdata[40]);
            }
            uint8_t bits = readdata[43];
            if (this->demand_source_bit0_sensor_ != nullptr) {
                this->demand_source_bit0_sensor_->publish_state((bits >> 0) & 0x01);
            }
            if (this->demand_source_bit1_sensor_ != nullptr) {
                this->demand_source_bit1_sensor_->publish_state((bits >> 1) & 0x01);
            }
            if (this->demand_source_bit2_sensor_ != nullptr) {
                this->demand_source_bit2_sensor_->publish_state((bits >> 2) & 0x01);
            }
            if (this->demand_source_bit3_sensor_ != nullptr) {
                this->demand_source_bit3_sensor_->publish_state((bits >> 3) & 0x01);
            }
            if (this->demand_source_bit4_sensor_ != nullptr) {
                this->demand_source_bit4_sensor_->publish_state((bits >> 4) & 0x01);
            }
            if (this->demand_source_bit5_sensor_ != nullptr) {
                this->demand_source_bit5_sensor_->publish_state((bits >> 5) & 0x01);
            }
            if (this->demand_source_bit6_sensor_ != nullptr) {
                this->demand_source_bit6_sensor_->publish_state((bits >> 6) & 0x01);
            }
            if (this->demand_source_bit7_sensor_ != nullptr) {
                this->demand_source_bit7_sensor_->publish_state((bits >> 7) & 0x01);
            }
            bits = readdata[44];
            if (this->input_bit0_sensor_ != nullptr) {
                this->input_bit0_sensor_->publish_state((bits >> 0) & 0x01);
            }
            if (this->input_bit1_sensor_ != nullptr) {
                this->input_bit1_sensor_->publish_state((bits >> 1) & 0x01);
            }
            if (this->input_bit2_sensor_ != nullptr) {
                this->input_bit2_sensor_->publish_state((bits >> 2) & 0x01);
            }
            if (this->input_bit3_sensor_ != nullptr) {
                this->input_bit3_sensor_->publish_state((bits >> 3) & 0x01);
            }
            if (this->input_bit5_sensor_ != nullptr) {
                this->input_bit5_sensor_->publish_state((bits >> 5) & 0x01);
            }
            if (this->input_bit6_sensor_ != nullptr) {
                this->input_bit6_sensor_->publish_state((bits >> 6) & 0x01);
            }
            if (this->input_bit7_sensor_ != nullptr) {
                this->input_bit7_sensor_->publish_state((bits >> 7) & 0x01);
            }
            bits = readdata[45];
            if (this->valve_bit0_sensor_ != nullptr) {
                this->valve_bit0_sensor_->publish_state((bits >> 0) & 0x01);
            }
            if (this->valve_bit2_sensor_ != nullptr) {
                this->valve_bit2_sensor_->publish_state((bits >> 2) & 0x01);
            }
            if (this->valve_bit3_sensor_ != nullptr) {
                this->valve_bit3_sensor_->publish_state((bits >> 3) & 0x01);
            }
            if (this->valve_bit4_sensor_ != nullptr) {
                this->valve_bit4_sensor_->publish_state((bits >> 4) & 0x01);
            }
            if (this->valve_bit6_sensor_ != nullptr) {
                this->valve_bit6_sensor_->publish_state((bits >> 6) & 0x01);
            }
            bits = readdata[46];
            if (this->pump_bit0_sensor_ != nullptr) {
                this->pump_bit0_sensor_->publish_state((bits >> 0) & 0x01);
            }
            if (this->pump_bit1_sensor_ != nullptr) {
                this->pump_bit1_sensor_->publish_state((bits >> 1) & 0x01);
            }
            if (this->pump_bit2_sensor_ != nullptr) {
                this->pump_bit2_sensor_->publish_state((bits >> 2) & 0x01);
            }
            if (this->pump_bit4_sensor_ != nullptr) {
                this->pump_bit4_sensor_->publish_state((bits >> 4) & 0x01);
            }
            if (this->pump_bit7_sensor_ != nullptr) {
                this->pump_bit7_sensor_->publish_state((bits >> 7) & 0x01);
            }
        }
        // Podstawowe wartości statusu (zawsze aktualizowane)
        if (this->state_sensor_ != nullptr) {
            this->state_sensor_->publish_state(readdata[47]);
        }
        if (this->lockout_sensor_ != nullptr) {
            this->lockout_sensor_->publish_state(readdata[48]);
        }
        if (this->blocking_sensor_ != nullptr) {
            this->blocking_sensor_->publish_state(readdata[49]);
        }
        if (this->sub_state_sensor_ != nullptr) {
            this->sub_state_sensor_->publish_state(readdata[50]);
        }
        if (this->sem_read_all_) {
            if (this->hydro_pressure_sensor_ != nullptr) {
                this->hydro_pressure_sensor_->publish_state(readdata[56]);
            }
            uint8_t bits2 = readdata[57];
            if (this->hru_sensor_ != nullptr) {
                // BIT1 (HRU)
                this->hru_sensor_->publish_state((bits2 >> 1) & 0x01);
            }
            if (this->control_temp_sensor_ != nullptr) {
                int16_t raw = (int16_t)(((uint16_t) readdata[59] << 8) | readdata[58]);
                this->control_temp_sensor_->publish_state(raw * 0.01f);
            }
            if (this->dhw_flowrate_sensor_ != nullptr) {
                int16_t raw = (int16_t)(((uint16_t) readdata[61] << 8) | readdata[60]);
                this->dhw_flowrate_sensor_->publish_state(raw * 0.01f);
            }
        }
        this->sem_read_all_ = !this->sem_read_all_;
    } else {
        ESP_LOGD(TAG, "CRC error in sample data");
    }
    // Zapisz dane w formacie heksadecymalnym do logów (debug)
    for (uint8_t i = 0; i < 80; ++i) {
        uint8_t nib1 = (readdata[i] >> 4) & 0x0F;
        uint8_t nib2 = (readdata[i] >> 0) & 0x0F;
        str[i*2]     = (nib1 < 0xA ? '0' + nib1 : 'A' + nib1 - 0xA);
        str[i*2+1]   = (nib2 < 0xA ? '0' + nib2 : 'A' + nib2 - 0xA);
    }
    str[80*2] = '\0';
    ESP_LOGD(TAG, "sample data: %s", str);
}

void Dietrich::getCounter() {
    uint8_t readdata[28];
    char str[57];
    // Wyślij pierwsze żądanie danych licznikowych (counter1)
    this->write_array(COUNTER1_CMD, sizeof(COUNTER1_CMD));
    delay(150);
    uint8_t n = 0;
    while (this->available()) {
        readdata[n++] = this->read();
    }
    if (readdata[0] == 2 && readdata[1] == 65 && readdata[2] == 6) {
        if (this->hours_run_pump_sensor_ != nullptr) {
            uint16_t raw = ((uint16_t) readdata[12] << 8) | readdata[13];
            this->hours_run_pump_sensor_->publish_state(raw * 2);
        }
        if (this->hours_run_3way_sensor_ != nullptr) {
            uint16_t raw = ((uint16_t) readdata[14] << 8) | readdata[15];
            this->hours_run_3way_sensor_->publish_state(raw * 2);
        }
        if (this->hours_run_ch_sensor_ != nullptr) {
            uint16_t raw = ((uint16_t) readdata[16] << 8) | readdata[17];
            this->hours_run_ch_sensor_->publish_state(raw * 2);
        }
        if (this->hours_run_dhw_sensor_ != nullptr) {
            uint16_t raw = ((uint16_t) readdata[18] << 8) | readdata[19];
            this->hours_run_dhw_sensor_->publish_state(raw);
        }
        if (this->power_supply_avail_hours_sensor_ != nullptr) {
            uint16_t raw = ((uint16_t) readdata[20] << 8) | readdata[21];
            this->power_supply_avail_hours_sensor_->publish_state(raw * 2);
        }
    } else {
        ESP_LOGD(TAG, "CRC error in counter1 data");
    }
    // Zaloguj surowe dane counter1 (hex)
    for (uint8_t i = 0; i < 28; ++i) {
        uint8_t nib1 = (readdata[i] >> 4) & 0x0F;
        uint8_t nib2 = (readdata[i] >> 0) & 0x0F;
        str[i*2]     = (nib1 < 0xA ? '0' + nib1 : 'A' + nib1 - 0xA);
        str[i*2+1]   = (nib2 < 0xA ? '0' + nib2 : 'A' + nib2 - 0xA);
    }
    str[28*2] = '\0';
    ESP_LOGD(TAG, "counter1 data: %s", str);
    // Wyślij drugie żądanie danych licznikowych (counter2)
    this->write_array(COUNTER2_CMD, sizeof(COUNTER2_CMD));
    delay(150);
    n = 0;
    while (this->available()) {
        readdata[n++] = this->read();
    }
    if (readdata[0] == 2 && readdata[1] == 65 && readdata[2] == 6) {
        if (this->pump_starts_sensor_ != nullptr) {
            uint16_t raw = ((uint16_t) readdata[6] << 8) | readdata[7];
            this->pump_starts_sensor_->publish_state(raw * 8);
        }
        if (this->number_of_3way_valve_cycles_sensor_ != nullptr) {
            uint16_t raw = ((uint16_t) readdata[8] << 8) | readdata[9];
            this->number_of_3way_valve_cycles_sensor_->publish_state(raw * 8);
        }
        if (this->burner_start_dhw_sensor_ != nullptr) {
            uint16_t raw = ((uint16_t) readdata[10] << 8) | readdata[11];
            this->burner_start_dhw_sensor_->publish_state(raw * 8);
        }
        if (this->total_burner_start_sensor_ != nullptr) {
            uint16_t raw = ((uint16_t) readdata[12] << 8) | readdata[13];
            this->total_burner_start_sensor_->publish_state(raw * 8);
        }
        if (this->failed_burner_start_sensor_ != nullptr) {
            uint16_t raw = ((uint16_t) readdata[14] << 8) | readdata[15];
            this->failed_burner_start_sensor_->publish_state(raw);
        }
        if (this->number_flame_loss_sensor_ != nullptr) {
            uint16_t raw = ((uint16_t) readdata[16] << 8) | readdata[17];
            this->number_flame_loss_sensor_->publish_state(raw);
        }
    } else {
        ESP_LOGD(TAG, "CRC error in counter2 data");
    }
    // Zaloguj surowe dane counter2 (hex)
    for (uint8_t i = 0; i < 28; ++i) {
        uint8_t nib1 = (readdata[i] >> 4) & 0x0F;
        uint8_t nib2 = (readdata[i] >> 0) & 0x0F;
        str[i*2]     = (nib1 < 0xA ? '0' + nib1 : 'A' + nib1 - 0xA);
        str[i*2+1]   = (nib2 < 0xA ? '0' + nib2 : 'A' + nib2 - 0xA);
    }
    str[28*2] = '\0';
    ESP_LOGD(TAG, "counter2 data: %s", str);
}

void Dietrich::update() {
    if (this->sem_reading_data_) {
        return;
    }
    this->sem_reading_data_ = true;
    this->counter_timer_++;
    if (this->counter_timer_ >= 8) {
        this->counter_timer_ = 0;
        this->getCounter();
    } else {
        this->getSample();
    }
    this->sem_reading_data_ = false;
}

}  // namespace dietrich
}  // namespace esphome
