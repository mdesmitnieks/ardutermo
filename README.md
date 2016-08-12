# ardutermo
Arduino based thermometer using two DS18B20 sensors and 2x16 display

Connection:
RS -------- Arduino pin 12
RW -------- Arduino pin 11
ENABLE ---- Arduino pin 10
LCD 15 ---- Arduino pin 6 (display brightness controled by PWM)
LCD D4 ---- Arduino pin 5
LCD D5 ---- Arduino pin 4
LCD D6 ---- Arduino pin 3
LCD D7 ---- Arduino pin 2
Sensor DQ ---- Arduino pin 8 (4.7K resistor between DQ and +5v)
