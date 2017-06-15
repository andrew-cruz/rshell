#ifndef SHELL_H
#define SHELL_H

#include <string>
#include <vector>

using namespace std;

class Shell {
private:
	vector<Shell*> roots;
	bool success;
public:
	Shell();
	void read();
	void parse(string&);
	bool getSuccess();
	virtual string getType();
	virtual string getString();
	virtual string getDirection();
	virtual void setSuccess(bool);
	virtual void setChildren(Shell*, Shell*);
	virtual Shell* getChild(string&);
	virtual void printString();
	virtual void execute(int, int);

};


#endif
