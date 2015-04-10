/*
 * test.cpp
 *
 *  Created on: 9 avr. 2015
 *      Author: jfellus
 */

#include "Sleep.h"
#include "PrintMessage.h"
#include "ReadFileLines.h"

int main(int argc, char **argv) {
	Sleep s;
	PrintMessage m;
	ReadFileLines f;
	for(uint i=0; i<100; i++) {
		s.process();
		m.process();
	}
}
