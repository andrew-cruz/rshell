#include <iostream>
#include "../header/And.h"

//Initilizes Left and Right to NULL
And::And() {
    left = NULL;
    right = NULL;
}

//Executes both left and right children
void And::execute(int in, int out) {
    left->execute(in, out);
    right->execute(in, out);
}

//Sets it left and right children to passes in param
void And::setChildren(Shell* lft, Shell* rht) {
    left = lft;
    right = rht;
}

//Prints the children 
void And::printString() {
    if(left && right) {
        this->left->printString();
        cout << " && ";
        this->right->printString();
    }
    else {
        cout << " && ";
    }
}

//Returns the child that is request from the param
Shell* And::getChild(string& child) {
    if(child == "left")
        return left;

    else if(child == "right")
        return right;

    return NULL;
}

//Returns what type of class it is
string And::getString() {
    return " && ";
}
