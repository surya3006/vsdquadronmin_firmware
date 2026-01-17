# Firmware Task 1: GPIO Driver Simulation

This project demonstrates the architecture of a **Hardware Abstraction Layer (HAL)** in C. It simulates a firmware environment where the Application Layer is separated from the Hardware Driver Layer.

## 📂 Project Structure

### 1. Header File (`gpio.h`)
Acts as the **blueprint** or public interface. It tells the main function what tools are available without revealing the complex details of the hardware.

* **Header Guards (`#ifndef GPIO_H` ...):**
    * *Concept:* Prevents the compiler from including the same file twice, which avoids definition errors.
* **Macros (`#define GPIO_OUTPUT 1`):**
    * *Concept:* Replaces "magic numbers" with readable names (e.g., using `GPIO_OUTPUT` instead of `1`), making the code easier to understand and maintain.
* **Function Prototypes (`void gpio_init...`):**
    * *Concept:* Acts as a promise to the compiler that these functions exist somewhere else. This allows the `main` function to call them even though the actual code is in a different file.

### 2. Driver File (`gpio.c`)
Acts as the **source** or **driver**. This file contains the actual implementation of the hardware logic.

* **`gpio_init`**: Simulates enabling the clock for a specific port and setting bits in a "Direction Register" to configure a pin as Input or Output.
* **`gpio_write`**: Simulates writing a `1` (High Voltage) or `0` (Low Voltage) to an "Output Data Register".
* **`gpio_read`**: Simulates reading the status of an "Input Data Register" to check if an external button is pressed.

### 3. Application Program (`main.c`)
Contains the **high-level user logic**. This file defines the behavior of the device using the tools provided by the driver.

* **`#include "gpio.h"`**: Connects the application to the custom driver library.
* **Logic Flow**:
    1.  Initializes the LED and Button.
    2.  Turns the LED **ON**.
    3.  Reads the status of the Button.
    4.  Turns the LED **OFF**.

---

## 🚀 How to Build and Run

Follow these steps to compile the simulation on your local machine.

### Prerequisites
* GCC Compiler (e.g., MinGW for Windows, or standard GCC on Mac/Linux)

### Step 1: Build the Code
Navigate to the project directory in your terminal and run:

```bash
gcc main.c gpio.c -o task1_demo
./task1_demo

