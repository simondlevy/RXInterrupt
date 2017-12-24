# ArduinoRXInterrupt

2017-12-23 -- I'm going to see if I can adapt this for Arduinos other than the Due. They obviously have less processing power than Due or Teensy, but might work for 1 or 2 channels. ?? The change I see right off hand is that Arduino interupt vector does not correspond with Pin numbers.

Interrupt-driven PWM RC receiver handling for Arduino.  Handles up to eight channels. I have tested it on the Arduino Due with FrSky VD5M and D8R-XP receivers and on the Teensy 3.1 with the VD5M.

To use, clone this folder to your Arduino/libraries folder.
