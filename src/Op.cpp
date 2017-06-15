#include "../header/Op.h"
#include "../header/And.h"
#include "../header/Or.h"
#include "../header/Pipe.h"
#include "../header/Arrow.h"

//Initilizes type to NULL
Op::Op() {
    type = NULL;
}

//Constructs the appropiate subclass from passed in string
Op::Op(const string& str) {
    if (str == "&&") {
        type = new And();
    }
    else if (str == "||") {
        type = new Or();
    }
}

//Calls execute on its type member variable
void Op::execute(int in, int out) {
    type->execute(in, out);
}

//Sets the children for its type member variable
void Op::setChildren(Shell* lft, Shell* rht) {
    type->setChildren(lft, rht);
}

//Returns what type of obj it is
string Op::getType() {
    return "Op";
}

//Prints its member variables
void Op::printString() {
    cout << " ";
    this->type->printString();
}

//Returns the child of the Op subclass
//Returns the one the user specifies through param
Shell* Op::getChild(string& child) {
    return type->getChild(child);
}

//Returns the string of what Subclass it is
string Op::getString() {
    return type->getString();
}
