# Firmware & Bare-Metal Programming Concepts

## 1. What is Firmware?
Firmware acts as a **translator**; it converts logic and algorithms into electrical signals.

### How it Works
* **Initialization:** It sets up the CPU clock, configures pins (Input and Output), and wakes up peripherals.
* **Hardware Control:** It manages the flow of electrons through transistors to toggle pins or read voltages.
* **Resource Management:** It ensures that limited RAM and CPU cycles are used efficiently to maintain real-time performance.

---

## 2. Firmware Libraries and APIs

A **Firmware Library** is a collection of pre-written code that handles common tasks. An **API (Application Programming Interface)** is the "menu" of functions within the Firmware library.

### The Problem: Complexity
Microcontrollers have thousands of 32-bit registers. Manually tracking each one to control a timer or clock is prone to error. We need libraries that provide an **Abstraction Layer** (often called a Hardware Abstraction Layer or HAL) that maps human-readable names to complex memory addresses.

### Why do functions like `digitalWrite()` exist?
To turn on an LED, the microcontroller needs to change specific bits in a specific register.

* **Without API:** You would have to write complex, error-prone code:
    ```c
    *(volatile uint32_t *)0x40021018 |= (1 << 5);
    ```
* **With API:** You write readable, safe code:
    ```c
    digitalWrite(13, HIGH);
    ```

### Why are reusable APIs critical?
If the SoC or chip is changed (e.g., from **STMicroelectronics** to **Texas Instruments**), a well-designed API allows engineers to port their code quickly without rewriting the entire logic from scratch.

---

## 3. What is Bare-Metal Firmware?
**Bare-Metal** means the code is running directly on hardware without an Operating System (OS) or Real-Time Operating System (RTOS) sitting in between.

### Why is no RTOS used?
In many simple programs like a thermometer or a remote control, an RTOS adds unnecessary overhead. An RTOS consumes RAM and CPU cycles to manage tasks. If a program does only one or two things, bare-metal is **faster, smaller, and deterministic**.

---

## 4. Handling Tasks Without an OS
Without an OS to schedule tasks, bare-metal firmware relies on three main concepts:

### A. The Super Loop (Polling)
The code runs in an infinite loop (i.e., `while(1)`). It basically checks if a button is pressed for an action to be executed, acts on it, and moves to the next line.

### B. Interrupts
These are **"hardware-triggered"** events. If a critical signal arrives, the hardware pauses the main loop instantly, runs a small function called an **Interrupt Service Routine (ISR)**, and then returns to where it left off.

### C. Hardware Timers
Instead of an OS clock, the firmware configures hardware counters to trigger events at precise intervals.
<img width="913" height="908" alt="image" src="https://github.com/user-attachments/assets/9e555162-3d22-43bd-9386-95d1d4217781" />
