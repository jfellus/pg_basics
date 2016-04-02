/*
 * BasicMatrix.h
 *
 *  Created on: 2 juin 2015
 *      Author: jfellus
 */

#ifndef BASICMATRIX_H_
#define BASICMATRIX_H_

#include <pg.h>
#include <matrix.h>

class BasicMatrix {
public:

	size_t n;
	uint w,h;

	Matrix m;
	PARAM(Matrix, m, {});
	inline operator Matrix& () {return m;}
public:

	BasicMatrix() {
		w = h = 0;
		n = 1;
	}

	void init() {
		if(w && h) {n=w*h; m.init(h,w);}
		else {h=1;w=n; m.init(h,w);}
	}

	void process() {	}
};

#endif /* BASICMATRIX_H_ */
