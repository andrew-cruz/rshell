#ifndef SHELL_H
#define SHELL_H

#include <vector>
using namspace std;

Class Shell {
protected:
	vector<Shell*> cmdLine;
public:
	void read();
	void parse();
	virtual void execute = 0;
};

#endif 
