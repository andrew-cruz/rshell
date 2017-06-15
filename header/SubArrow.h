#ifndef SUBARROW_H
#define SUBARROW_H

#include "Arrow.h"

class RightArrow : public Arrow {
private:
    Shell* left;
    Shell* right;
public:
    RightArrow();
    void setChildren(Shell*,Shell*);
    void printString();
    string getDirection();
    Shell* getChild(string&);
    string getString();
};

class RightRArrow : public Arrow {
private:
    Shell* left;
    Shell* right;
public:
    RightRArrow();
    void setChildren(Shell*,Shell*);
    void printString();
    string getDirection();
    Shell* getChild(string&);
    string getString();
};

class LeftArrow : public Arrow {
private:
    Shell* left;
    Shell* right;
public:
    LeftArrow();
    void setChildren(Shell*,Shell*);
    void printString();
    string getDirection();
    Shell* getChild(string&);
    string getString();
};

#endif
