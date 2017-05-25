#ifndef DECORATOR_H
#define DECORATOR_H

#include "../header/Shell.h"
#include <stack>

class Decorator : public Shell{
protected:
    Shell* cmdD;
    stack<string> stkCmd;
    stack<Shell*> cmdDec;
    string cmd;
public:
    //Constructor
    Decorator();
    Decorator(string);
    //Inherited
	void read() {};
	bool cont() {return false;};
    bool getSuccess(int) {return false;};
	void getCommand() {};
	void parse(string);
    //Need Implementation by Subclasses
	virtual void parse() = 0;
	virtual void execute() = 0;
};

#endif
