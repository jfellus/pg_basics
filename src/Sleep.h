/*
 * Sleep.h
 *
 *  Created on: 9 avr. 2015
 *      Author: jfellus
 */

#ifndef PG_SLEEP_H_
#define PG_SLEEP_H_

#include <pg.h>

class Sleep {
public:
	size_t us;
public:
	Sleep() { us = 1000000; }
	void init() { }
	void process() { usleep(us); }
};


#endif /* PG_SLEEP_H_ */
