/*

FiveChannelReadout : demo RXInterrupt with five-channel receiver.

Copyright (C) Simon D. Levy 2015

This file is part of RXInterrupt

RXInterrupt is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as 
published by the Free Software Foundation, either version 3 of the 
License, or (at your option) any later version.

RXInterrupt is distributed in the hope that it will be useful,     
but WITHOUT ANY WARRANTY without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
You should have received a copy of the GNU Lesser General Public License 
along with this code.  If not, see <http:#www.gnu.org/licenses/>.
*/

#include <RXInterrupt.h>

void setup()
{
  // Aurduino based on ATmega328P or ATmega168 have external 
  // interupts only on digital pins 2 & 3  
  int pins[2] = {2, 3};

  initChannels(pins, 2);

  Serial.begin(9600);
  Serial.println("Initialized pins 2 & 3");
}
            
void loop()
{
  short values[2];

  updateChannels(values, 2);
  
  Serial.print(values[0]);
  Serial.print(" ");
  Serial.print(values[1]);
  Serial.println();
}
