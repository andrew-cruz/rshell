#ifndef SHELL_H
#define SHELL_H

#include <string>
#include <queue>

using namespace std;

class Shell{
protected:
	string cmdLine;
	bool success;
	queue<Shell*> commands;
public:
	Shell();
	void read();
	void parse();
	bool cont();
	virtual bool getSuccess(int);
	virtual void getCommand();
	virtual void execute();
	virtual string getNewCmd();
	virtual void parse(string a) = 0;
};


#endif
