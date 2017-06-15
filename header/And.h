#ifndef AND_H
#define AND_H

#include "Op.h"

#include <iostream>

class And : public Op {
private:
    Shell* left;
    Shell* right;
public:
    //Constructor
    And();
    //Inherited
    void execute(int, int);
    //Setter
    void setChildren(Shell*, Shell*);
    //Getter
    void printString();
    Shell* getChild(string&);
    string getString();
};


#endif
