#ifndef PIPE_H
#define PIPE_H

#include "Op.h"

class Pipe : public Arrow {
private:
    Shell* left;
    Shell* right;
public:
    //Constructor
    Pipe();
    //Inherited
    void execute();
    //Setter
    void setChildren(Shell*, Shell*);
    //Getter
    void printString();
    string getString();
};

#endif
