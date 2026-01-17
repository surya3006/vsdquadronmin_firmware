UNDERSTANDING OF TASK_1
GPIO_H: It is a header file, it act as library or it act as a blueprint which tells main function what tools are available with revelaling complex details of hardware.
	Header Guard (ifndef GPIO_H .. #endif): 
	-> Concept: These line prevents compiler from including the same file twice 
	Macros (#define GPIO_OUTPUT 1, #define GPIO_INPUT 0): 
	->Concept: This is use to define hardcoded value which maps the value to readable name which tells about the functionality of value.
	Function Prototype (void gpio_init ..):
	->Concept: This tells compiler that this function exists somewhere, and allows main function to call them even though actual code is in different file

GPIO_C: It is a source or driver file, this file contains the real implementation
	1. gpio_init: This function enables LED or Button signal for the specific port and set specific bits in a "Direction Register" to configure pin as Input as Output.
	2. gpio_write: This would write 1 (High Voltage) or 0 (Low Voltage) to an "Output Data Register".
	3. gpio_read: This would read the status of an "Input Data Register" to see if a button is pressed or not.  

MAIN_C: It is a Application Program. This is where the user behavior is defined
	1. "#include gpio.h":  This connects the application to a custom library.
	2. "gpio_write(LED_PIN, 1): Turn the LED ON.
	3. "int button_state = gpio_read(BTN_PIN)" : Check the button status.
	4. "gpio_write(LED_PIN, 0)": This would turn the LED OFF.

### Step 1: Build the Code

From inside the `task1` directory, run:

```bash
gcc main.c gpio.c -o task1_demo
````

---

### Step 2: Run the Program

```bash
./task1_demo
```

---

