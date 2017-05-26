#ifndef Parentheses_H
#define Parentheses_H

#include "../header/Shell.h"
#include <string>

using namespace std;

class Parentheses : public Shell{
private:
    string newCmds;
    vector<string> precVec;
public:
    //Constructor
    Parentheses();
    Parentheses(string);
    void parse();
    void parse(string);
    void setVector(string);
    string getNewCmd();

};

#endif
