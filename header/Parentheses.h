#ifndef Parentheses_H
#define Parentheses_H

#include "../header/Shell.h"
#include <string>

using namespace std;

class Parentheses : public Shell{
private:
    string newCmds;
public:
    //Constructor
    Parentheses();
    Parentheses(string);
    void parse(string);
    string getNewCmd();

};

#endif
