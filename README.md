# Arduino Ultrasonic Proximity Alert System

A smart distance warning system built with Arduino using an ultrasonic sensor, LEDs, and a buzzer. The system measures the distance of nearby objects and gives visual and audio alerts based on proximity.

## Features

- Real-time distance measurement in centimeters and inches
- Green LED for safe distance
- Yellow LED for caution range
- Red LED for danger zone
- Buzzer alert when object is too close
- Live distance data shown in Serial Monitor

## Distance Zones

### Safe Zone
- Greater than 30 cm
- Green LED ON

### Caution Zone
- Between 15 cm and 30 cm
- Yellow LED ON

### Danger Zone
- Less than 15 cm
- Red LED ON
- Buzzer sounds

## Components Used

- Arduino Uno
- Ultrasonic Sensor (HC-SR04 / PING)))
- Red LED
- Yellow LED
- Green LED
- Buzzer
- Breadboard
- Jumper Wires
- Resistors

## Files Included

- `main.ino` → Arduino source code
- `README.md` → Project documentation

## Skills Demonstrated

- Sensor integration
- Embedded systems programming
- Distance measurement using sound waves
- Conditional logic
- Hardware debugging
- Real-time monitoring with Serial Monitor

## Future Improvements

- LCD screen for live distance display
- Adjustable distance thresholds
- Servo-controlled automatic barrier
- Parking assist mode
- Data logging to SD card

## Author

Ziyan Ali  
Aspiring Electrical Engineering and Computer Engineering Student
