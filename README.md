# ESPHome Dietrich Custom Component

This repository contains a **custom ESPHome component** for integrating the **Dietrich boiler**. It is a fork and update of the original [kakaki/esphome_dietrich](https://github.com/kakaki/esphome_dietrich) repository. Due to changes in the way ESPHome handles custom components **starting from version 2024.12.2**, significant modifications were required to ensure compatibility with the latest releases. This component has been thoroughly updated and tested with **ESPHome 2025.2.1**.

> **Important:** All sensor names and labels in this component are in **Polish**.

---

## Features
- **UART Communication:** Full integration with the Dietrich boiler via UART.  
- **Comprehensive Sensor Support:** Supports all essential sensors as defined in the original configuration.  
- **Updated for ESPHome:** Adapted to the new external components API introduced in ESPHome version 2024.12.2.  
- **Tested Compatibility:** Successfully compiled and tested with ESPHome 2025.2.1.  

---

## Installation
To use this component, add it as an **external component** in your ESPHome YAML configuration. For example:

```yaml
external_components:
  - source:
      type: github
      repository: slusaro2/esphome_dietrich
      revision: main
```

Then include the component in your sensor configuration, for example:

```yaml
sensor:
  - platform: dietrich
    uart_id: uart_bus
    update_interval: 15s
    # Define your sensors here. Sensor names are in Polish.
```

---

## Configuration
A sample configuration file (**kotlownia-piec.yaml**) is provided in this repository. It contains a basic setup with the necessary sensors enabled. Feel free to customize it to suit your needs.

---

## Background
The original repository by kakaki was built for earlier versions of ESPHome. However, starting from **ESPHome version 2024.12.2**, changes in the custom component API required a complete rewrite of the component code. This fork preserves the original functionality while adapting the implementation to meet current ESPHome standards.

---

## Credits
This component was developed with deep research and assistance from **ChatGPT**.

---

## License
This project is released under **The Unlicense**. You are free to use, modify, and distribute this software without restriction.

