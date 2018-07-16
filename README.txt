This project helps to automatically turn off the supply for a particular room or an area. This project used ESP32 Dev Board, an array relay board, a current sensor- ACS712,
a sample high current rated device(Iron box-1000W). 
If a 20Amps current sensor is used, if condition is about 3 Amps
If 5Amps sensor is used, if condition is about 4 Amps
This depends on current sensitivity of the sensor.

The explanation of the code:
Whenever there is no high current rated device connected, the current value is approximately less than 1 or 2 Amps. When a high current rated device is connected,
the current drawn increases. This is indicated by the current sensor. So the supply turns off for about 10 seconds and then again checks whether the device
has been disconnected from the supply or not.This time of checking is 2 seconds. Everything can be changed in the code given. This is very helpful
in places where only low current rated devices are allowed to be connected.

Connections: 
Connect the sensor to the ESP32. Connect the high current rated device to the sensor in series with the supply. Use a relay for performing the 
desired connection. A relay is used to trigger on and off for the device connected.

