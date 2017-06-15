#include "../header/Cmd.h"
#include "../header/Test.h"
#include "../header/Command.h"
#include <iostream>

//Initilizes type varibale to NULL
Cmd::Cmd(){
    type = NULL;
}

//Creates the appropiate Cmd subclass obj depending on what str is
Cmd::Cmd(const string& str) {
    if ( ( (str.find("test") != string::npos) || 
        (str.find("[") != string::npos) )
        && (str.find('.') == string::npos) ) {
        type = new Test(str);
    }
    else {
        type = new Command(str);
    }
}

//Executes type
void Cmd::execute(int in, int out) {
    type->execute(in, out);
}

//Returns what type of obj it is
string Cmd::getType() {
    return "Cmd";
}

//Prints out the children of the subclass type
void Cmd::printString() {
    cout << " ";
    this->type->printString();
}

//Returns the string  of what type of subclass type is
string Cmd::getString() {
    return type->getString();
}

//Returns the child of type variable
Shell* Cmd::getChild(string& child){
    return type->getChild(child);
}
