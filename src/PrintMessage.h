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
public:
	PrintMessage() { msg="HELLO WORLD !"; }
	void init() { }
	void process() { DBG(msg); }
	void process(const std::string& msg) { DBG(msg); }
};


#endif /* PG_PrintMessage_H_ */
