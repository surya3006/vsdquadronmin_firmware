# CH32V003 UART & GPIO Demo

This project demonstrates basic GPIO input/output and UART communication on the **VSDSquadron Mini** (CH32V003) development board using PlatformIO.

## 🚀 Features
* **Startup Sequence:** Prints consecutive numbers (1 to 10) to the UART terminal on boot to verify communication.
* **Button Input:** Detects a button press on **PD0** (Active Low configuration with internal Pull-Up).
* **LED Control:** Toggles an LED on **PD4** when the button is pressed.
* **UART Feedback:** Sends status messages to the terminal in real-time.

## 🔌 Hardware Connections

| Component | Board Pin | Wiring Details |
| :--- | :--- | :--- |
| **LED** | **PD4** | Anode to PD4, Cathode to GND (via 220Ω-1kΩ resistor). |
| **Button** | **PD0** | One leg to PD0, the other leg to GND. |
| **UART RX** | **PD5** | Connect this to the **RX** pin of your USB-TTL Adapter.* |

> ***Note:** If you are using the VSDSquadron Mini, the onboard USB-C port often handles UART automatically, so no external USB-TTL adapter is usually required.*

## 🛠️ Prerequisites
* **VS Code** with the **PlatformIO** extension installed.
* **Minicom** (for macOS terminal monitoring).
  ```bash
  brew install minicom

## 🔌 How to Build and Run
## Clean project 
pio run --target clean

## Build project
pio run

## Run the project
pio run --target upload

## How to monitor the output on macOS
minicom -D /dev/tty.usbmodem4EAA8F06D36B2 -b 115200