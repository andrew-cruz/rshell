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
Tree::Tree(string str) {
    root = constructTree(str);
}

//Used to check if char is an operator or not
bool Tree::isOperator(const char& str) {
    if (str == '&' || str == '|' || str == '<'
        || str == '>')
        return true;
    return false;
}

//Used to check if Shell* is an operator
bool Tree::isOperator(Shell* shellPtr) {
    if (shellPtr->getType() == "Op")
        return true;
    return false;
}

//Creates a Shell Pointer for given string
Shell* Tree::shellPtrConstruct(const string& str) {
    Shell* newObj;

    if (str == "&&" || str == "||")
        newObj = new Op(str);
    else if ( str == "<" || str == ">" || str == ">>" || str.find('|') != string::npos)
        newObj = new Arrow(str);
    else
        newObj = new Cmd(str);

    return newObj;
}

//Creates the vector we use to make expression tree
vector<Shell*> Tree::setVector(const string& str) {
    string temp;
    vector<Shell*> precVec;

    //Traverse the entire string to parse it by operators
    for (unsigned i = 0; i < str.length(); i++) {
        //If you find a parenthesis then you push what is in temp into the vector
        //then push the parenthesis into the vector
        if (str.at(i) == '(' || str.at(i) == ')') {
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
        //If you find an operator then you push it back into the stack
        //Special cases are when the operator are in more than one index in the string
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
                if (str.at(i + 1) == '|' || str.at(i + 1) == '&' ||
                str.at(i + 1) == '>') {
                    temp.push_back(str.at(i));
                    temp.push_back(str.at(i + 1));
                    i += 2;
                    Shell* tempShell = shellPtrConstruct(temp);
                    precVec.push_back(tempShell);
                    temp.clear();
                }
                else {
                    temp.push_back(str.at(i));
                    i += 1;
                    Shell* tempShell = shellPtrConstruct(temp);
                    precVec.push_back(tempShell);
                    temp.clear();
                }
            }
        }
        //Push back char at i into the string temp
        else {
            temp.push_back(str.at(i));
        }
    }
    //If temp is not empty put remains into vector
    if (!temp.empty()) {
        Shell* tempShell = shellPtrConstruct(temp);
        precVec.push_back(tempShell);
    }
    return precVec;
}

//Used to check what has higher precedence between to shell pointers
bool Tree::precedenceGt(Shell* str, Shell* gt) {
    int op1 = weight(str);
    int op2 = weight(gt);

    if (op1 > op2) {
        return true;
    }

    return false;
}

//Returns the weight of the Shell* being examined
int Tree::weight(Shell* str) {
   if (str->getType() == "arrow") {
       return 1;
   }
    return 0;
}

//Converts the passed in vector from infix to postfix
vector<Shell*> Tree::infixToPostfix(const vector<Shell*>& stringVec) {
    //Stack that we use to push and pop from for algorithm
    stack<Shell*> s;
    //Vector where we store postfix expression
    vector<Shell*> postfixVector;

    for (unsigned i = 0; i < stringVec.size(); i++){
        //If Shell* is an operator
        if (isOperator(stringVec.at(i) ) ) {
            //While the element on top is not an opening paren and it has higher precedence than
            //the current vector element than we push the top of the stack into the postfix vector
            while (!s.empty() && s.top()->getString() != "(" && precedenceGt(s.top(), stringVec.at(i) ) ) {
                postfixVector.push_back(s.top() );
                s.pop();
            }
            //We then push the vector element we were comparing
            s.push(stringVec.at(i));
        }
        //If shell* is a cmd we push it into the postfix vector
        else if (!isOperator(stringVec.at(i)) && stringVec.at(i)->getString() != "(" &&
                stringVec.at(i)->getString() != ")" ) {
            postfixVector.push_back(stringVec.at(i));
        }
        //If it is an opening paren than we push it back into the stack
        else if (stringVec.at(i)->getString() == "(") {
            s.push(stringVec.at(i));

        }
        //If we find a closing paren then while the stack is not empty and while we do not
        //find an opening paren we push the top of the stack into the postfix vec
        else if (stringVec.at(i)->getString() == ")") {
            while (!s.empty() && s.top()->getString() != "(") {
                postfixVector.push_back(s.top());
                s.pop();
            }
        }
    }
    //If the stack still has elements than we push those into the postfix vector
    while (!s.empty() ) {
        if (s.top()->getString() != ")" && s.top()->getString() != "(") {
            postfixVector.push_back(s.top());
        }
        s.pop();
    }
    return postfixVector;
}

//Constructs the expression tree from the postfix vector being passes in
Shell* Tree::constructTree(const string& str) {
    //Stack to push and pop from
    stack<Shell*> shellStack;
    //Vector that stores the commands
    vector<Shell*> commandVector;
    //Convert string into vector
    commandVector = setVector(str);
    //Convert infix vector into postfix vector
    commandVector = infixToPostfix(commandVector);

    Shell* parent;

    for (unsigned i = 0; i < commandVector.size(); i++) {
        //Push into stack if not an operator
        if (!isOperator(commandVector.at(i)) && !isArrow(commandVector.at(i) ) ) {
            shellStack.push(commandVector.at(i));
        }
        //If we find an operator in current index
        else {
            //Parent becomes current vector index
            parent = commandVector.at(i);
            Shell* left;
            Shell* right;

            //If we find a pipe or arrow than we set the rhs to index + 1 from vector and
            //lhs to the top of the stack and then increment i to compensate for access
            if (parent->getType() == "arrow" && (i + 1 < commandVector.size() ) )  {
                right = commandVector.at(i + 1);
                left = shellStack.top();
                shellStack.pop();
                i++;
            }
            //IF not then we set right to top of stack and then left to top - 1 of stack
            else {
                right = shellStack.top();
                shellStack.pop();
                left = shellStack.top();
                shellStack.pop();
            }
            //We set the left and right as children of the parent and then push it back into stack
            parent->setChildren(left,right);
            shellStack.push(parent);
        }
    }
    //Set the root to the stack top and return it
    Shell* root = shellStack.top();
    shellStack.pop();

    return root;
}

//checks if Shell* is an arrow or not
bool Tree::isArrow(Shell* shPtr) {
    if(shPtr->getType() == "arrow")
        return true;

    return false;
}

//returns the root
Shell* Tree::getRoot() {
    return this->root;
}
