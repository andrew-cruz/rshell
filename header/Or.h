#ifndef OR_H
#define OR_H

#include "Op.h"

class Or : public Op {
private:
    Shell* left;
    Shell* right;
public:
    //Constructor
    Or();
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
