/*
 * Counter.h
 *
 *  Created on: 31 mai 2015
 *      Author: jfellus
 */

#ifndef COUNTER_H_
#define COUNTER_H_

#include <pg.h>

class Counter {
public:
	int start;
	int i;
	OUTPUT(int, i);

	Counter() {
		i = start = 0;
	}

	void init() {
		i = start;
	}

	void process() {
		i++;
	}
};


#endif /* COUNTER_H_ */
