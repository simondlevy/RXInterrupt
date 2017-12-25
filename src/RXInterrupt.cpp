/*
RXInterrupt.cpp Interrupt-driven RC receiver handling for Arduino

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

#include <Arduino.h>

static volatile unsigned long ulStartPeriods[8]; 
static volatile boolean bNewChanSignals[8]; 
static volatile int nChanIns[8]; 
static int nPins[8];

static void isrService(int off)
{
  int pin = nPins[off];

  noInterrupts();

  if(digitalRead(pin) == HIGH) { 

      ulStartPeriods[off] = micros();
  }

  else if (ulStartPeriods[off] && !bNewChanSignals[off])  {

      nChanIns[off] = (int)(micros() - ulStartPeriods[off]);
      ulStartPeriods[off] = 0;
      bNewChanSignals[off] = true;
  }
  
  
  interrupts();
}

static void isrService1()
{
  isrService(0);
}

static void isrService2()
{
  isrService(1);
}

static void isrService3()
{
  isrService(2);
}

static void isrService4()
{
  isrService(3);
}

static void isrService5()
{
  isrService(4);
}

static void isrService6()
{
  isrService(5);
}

static void isrService7()
{
  isrService(6);
}

static void isrService8()
{
  isrService(7);
}

static void initChannel(void (*isrFun)(), int * pins, int chan, int nchans)
{
    if (chan >= nchans) return;
  
    int pin = pins[chan];
  
    ulStartPeriods[chan] = 0;
    bNewChanSignals[chan] = false;    
    nPins[chan] = pin;

    pinMode(pin, INPUT); 
    // For Due and Teensy, using just the raw pin number is okay
    // but for most other Arduino microcontrollers, wrapping it
    // in digitalPinToInterrupt will translate the pin to the 
    // external interrupt vector.
    attachInterrupt(digitalPinToInterrupt(pin), isrFun, CHANGE);
}

static void updateChannel(int off)
{
  bNewChanSignals[off] = false;
}

#include <RXInterrupt.h>

void initChannels(int * pins, int nchans)
{
  initChannel(isrService1, pins, 0, nchans);
  initChannel(isrService2, pins, 1, nchans);
  initChannel(isrService3, pins, 2, nchans);
  initChannel(isrService4, pins, 3, nchans);
  initChannel(isrService5, pins, 4, nchans);
  initChannel(isrService6, pins, 5, nchans);
  initChannel(isrService7, pins, 6, nchans);
  initChannel(isrService8, pins, 7, nchans);
}

void updateChannels(short * values, int nchans)
{
  for (int k=0; k<nchans; ++k) {
    updateChannel(k);
  }

  for (int k=0; k<nchans; ++k) {
    values[k] = nChanIns[k];
  }
}
