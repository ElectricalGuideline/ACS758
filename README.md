ACS758
======

Hi this is Sajid Akhtar Gazi,contributing custom library for ACS758.


An Arduino library to interact with the ACS758 Hall effect-based linear current sensor. Includes DC and RMS AC current measuring. Supports ACS758LCB-050B, ACS758LCB-100B, ACS758KCB-150B, ACS758ECB_200B, ACS758LCB-050U, ACS758LCB-100U, ACS758KCB-150U, ACS758ECB_200U  sensors. Typical applications include motor control, load detection and management, switch mode power supplies, and overcurrent fault protection.

For more information see the datasheet: http://www.allegromicro.com/~/media/Files/Datasheets/ACS758-Datasheet.ashx

Wiring
======
| ACS758 | Arduino |
|:------:|:-------:|
| GND    | GND     |
| OUT    | A1      |
| VCC    | 5V      |

Methods
=======
### Constructor:
### **ACS758(** *ACS758_type* type, *uint8_t* _pin **)**
Constructor has two parameters: sensor model and analog input to which it is connected. Supported models: **ACS758LCB_050B**, **ACS758ECB_200B**, **ACS758LCB_100B**, **ACS758KCB_150B**,**ACS758LCB_050U**, **ACS758ECB_200U**, **ACS758LCB_100U**, **ACS758KCB_150U**

### *float* **getCurrentDC()**
This method reads the value from the current sensor and returns it.

### *float* **getCurrentAC(** *uint16_t* frequency **)**
This method allows you to measure AC voltage. Current frequency is measured in Hz. Method use the Root Mean Square technique for the measurement. The measurement itself takes time of one full period (1second / frequency). RMS method allow us to measure complex signals different from the perfect sine wave.

### *float* **getCurrentAC()**
Does the same as the previous method, but frequency is equal to 50 Hz.

### *int* **calibrate()**
This method reads the current value of the sensor and sets it as a reference point of measurement, and then returns this value. By default, this parameter is equal to half of the maximum value on analog input - 512; however, sometimes this value may vary. It depends on the concrete sensor, power issues etc… It is better to execute this method at the beginning of each program. Note that when performing this method, no current must flow through the sensor, and since this is not always possible - there is the following method:

### *void* **setZeroPoint(** *int* _zero **)**
This method sets the obtained value as a zero point for measurements. You can use the previous method once, in order to find out zero point of your sensor and then use this method in your code.
