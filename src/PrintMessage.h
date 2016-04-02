/*
 * PrintMessage.h
 *
 *  Created on: 9 avr. 2015
 *      Author: jfellus
 */

#ifndef PG_PrintMessage_H_
#define PG_PrintMessage_H_

#include <pg.h>

class PrintMessage {
public:
	std::string msg;
	std::string zob;

	PARAM(std::string, msg, {});

	OUTPUT(std::string, zob);
public:
	PrintMessage() { msg="HELLO WORLD !"; }
	void init() { }
	void process() { DBG(msg); }
	void process(const std::string& msg) { DBG(msg); }

	void process(float i) {DBG(i);}
};


#endif /* PG_PrintMessage_H_ */
