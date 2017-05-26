#include "../header/Parentheses.h"
#include "../header/Shell.h"
#include "../header/Command.h"
#include "../header/And.h"
#include "../header/Or.h"
#include "../header/Test.h"

#include <iostream>
#include <stack>

using namespace std;

Parentheses::Parentheses() {}

Parentheses::Parentheses(string str){
    Parentheses::setVector(str);
    Parentheses::parse();
}

void Parentheses::parse() {
    //Stack used to push and pop vector elements into
    stack<string> tempStrStk;
    //Iterate through the entire vector of strings
    for(unsigned i = 0; i < precVec.size(); i++){
        //Triggers that we should begin pooping
        if(precVec.at(i) == ")"){
            //Until the top element is ( we pop the stack
            while( tempStrStk.top() != "(" ){
                //If the 1st top element is an Operator than we create string op
                //Then pop off that element and new top is then converted into
                //Shell pointer to Command obj and then pop string stack again
                if( (tempStrStk.top() == "&&") || (tempStrStk.top() == "||") ){
                    string op = tempStrStk.top();
                    tempStrStk.pop();
                    Shell* newCmd = new Command(tempStrStk.top());
                    tempStrStk.pop();
                    //If op is && create new And obj with shellPtr.top(Left
                    // side of op) and newCmd(right side)
                    //Else do same as And with Or
                    if( op == "&&" ){
                        Shell* newAnd = new And( shellPtr.top(), newCmd);
                        shellPtr.pop();
                        shellPtr.push(newAnd);
                    }
                    else{
                        Shell* newOr = new Or( shellPtr.top(), newCmd);
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
                else{
                    Shell* cmdRight = new Command( tempStrStk.top() );
                    tempStrStk.pop();
                    shellPtr.push(cmdRight);
                    string op = tempStrStk.top();
                    tempStrStk.pop();
                    //If next obj is another Operator then we check what the
                    //previous op was and creat approp Operator class for is
                    //First create Operator for string op with param
                    //(cmdRight,shellPtr.top()) then this become new cmdRight
                    if( (tempStrStk.top() == "&&") || (tempStrStk.top() == "||") ){
                        if(op == "&&"){
                            Shell* newAnd = new And(cmdRight, shellPtr.top());
                            shellPtr.pop();
                            shellPtr.push(newAnd);
                        }
                        else{
                            Shell* newOr = new Or(cmdRight,shellPtr.top());
                            shellPtr.pop();
                            shellPtr.push(newOr);
                        }
                        //Create new Operator class with tempOp and param being
                        //(shellPtr.top(), strtok.top() ) and push that back
                        //into stack
                        string tempOp = tempStrStk.top();
                        tempStrStk.pop();

                        string cmdRight = tempStrStk.top();
                        tempStrStk.pop();
                        Shell* cmdR = new Command(cmdRight);
                        if(tempOp == "&&"){
                            Shell* newAnd = new And(shellPtr.top(), cmdR);
                            shellPtr.push(newAnd);
                        }
                        else{
                            Shell* newOr = new Or(shellPtr.top(), cmdR);
                            shellPtr.push(newOr);
                        }

                    }
                    //If next obj is another Command then 
                    else{
                        Shell* cmdLeft = new Command(tempStrStk.top());
                        tempStrStk.pop();
                        if(op == "&&"){
                            Shell* newAnd = new And(cmdLeft, shellPtr.top());
                            shellPtr.pop();
                            shellPtr.push(newAnd);
                        }
                        else{
                            Shell* newOr = new Or(cmdLeft,shellPtr.top());
                            shellPtr.pop();
                            shellPtr.push(newOr);
                        }
                    }
                }
            }
            if(!tempStrStk.empty())
                tempStrStk.pop();
        }
        else{
            tempStrStk.push(precVec.at(i));
        }
    }

//*****************
// CHeck if temp stack still has operators
//*****************
    while(!tempStrStk.empty()){
        if(tempStrStk.top() == "&&" || tempStrStk.top() == "||"){
            string op = tempStrStk.top();
            if(tempStrStk.size() == 1){
                if(op == "&&"){
                    Shell* right = shellPtr.top();
                    shellPtr.pop();
                    Shell* left = shellPtr.top();
                    shellPtr.pop();
                    Shell* newAnd = new And(left, right);
                    shellPtr.push(newAnd);
                }
                if(op == "||"){
                    Shell* right = shellPtr.top();
                    shellPtr.pop();
                    Shell* left = shellPtr.top();
                    shellPtr.pop();
                    Shell* newOr = new Or(left, right);
                    shellPtr.push(newOr);
                }
            }

            tempStrStk.pop();
        }
        else{
            Shell* newCmd = new Command(tempStrStk.top());
            tempStrStk.pop();
            string op = tempStrStk.top();
            tempStrStk.pop();
            if(op == "&&"){
                Shell* newAnd = new And(newCmd, shellPtr.top());
                shellPtr.pop();
                shellPtr.push(newAnd);
            }
            else{
                Shell* newOr = new Or(newCmd,shellPtr.top());
                shellPtr.pop();
                shellPtr.push(newOr);
            }
        }
    }

}

void Parentheses::parse(string str){}

void Parentheses::setVector(string str){
    string temp;

    for(unsigned i = 0; i < str.length(); i++){
        if( str.at(i) == '(' || str.at(i) == ')' ){
            if(temp == " "){
                temp.clear();
            }
            if( !temp.empty() ){
                precVec.push_back(temp);
                temp.clear();
            }
            temp.push_back(str.at(i));
            precVec.push_back(temp);
            temp.clear();
        }
        else if( str.at(i) == '&' || str.at(i) == '|'){
            if(temp == " "){
                temp.clear();
            }
            if( !temp.empty() ){
                precVec.push_back(temp);
                temp.clear();
            }
            if( i + 1 < str.length() ){
                temp.push_back( str.at(i) );
                temp.push_back( str.at(i + 1) );
                i += 2;
                precVec.push_back(temp);
                temp.clear();
            }
        }
        else{
            temp.push_back( str.at(i) );
        }
    }
    if(!temp.empty()){
        precVec.push_back(temp);
    }
}

void Parentheses::execute(){
    while(!shellPtr.empty()){
        shellPtr.top()->execute();
        shellPtr.pop();
    }
}

string Parentheses::getNewCmd(){
    return newCmds;
}
