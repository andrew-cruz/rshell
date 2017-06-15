#ifndef CMD_H
#define CMD_H

#include "Shell.h"

class Cmd : public Shell {
protected:
    Shell* type;
public:
    //Constructor
    Cmd();
    Cmd(const string&);
    //Inherited
    virtual void execute();
    //Getter
    string getType();
	virtual void printString();
    virtual string getString();
    virtual Shell* getChild(string&);
};

#endif
