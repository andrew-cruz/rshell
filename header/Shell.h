#ifndef SHELL_H
#define SHELL_H

#include <vector>

using namespace std;

class Shell {
protected:
	vector<Shell*> cmdLine;
public:
	Shell();
	void read();
	virtual void parse();
	virtual void execute() = 0;
};

#endif
