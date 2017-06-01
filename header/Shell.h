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
	bool cont();
	void getCommand();
	virtual void parse(string a) = 0;
	virtual void execute() = 0;
	virtual bool getSuccess(int) = 0;
};


#endif
