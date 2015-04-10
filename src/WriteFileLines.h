/*
 * WriteFileLines.h
 *
 *  Created on: 10 avr. 2015
 *      Author: jfellus
 */

#ifndef WRITEFILELINES_H_
#define WRITEFILELINES_H_

#include <pg.h>
#include <fstream>

class WriteFileLines {
public:
	std::string filename;
	std::ofstream f;

	void init() {
		if(filename.empty()) ERROR("No filename specified");
		f.open(filename.c_str());
	}

	void process(const std::string& s) {
		f << s << "\n";
		f.flush();
	}

};




#endif /* WRITEFILELINES_H_ */
