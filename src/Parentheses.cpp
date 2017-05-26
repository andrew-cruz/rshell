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
    // Parentheses::parse(str);
    Parentheses::setVector(str);
    Parentheses::parse();
}

void Parentheses::parse() {
    stack<string> tempStrStk;

    for(unsigned i = 0; i < precVec.size(); i++){
        // cout << "************************************************\n";
        // cout << "We are working with "  << precVec.at(i) << endl;
        //POP OUT OF STACK UNTIL ReACHING (
        if(precVec.at(i) == ")"){
            // cout << "In outer if()\n";
            while( tempStrStk.top() != "(" ){
                // cout << "In While()\n";
                if( (tempStrStk.top() == "&&") || (tempStrStk.top() == "||") ){
                    // cout << "if 1\n";
                    string op = tempStrStk.top();
                    // cout << "\tCreated op " << op << endl;
                    tempStrStk.pop();

                    Shell* newCmd = new Command(tempStrStk.top());
                    // cout << "\tCreated new cmd " << tempStrStk.top() << endl;
                    tempStrStk.pop();

                    if( op == "&&" ){
                        // cout << "if 2\n";
                        Shell* newAnd = new And( shellPtr.top(), newCmd);
                        shellPtr.pop();
                        // cout << "Created New And ";
                        // newAnd->getCommand();
                        // cout << "\n";
                        shellPtr.push(newAnd);
                    }
                    else{
                        // cout << "if 3\n";
                        Shell* newOr = new Or( shellPtr.top(), newCmd);
                        shellPtr.pop();
                        // cout << "Created New Or ";
                        // newOr->getCommand();
                        // cout << "\n";
                        shellPtr.push(newOr);
                    }
                }
                else{
                    // cout << "if 4\n";
                    Shell* cmdRight = new Command( tempStrStk.top() );
                    // cout << "\tCreated new cmdRight " << tempStrStk.top() << endl;
                    tempStrStk.pop();
                    shellPtr.push(cmdRight);

                    string op = tempStrStk.top();
                    // cout << "\tCreated op " << op << endl;
                    tempStrStk.pop();



                    if( (tempStrStk.top() == "&&") || (tempStrStk.top() == "||") ){
                        // cout << "if 5\n";
                        if(op == "&&"){
                            // cout << "if 6\n";
                            Shell* newAnd = new And(cmdRight, shellPtr.top());
                            shellPtr.pop();
                            // cout << "Created New And ";
                            // newAnd->getCommand();
                            // cout << "\n";
                            shellPtr.push(newAnd);
                        }
                        else{
                            // cout << "if 7\n";
                            Shell* newOr = new Or(cmdRight,shellPtr.top());
                            shellPtr.pop();
                            // cout << "Created New Or ";
                            // newOr->getCommand();
                            // cout << "\n";
                            shellPtr.push(newOr);
                        }
                    }
                    else                    {
                        // cout << "if 8\n";
                        Shell* cmdLeft = new Command(tempStrStk.top());
                        // cout << "\tCreated new cmdLeft " << tempStrStk.top() << endl;
                        tempStrStk.pop();

                        if(op == "&&"){
                            // cout << "if 9\n";
                            Shell* newAnd = new And(cmdLeft, shellPtr.top());
                            shellPtr.pop();
                            // cout << "Created New And ";
                            // newAnd->getCommand();
                            // cout << "\n";
                            shellPtr.push(newAnd);
                        }
                        else{
                            // cout << "if 10\n";
                            Shell* newOr = new Or(cmdLeft,shellPtr.top());
                            shellPtr.pop();
                            // cout << "Created New Or ";
                            // newOr->getCommand();
                            // cout << "\n";
                            shellPtr.push(newOr);
                        }
                    }
                }
                // cout << "Leaving While()\n";
            }
            //Pops out (
            if(!tempStrStk.empty())
                tempStrStk.pop();
            // cout << "Leaving outer if\n";
        }
        else{
            // cout << "Outer else\n";
            tempStrStk.push(precVec.at(i));
            // cout << "Leaving outer else\n";
        }
    }



//**************
//
//***************
// cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
// cout << "Stack size is " << shellPtr.size() << endl;
// while(!tempStrStk.empty()){
//     cout << tempStrStk.top() << endl;
//     tempStrStk.pop();
// }
// cout << "-------------------------------------------------\n";


//*****************
// CHeck if temp stack still has operators
//*****************
    while(!tempStrStk.empty()){
        // cout << "IN while\n";
        if(tempStrStk.top() == "&&" || tempStrStk.top() == "||"){
            // cout << "In if\n";
            string op = tempStrStk.top();
            // tempStrStk.pop();
            if(tempStrStk.size() == 1){
            // cout << "if(1)\n";
                if(op == "&&"){
                    Shell* right = shellPtr.top();
                    shellPtr.pop();
                    Shell* left = shellPtr.top();
                    shellPtr.pop();
                    Shell* newAnd = new And(left, right);

                    shellPtr.push(newAnd);
                }
                if(op == "||"){
                    // cout << "In Or\n";
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

void Parentheses::parse(string str){

}

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

    //Getting rid of space

}

void Parentheses::execute(){
    while(!shellPtr.empty()){
        // cout << "Paran execute\n";
        shellPtr.top()->execute();
        shellPtr.pop();
    }
}

string Parentheses::getNewCmd(){
    return newCmds;
}
