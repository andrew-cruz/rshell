#include <iostream>
#include "../header/Or.h"

//INitilize member functions to NULL
Or::Or() {
    right = NULL;
    left = NULL;
}

//Execute the left and then if left was successful do not execute the right
void Or::execute(int in, int out) {
    left->execute(in, out);

    if(!left->getSuccess() )
        right->execute(in, out);
}

//Sets the left and right children to what the parameter passes in
void Or::setChildren(Shell* lft, Shell* rht) {
    left = lft;
    right = rht;
}

//Prints out the children of the Obj
void Or::printString() {
    if (left && right) {
        this->left->printString();
        cout << " || ";
        this->right->printString();
    }
    else {
        cout << " || ";
    }
}

//Returns the child indicated by the param
Shell* Or::getChild(string& child) {
    if (child == "left")
        return left;

    else if (child == "right")
        return right;

    return NULL;
}

//Returns what obj you are in
string Or::getString() {
    return " || ";
}
