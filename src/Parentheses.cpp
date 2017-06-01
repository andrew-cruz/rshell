#include "../header/Parentheses.h"
#include "../header/Shell.h"
#include "../header/Command.h"
#include "../header/And.h"
#include "../header/Or.h"
#include "../header/Test.h"

#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <string.h>

using namespace std;

Parentheses::Parentheses() {}

Parentheses::Parentheses(string str) {
    Parentheses::paraCheck(str);
}

//Used to detect if odd or even number of parenthesis where passed in
void Parentheses::paraCheck(string str) {
    int counter = 0;

    //Increments counter when a parenthesis is found
    for (unsigned i = 0; i < str.length(); i++) {
        if (str.at(i) == '(' || str.at(i) == ')') {
            counter++;
        }
    }
    //If odd number fo parenthesis then we cerr
    if (counter % 2 != 0) {
        cerr << "ERROR: INVALID AMMOUNT OF PARENTHESES\n";
        return;
    }
    //else we continue with parsing
    Parentheses::parse(str);
    Parentheses::setVector(newCmds);
    Parentheses::parse();
}

//Parses anything before the first parenthesis and stores it into string right
void Parentheses::parse(string str) {
    newCmds = str;

    if (str.at(0) != '(' && !str.empty()) {
        right = str.substr( 0 , str.find('(') );
        newCmds.erase( 0, str.find('(') );
    }
}

//Used to put back the string right from the above parsing function
void Parentheses::left() {
    string op;
    //If the right string is not empty then we continue
    if (!right.empty()) {
        //Deletes any unnecessary spaces
        while (right.at(right.size() - 1) == ' ' && !right.empty()) {
            right.pop_back();
        }
        //We set the operator that is at the end of this string
        if (right.at(right.size() - 1) == '&') {
            op = "&&";
            right.erase(right.size() - 2, 2);
        }
        else {
            op = "||";
            right.erase(right.size() - 2, 2);
        }
        //We parse the string as usual
        while (right.length() != 0) {
    		//If multiple commands found
    			//Store begining upto first semicolon of string into a substring
    			string temp = right;
    			//If substring contains test, creates Shell* of type Test and push back into queue
    			//If substring contains && go create Shell* of type And and push back into queue
    			if (temp.find("&&") != string::npos) {
    				Shell* tempAnd = new And(temp);
    				shellPtr.push(tempAnd);
    			}
    			//If substring contains || create a Shell* of type Or and push back into queue
    			else if (temp.find("||") != string::npos) {
    				Shell* tempOr = new Or(temp);
    				shellPtr.push(tempOr);
    			}
    			//If substring contains test or [] create a Shell* of type Test and push back into queue
    			else if ( (temp.find("test") != string::npos) ||
                    ( (temp.find("[") != string::npos) &&
                    (temp.find("]") != string::npos) ) ) {
    				Shell* tempTest = new Test(temp);
    				shellPtr.push(tempTest);
    			}
    			//If substring is just a simple command create a Shell* of type Command and push back into queue
    			else {
    				Shell* tempCmd = new Command(temp);
    				shellPtr.push(tempCmd);
    			}
    			//Erases the substring and reduces the string down
    			right.clear();
    	}
        //We create both the left and right side of the opereator that we stored
        //in op
        Shell* left = shellPtr.top();
        shellPtr.pop();
        Shell* right = shellPtr.top();
        shellPtr.pop();
        //We create the operator object using op
        //And push that back into stack
        if (op == "&&") {
            Shell* newAnd = new And(left,right);
            shellPtr.push(newAnd);
        }
        else {
            Shell* newOr = new Or(left,right);
            shellPtr.push(newOr);

        }
    }
}

void Parentheses::parse() {
    //Stack used to push and pop vector elements into
    stack<string> tempStrStk;
    //Iterate through the entire vector of strings
    for (unsigned i = 0; i < precVec.size(); i++) {
        //Triggers that we should begin popping
        if (precVec.at(i) == ")") {
            //Until the top element is ( we pop the stack
            while ( tempStrStk.top() != "(" ) {
                //If the 1st top element is an Operator than we create string op
                //Then pop off that element and new top is then converted into
                //Shell pointer to Command obj and then pop string stack again
                if ( (tempStrStk.top() == "&&") || (tempStrStk.top() == "||") ) {
                    string op = tempStrStk.top();
                    tempStrStk.pop();
                    Shell* newCmd;

                    if ((tempStrStk.top().find("test") != string::npos) ||
                      (tempStrStk.top().find('[') != string::npos)) {
                          newCmd = new Test(tempStrStk.top());
                      }
                      else {
                          newCmd = new Command(tempStrStk.top());
                      }
                    tempStrStk.pop();
                    //If op is && create new And obj with shellPtr.top(Left
                    // side of op) and newCmd(right side)
                    //Else do same as And with Or
                    if ( op == "&&" ) {
                        Shell* newAnd = new And(newCmd, shellPtr.top());
                        shellPtr.pop();
                        shellPtr.push(newAnd);
                    }
                    else {
                        Shell* newOr = new Or( newCmd,shellPtr.top());
                        shellPtr.pop();
                        shellPtr.push(newOr);
                    }
                }
                //If 1st element is a string wih commands then we create a
                //Command obj pointing to string stack top and push into Shell*
                //Stack. Then pop string stack and next element should always be
                //Operator and store op in a string and pop string stack
                //Depending on what next onj is on top of string stack we
                //deal with it appropiately
                else {
                    Shell* cmdRight;
                    if ((tempStrStk.top().find("test") != string::npos) ||
                      (tempStrStk.top().find('[') != string::npos)) {
                          cmdRight = new Test(tempStrStk.top());
                      }
                      else {
                          cmdRight = new Command(tempStrStk.top());
                      }
                    tempStrStk.pop();


                    if ((tempStrStk.size() == 1) && (tempStrStk.top() == "(")) {

                        shellPtr.push(cmdRight);
                    }
                    else {
                        shellPtr.push(cmdRight);
                        string op = tempStrStk.top();
                        tempStrStk.pop();
                        //If next obj is another Operator then we check what the
                        //previous op was and creat approp Operator class for is
                        //First create Operator for string op with param
                        //(cmdRight,shellPtr.top()) then this become new cmdRight
                        if ( (tempStrStk.top() == "&&") ||
                            (tempStrStk.top() == "||") ) {
                            if (op == "&&") {
                                Shell* newAnd = new And(cmdRight, shellPtr.top());
                                shellPtr.pop();
                                shellPtr.push(newAnd);
                            }
                            else {
                                Shell* newOr = new Or(cmdRight,shellPtr.top());
                                shellPtr.pop();
                                shellPtr.push(newOr);
                            }
                            //Create new Operator class with tempOp and param being
                            //(shellPtr.top(), strtok.top() ) and push that back
                            //into stack
                            string tempOp = tempStrStk.top();
                            tempStrStk.pop();

                            Shell* cmdR;
                            if ((tempStrStk.top().find("test") != string::npos)
                            || (tempStrStk.top().find('[') != string::npos)) {
                                  cmdR = new Test(tempStrStk.top());
                              }
                              else {
                                  cmdR = new Command(tempStrStk.top());
                              }
                              tempStrStk.pop();

                            if (tempOp == "&&") {
                                Shell* newAnd = new And(shellPtr.top(), cmdR);
                                shellPtr.push(newAnd);
                            }
                            else {
                                Shell* newOr = new Or(shellPtr.top(), cmdR);
                                shellPtr.push(newOr);
                            }

                        }
                        //If next obj is another Command then we creat a Command ptr
                        //using string stack from the top and then pop string stack
                        //Depending on op we creat Operator Class obj and pass in
                        //param (cmdLeft, cmdRight)
                        //Note: cmdRight is shellPtr.top() line: 60
                        else {
                            Shell* cmdLeft;

                            if ( (tempStrStk.top().find("test") != string::npos)
                            || (tempStrStk.top().find('[') != string::npos) ) {
                                  cmdLeft = new Test(tempStrStk.top());
                              }
                              else {
                                  cmdLeft = new Command(tempStrStk.top());
                              }

                            tempStrStk.pop();
                            if (op == "&&") {
                                Shell* newAnd = new And(cmdLeft, shellPtr.top());
                                shellPtr.pop();
                                shellPtr.push(newAnd);
                            }
                            else {
                                Shell* newOr = new Or(cmdLeft,shellPtr.top());
                                shellPtr.pop();
                                shellPtr.push(newOr);
                            }
                        }
                    }
                }
            }
            //If string stack is not empty pop off one element
            //Should pop off ) from string stack
            if (!tempStrStk.empty())
                tempStrStk.pop();
        }
        //Push vector element into string stack
        else {
            tempStrStk.push(precVec.at(i));
        }
    }

    while (!tempStrStk.empty()) {
        //If top element in stack is an Operator then go in here
        if (tempStrStk.top() == "&&" || tempStrStk.top() == "||") {
            string op = tempStrStk.top();
            //If only element in stack is operator and shellPtr stack has 2+
            //elements than we pop and create the corresponding operator obj
            if (shellPtr.size() >= 2) {
                if (op == "&&") {
                    Shell* left = shellPtr.top();
                    shellPtr.pop();
                    Shell* right = shellPtr.top();
                    shellPtr.pop();
                    Shell* newAnd = new And(right, left);
                    shellPtr.push(newAnd);
                }
                if (op == "||") {
                    Shell* left = shellPtr.top();
                    shellPtr.pop();
                    Shell* right = shellPtr.top();
                    shellPtr.pop();
                    Shell* newOr = new Or(right,left);
                    shellPtr.push(newOr);
                }
            }
            tempStrStk.pop();
        }
        //If top element in stack is of type Command then wego in here
        else {
            Shell* newCmd;
            //If the top element is test then we create test obj else we
            //create normal command obj
            if ((tempStrStk.top().find("test") != string::npos) ||
              (tempStrStk.top().find('[') != string::npos)) {
                  newCmd = new Test(tempStrStk.top());
            }
            else {
                  newCmd = new Command(tempStrStk.top());
            }

            tempStrStk.pop();

            string op = tempStrStk.top();
            tempStrStk.pop();
            //Use the newCmd and the top of shellPtr stack to create the
            //appropiate obj as defined by op
            if (op == "&&") {
                Shell* newAnd = new And(newCmd,shellPtr.top());
                shellPtr.pop();
                shellPtr.push(newAnd);
            }
            else {
                Shell* newOr = new Or(newCmd,shellPtr.top());
                shellPtr.pop();
                newOr->getCommand();
                shellPtr.push(newOr);
            }
        }
    }
    //Add the left part of the command that we parsed off in parse(str) function
    Parentheses::left();
}

//Creates the vector that we create the stack from
void Parentheses::setVector(string str){
    string temp;
    //Strings that are "(" "&&" "||" ")" get there own index in the vector
    //While everything else share index allocation
    for (unsigned i = 0; i < str.length(); i++) {
        if(str.at(i) == '(' || str.at(i) == ')'){
            if (temp == " ") {
                temp.clear();
            }
            if (!temp.empty()) {
                precVec.push_back(temp);
                temp.clear();
            }
            temp.push_back(str.at(i));
            precVec.push_back(temp);
            temp.clear();
        }
        else if ( str.at(i) == '&' || str.at(i) == '|') {
            if (temp == " ") {
                temp.clear();
            }
            if (!temp.empty()) {
                precVec.push_back(temp);
                temp.clear();
            }
            if (i + 1 < str.length()) {
                temp.push_back(str.at(i));
                temp.push_back(str.at(i + 1));
                i += 2;
                precVec.push_back(temp);
                temp.clear();
            }
        }
        else {
            temp.push_back(str.at(i));
        }
    }
    if (!temp.empty()) {
        precVec.push_back(temp);
    }

}

//Executes the stack
void Parentheses::execute() {
    while (!shellPtr.empty()) {
        shellPtr.top()->execute();
        shellPtr.pop();
    }
}

//Return the string member function
string Parentheses::getNewCmd() {
    return newCmds;
}
