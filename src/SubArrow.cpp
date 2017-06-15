#include "../header/SubArrow.h"
#include <iostream>

//************************************
//      Left Arrow <
//************************************

//Initialize member obj to NULL
LeftArrow::LeftArrow() {
    left = NULL;
    right = NULL;
}

//Sets the left and right children to passed in param
void LeftArrow::setChildren(Shell* lft, Shell* rht){
    left = lft;
    right = rht;
}

//Prints the left and right children of the obj
void LeftArrow::printString() {
    if (left && right) {
        left->printString();
        cout << " < ";
        right->printString();
    }
    else {
        cout << " < ";
    }
}

//Returns the direction of the arrow
string LeftArrow::getDirection() {
    return "<";
}

//Returns the child indicated by the param
Shell* LeftArrow::getChild(string& child) {
    if (child == "left")
        return left;

    else if (child == "right")
        return right;

    return NULL;
}

//Returns the type of obj it is
string LeftArrow::getString() {
    return " < ";
}


//**********************************
//      Right Right Arrow >>
//**********************************

//Initilize member obj to NULL
RightRArrow::RightRArrow() {
    left = NULL;
    right = NULL;
}

//Sets the left and right children to passed in param
void RightRArrow::setChildren(Shell* lft, Shell* rht) {
    left = lft;
    right = rht;
}

//Prints the left and right children of the obj
void RightRArrow::printString() {
   if (left && right) {
        left->printString();
        cout << " >> ";
        right->printString();
    }
    else {
        cout << " >> ";
    }
}

//Returns the direction of the arrow
string RightRArrow::getDirection() {
    return ">>";
}

//Returns the child indicated by the param
Shell* RightRArrow::getChild(string& child) {
    if (child == "left")
        return left;

    else if (child == "right")
        return right;

    return NULL;
}

//Returns the type of obj it is
string RightRArrow::getString() {
    return " >> ";
}

//***********************************
//      Right Arrow >
//***********************************

//Initilize member obj to NULL
RightArrow::RightArrow() {
    right = left = NULL;
}

//Sets the left and right children to passed in param
void RightArrow::setChildren(Shell* lft, Shell* rht) {
    left = lft;
    right = rht;
}

//Prints the left and right children of the obj
void RightArrow::printString() {
    if (left && right) {
        left->printString();
        cout << " > ";
        right->printString();
    }
    else {
        cout << " > ";
    }
}

//Returns the direction of the arrow
string RightArrow::getDirection() {
    return ">";
}

//Returns the child indicated by the param
Shell* RightArrow::getChild(string& child) {
    if (child == "left")
        return left;

    else if (child == "right")
        return right;

    return NULL;
}

//Returns the type of obj it is
string RightArrow::getString() {
    return " > ";
}
