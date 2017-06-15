#ifndef PIPE_H
#define PIPE_H

#include "Arrow.h"

class Pipe : public Arrow {
private:
    Shell* left;
    Shell* right;
public:
    //Constructor
    Pipe();
    //Inherited
    void execute(int, int);
    //Setter
    void setChildren(Shell*, Shell*);
    //Getter
    void printString();
    string getString();
    string getDirection();
    Shell* getChild(string&);
};

#endif
