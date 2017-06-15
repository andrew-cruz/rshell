#ifndef ARROW_H
#define ARROW_H


#include "Shell.h"

class Arrow : public Shell {
protected:
    Shell* type;
public:
    //Constructor
    Arrow();
    Arrow(const string&);
    //Inherited
    void execute(int, int);
    //Setter
    void setChildren(Shell*, Shell*);
    //Getter
    void printString();
    string getType();
    //Unique
    string getDirection();
    Shell* getChild(string&);
    string getString();
};


#endif
