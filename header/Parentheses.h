#ifndef Parentheses_H
#define Parentheses_H

#include "../header/Shell.h"
#include <string>

using namespace std;

class Parentheses : public Shell{
private:
    vector<Shell*> cmdPara;
public:
    //Constructor
    Parentheses() {};
    Parentheses(string);
    Parentheses(Shell*);
    //Need defintion
    void parse(){}
	void parse(string);
	void execute(){};

	 bool getSuccess(int) {return false;};
	 void getCommand() {};
     string getString() {
         string temp = "Paran";
         return temp;
     };
};

#endif
