/*
 * FPS.h
 *
 *  Created on: 17 mai 2015
 *      Author: jfellus
 */

#ifndef FPS_H_
#define FPS_H_

#include <pg.h>
#include <sys/time.h>

class FPS {
private:
	struct timeval last;
public:
	FPS() {}

	void init() {
		gettimeofday(&last, NULL);
	}

	void process() {
		struct timeval t;
		gettimeofday(&t, NULL);
		float ms = (t.tv_sec-last.tv_sec)*1000.0+(t.tv_usec-last.tv_usec)/1000.0;
		printf("FPS = %.2f\n", 1000.0/ms);
		last = t;
	}
};



#endif /* FPS_H_ */
