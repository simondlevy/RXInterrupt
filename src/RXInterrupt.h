/*
RXInterrupt.h Interrupt-driven RC receiver handling for Arduino

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

void initChannels(int * pins, int nchans);

void updateChannels(short * values, int nchans);
