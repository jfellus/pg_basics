/*
 * ReadFileLines.h
 *
 *  Created on: 9 avr. 2015
 *      Author: jfellus
 */

#ifndef READFILELINES_H_
#define READFILELINES_H_

#include <pg.h>
#include <fstream>

class ReadFileLines {
public:
	std::string filename;
	std::ifstream f;
	std::string line;

	OUTPUT(std::string, line);

	void init() {
		if(filename.empty()) ERROR("no filename specified");
		f.open(filename.c_str());
	}

	void process() {
		getline(f,line);
		if(!f.good()) {f.close();f.open(filename.c_str());}
	}
};



#endif /* READFILELINES_H_ */
