#ifndef OP_H
#define OP_H

#include "Shell.h"

class Op : public Shell {
protected:
    Shell* type;
public:
    //Constructor
    Op();
    Op(const string&);
    //Inherited fcn
    virtual void execute(int, int);
    //Setter
    void setChildren(Shell*, Shell*);
    //Getter
    string getType();
    virtual void printString();
    Shell* getChild(string&);
    string getString();
};



#endif
