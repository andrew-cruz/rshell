#ifndef Parentheses_H
#define Parentheses_H

#include "../header/Shell.h"
#include <string>
#include <stack>

using namespace std;

class Parentheses : public Shell{
private:
    string newCmds;
    string right;
    vector<string> precVec;
    stack<Shell*> shellPtr;
public:
    //Constructor
    Parentheses();
    Parentheses(string);
    void parse();
    void paraCheck(string);
    void parse(string);
    void left();
    void setVector(string);
    void execute();
    string getNewCmd();

};

#endif
