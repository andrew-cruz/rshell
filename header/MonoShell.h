#ifndef MONOSHELL_H
#define MONOSHELL_H

#include <stack>
#include <vector>
#include <string>
#include "../header/Shell.h"

class MonoShell : public Shell{
protected:
    stack<Shell*> monoStack;
    vector<string> monoVec;
    string monoCmd;
public:
    MonoShell() {};
    MonoShell(string);
    MonoShell(Shell*);
    //Inherited
    void read();
	void parse();
	bool cont();
	bool getSuccess(int) {return false;};
    virtual void parse(string a) = 0;
	virtual void execute() = 0;

};

#endif
