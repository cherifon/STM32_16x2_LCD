# STM32 with I2C 16x2 LCD

This repository contains example code for interfacing an STM32 microcontroller with a 16x2 LCD display. This project serves as a starting point for using STM32 microcontrollers with LCD displays using the STM32CubeIDE.

## Table of Contents

- [Introduction](#introduction)
- [Hardware Requirements](#hardware-requirements)
- [Software Requirements](#software-requirements)
- [Setup Instructions](#setup-instructions)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)
- [Contact](#contact)

## Introduction

This repository provides example code demonstrating how to interface an STM32 microcontroller with a 16x2 LCD display using the STM32CubeIDE development environment. The libraries used in these examples have been translated from Arduino to STM32 based on the documentation provided with the LCD module, ensuring compatibility and functionality on STM32 microcontrollers.

## Hardware Requirements

To replicate this project, you will need the following hardware components:

- STM32 microcontroller development board (e.g., STM32L4 Discovery)
- [Grove-16x2 LCD](https://wiki.seeedstudio.com/Grove-16x2_LCD_Series/) display module
- Jumper wires for connections

## Software Requirements

- STM32CubeIDE (or any other IDE for STM32 development)
- STM32CubeMX (optional, for configuring pin assignments and clock settings)
- STM32 HAL libraries

## Setup Instructions

1. **Hardware Connections:**
   - Connect the 16x2 LCD display to the STM32 microcontroller according to the pin (I2C) configurations in the provided example code.

2. **Software Setup:**
   - Clone, download or recreate the code of this repository to your local machine.
   - Open the project in STM32CubeIDE.
   - Import the `.ioc` file into STM32CubeMX to configure the necessary peripherals, pins, and clocks.

3. **Build and Flash:**
   - Build the project to ensure there are no errors.
   - Connect your STM32 development board to your computer via USB.
   - Flash the compiled code to the STM32 microcontroller using STM32CubeIDE.

## Usage

Once the code is flashed to your STM32 microcontroller and the connections are correctly set up, the LCD should display the predefined text or information specified in the example code. You can modify the code to customize what is displayed on the LCD.

## Contributing

Contributions are welcome! If you have any improvements or additional features to add, feel free to fork this repository and submit a pull request. Please follow GitHub's guidelines for contributing.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Contact

For questions or suggestions, contact [cherifjebali0301@gmail.com](mailto:cherifjebali0301@gmail.com).
