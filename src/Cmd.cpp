#include "../header/Cmd.h"
#include "../header/Test.h"
#include "../header/Command.h"
#include <iostream>

Cmd::Cmd(){
    type = NULL;
}

Cmd::Cmd(const string& str) {
    if( ( (str.find("test") != string::npos) || (str.find("[") != string::npos)) && (str.find('.') == string::npos) ){
        // cout << "Creating test " << str << endl;
        type = new Test(str);
    }
    else{
        type = new Command(str);
    }
}

void Cmd::execute() {
    type->execute();
}

string Cmd::getType() {
    return "Cmd";
}

void Cmd::printString() {
    cout << " ";
    this->type->printString();
}

string Cmd::getString() {
    return type->getString();
}

Shell* Cmd::getChild(string& child){
    return type->getChild(child);
}
