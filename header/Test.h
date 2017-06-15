#ifndef TEST_H
#define TEST_H

#include "Cmd.h"

class Test : public Cmd {
private:
    string test;
public:
    //Constructor
    Test();
    Test(const string&);
    //Inherited
    void execute(int, int);
    //Getter
    void printString();
    string getString();
    //Unique
    void parseStr();
};

#endif
