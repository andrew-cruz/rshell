#ifndef SHELL_H
#define SHELL_H

#include <string>
#include <queue>

using namespace std;

class Shell{
protected:
	string cmdLine;
	queue<Shell*> commands;
public:
	Shell();
	void read();
	void parse();
	virtual void parse(string a) = 0;
	virtual void execute() = 0;
};


#endif
