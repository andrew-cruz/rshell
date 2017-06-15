#include "../header/SubArrow.h"

#include <iostream>

//*****************************
//      Left Arrow <
//*****************************
LeftArrow::LeftArrow() {
    left = NULL;
    right = NULL;
}
void LeftArrow::setChildren(Shell* lft,Shell* rht){
    left = lft;
    right = rht;
}
void LeftArrow::printString(){
    if(left && right){
        left->printString();
        cout << " < ";
        right->printString();
    }
    else{
        cout << " < ";
    }
}

string LeftArrow::getDirection() {
    return "<";
}

Shell* LeftArrow::getChild(string& child) {
    if(child == "left")
        return left;

    else if(child == "right")
        return right;

    return NULL;
}

string LeftArrow::getString() {
    return " < ";
}
//*****************************
//      Right Right Arrow >>8
//*****************************
RightRArrow::RightRArrow() {
    left = NULL;
    right = NULL;
}
void RightRArrow::setChildren(Shell* lft, Shell* rht) {
    left = lft;
    right = rht;
}
void RightRArrow::printString() {
   if(left && right){
        left->printString();
        cout << " >> ";
        right->printString();
    }
    else{
        cout << " >> ";
    }
}

string RightRArrow::getDirection() {
    return ">>";
}

Shell* RightRArrow::getChild(string& child) {
    if(child == "left")
        return left;

    else if(child == "right")
        return right;

    return NULL;
}

string RightRArrow::getString() {
    return " >> ";
}
//*****************************
//      Right Arrow >
//*****************************
RightArrow::RightArrow() {
    right = left = NULL;
}

void RightArrow::setChildren(Shell* lft, Shell* rht) {
    left = lft;
    right = rht;
}
void RightArrow::printString() {
    if(left && right){
        left->printString();
        cout << " > ";
        right->printString();
    }
    else{
        cout << " > ";
    }
}

string RightArrow::getDirection() {
    return ">";
}

Shell* RightArrow::getChild(string& child) {
    if(child == "left")
        return left;

    else if(child == "right")
        return right;

    return NULL;
}

string RightArrow::getString() {
    return " > ";
}
