# Robotics Dev Board

A simple dev board/shield for robotics experiments with Arduino

## Board layout

![Board Layout](images/devboard_annotated.png)

## Arduino pinout

![Arduino Pin layout](images/arduino-nano-pins.png)

## Power

Can be powered in 3 ways:
1. USB (NOTE: use a thick cable if you are running lots of servos)
1. External 5V connected to 5V and GND
1. External battery 6V to 15V connected to VIN and GND

## Display

Display is a SH1106 IIC display 128x64 pixels.

Use the U8g2 library for easy access, and the U8G2_SH1106_128X64_NONAME_F_HW_I2C class. All relevant examples should work.

A simple 4 port I2C bus is provided at the lower right hand corner, with the correct pinouts for a DiyMore display.

## Servo

## Joystick
