#include "../header/Tree.h"
#include "../header/Shell.h"
#include "../header/Op.h"
#include "../header/Cmd.h"
#include "../header/Arrow.h"


#include <iostream>
#include <stack>
#include <fstream>

using namespace std;

//Sets the root Shell* to NULL
Tree::Tree(string str){
    root = constructTree(str);
}

//Used to check if char is an operator or not
bool Tree::isOperator(const char& str){
    if(str == '&' || str == '|' || str == '<'
        || str == '>')
        return true;
    return false;
}

//Used to check if Shell* is an operator
bool Tree::isOperator(Shell* shellPtr){
    if(shellPtr->getType() == "Op")
        return true;
    return false;
}

//Creates a Shell Pointer for given string
Shell* Tree::shellPtrConstruct(const string& str){
    Shell* newObj;

    if(str == "&&" || str == "||")
        newObj = new Op(str);
    else if ( str == "<" || str == ">" || str == ">>" || str.find('|') != string::npos)
        newObj = new Arrow(str);
    else
        newObj = new Cmd(str);

    return newObj;
}

//Creates the vector we use to make expression tree
vector<Shell*> Tree::setVector(const string& str){
    string temp;
    vector<Shell*> precVec;
    for (unsigned i = 0; i < str.length(); i++) {
        if(str.at(i) == '(' || str.at(i) == ')'){
            if (temp == " ") {
                temp.clear();
            }

            if (!temp.empty()) {
                Shell* tempShell = shellPtrConstruct(temp);
                precVec.push_back(tempShell);
                temp.clear();
            }

            temp.push_back(str.at(i));
            Shell* tempShell = shellPtrConstruct(temp);
            precVec.push_back(tempShell);
            temp.clear();
        }
        else if ( isOperator(str.at(i)) ) {
            if (temp == " ") {
                temp.clear();
            }
            if (!temp.empty()) {
                Shell* tempShell = shellPtrConstruct(temp);
                precVec.push_back(tempShell);
                temp.clear();
            }
            //Checking to see if >> && ||
            if (i + 1 < str.length()) {
                if(str.at(i + 1) == '|' || str.at(i + 1) == '&' ||
                str.at(i + 1) == '>'){
                    temp.push_back(str.at(i));
                    temp.push_back(str.at(i + 1));
                    i += 2;
                    Shell* tempShell = shellPtrConstruct(temp);
                    precVec.push_back(tempShell);
                    temp.clear();
                }
                else{
                    temp.push_back(str.at(i));
                    i += 1;
                    Shell* tempShell = shellPtrConstruct(temp);
                    precVec.push_back(tempShell);
                    temp.clear();
                }
            }
        }
        else {
            temp.push_back(str.at(i));
        }
    }
    if (!temp.empty()) {
        Shell* tempShell = shellPtrConstruct(temp);
        precVec.push_back(tempShell);
    }
    return precVec;
}

bool Tree::precedenceGt(Shell* str, Shell* gt) {
    int op1 = weight(str);
    int op2 = weight(gt);

    if(op1 > op2) {
        return true;
    }

    return false;
}

int Tree::weight(Shell* str) {
   if(str->getType() == "arrow") {
       return 1;
   }
    return 0;
}

vector<Shell*> Tree::infixToPostfix(const vector<Shell*>& stringVec){
    stack<Shell*> s;
    vector<Shell*> postfixVector;

    for(unsigned i = 0; i < stringVec.size(); i++){
        //If char is an operator pop out from stack perform operation and push result back
        if(isOperator(stringVec.at(i))){
            while(!s.empty() && s.top()->getString() != "(" && precedenceGt(s.top(), stringVec.at(i))){
                postfixVector.push_back(s.top());
                s.pop();
            }
            s.push(stringVec.at(i));
        }
        //If shell* is a cmd
        else if(!isOperator(stringVec.at(i)) && stringVec.at(i)->getString() != "(" &&
                stringVec.at(i)->getString() != ")" ){
            postfixVector.push_back(stringVec.at(i));
        }
        else if(stringVec.at(i)->getString() == "("){
            s.push(stringVec.at(i));

        }
        else if(stringVec.at(i)->getString() == ")"){
            while(!s.empty() && s.top()->getString() != "("){
                postfixVector.push_back(s.top());
                s.pop();
            }
        }
    }

    while(!s.empty()){
        if(s.top()->getString() != ")" && s.top()->getString() != "("){
            postfixVector.push_back(s.top());
        }
        s.pop();
    }


    return postfixVector;
}

Shell* Tree::constructTree(const string& str){
    stack<Shell*> shellStack;
    vector<Shell*> commandVector;
    commandVector = setVector(str);
    commandVector = infixToPostfix(commandVector);

    Shell* parent;


    // for(unsigned i = 0; i < commandVector.size(); i++) {
    //     commandVector.at(i)->printString();
    //     cout << endl;
    // }

    for(unsigned i = 0; i < commandVector.size(); i++) {
        //Push into stack if not an operator
        if(!isOperator(commandVector.at(i)) && !isArrow(commandVector.at(i))) {
            shellStack.push(commandVector.at(i));
        }
        else{
            parent = commandVector.at(i);
            Shell* left;
            Shell* right;

            if(parent->getType() == "arrow" && (i + 1 < commandVector.size()))  {
                // cout << "hwe " << i << endl;
                right = commandVector.at(i + 1);
                left = shellStack.top();
                shellStack.pop();
                i++;
            }
            else{
                right = shellStack.top();
                shellStack.pop();
                left = shellStack.top();
                shellStack.pop();
            }

            // cout << "\t" << parent->getString();
            // cout << '\n';
            // cout << left->getString();
            // cout << "\t\t" << right->getString();
            // cout << '\n';

            parent->setChildren(left,right);
            shellStack.push(parent);
        }
    }

    Shell* root = shellStack.top();

    shellStack.pop();

    // root->printString();
    //
    // cout << '\n';
    // cout << "roo is " << root->getType() << endl;
    return root;
}

bool Tree::isArrow(Shell* shPtr) {
    if(shPtr->getType() == "arrow")
        return true;

    return false;
}

Shell* Tree::getRoot(){
    return this->root;
}
