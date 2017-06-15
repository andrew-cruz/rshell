#include "../header/Op.h"
#include "../header/And.h"
#include "../header/Or.h"
#include "../header/Pipe.h"
#include "../header/Arrow.h"


Op::Op(){
    type = NULL;
}

Op::Op(const string& str){
    // cout << "Creating op " << str << endl;
    if(str == "&&"){
        type = new And();
    }
    else if(str == "||"){
        type = new Or();
    }
    else if(str.find('|') != string::npos){
        type = new Pipe();
    }
}

void Op::execute() {
    type->execute();
}

void Op::setChildren(Shell* lft, Shell* rht) {
    type->setChildren(lft,rht);
}

string Op::getType() {
    return "Op";
}

void Op::printString() {
    cout << " ";
    this->type->printString();
}

Shell* Op::getChild(string& child){
    return type->getChild(child);
}

string Op::getString() {
    return type->getString();
}
