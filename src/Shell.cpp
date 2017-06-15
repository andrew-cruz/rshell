#include <iostream>
#include <vector>
#include "../header/Shell.h"
#include "../header/Tree.h"


using namespace std;

//Constructor initilizes succes to true
Shell::Shell() : success(true) {}

//Used to keep accepting user input and executes user input
void Shell::read() {
    string input;
    cout << "CS100$ ";
    while(getline(cin,input)) {
        parse(input);
        //Use 0 and 1 because they are the standard FD
        execute(0, 1);
        cout << "CS100$ ";
    }
}

//Takes in the whole user input and speretes it by semicolon
//Each index in vector is each sub command line
void Shell::parse(string& str) {
    //Deletes anything after the comments
    if(str.find('#') != string::npos) {
        str.erase( str.find('#'), str.length() - str.find('#') );
    }

    //Used to hold each individual subcommand line
    vector<string> multiCmd;

    //Go thorugh entire commandline and parse
    while(str.find(';') != string::npos && !str.empty()) {
        multiCmd.push_back( str.substr(0, str.find(';') ) );
        str.erase(0, str.find(';') + 1);
    }
    //Push back remaing command into subcommands vector
    if(!str.empty() && str.find(';') == string::npos){
        multiCmd.push_back(str);
    }
    //Crates the expression tree for each subcommand and return the root
    //Root is then pushed back into vector of roots
    for(unsigned i = 0; i < multiCmd.size(); i++){
        Tree* tempTree = new Tree(multiCmd.at(i));
        roots.push_back(tempTree->getRoot());
    }
}

//Executes each root in vector once at a time
void Shell::execute(int in, int out) {
    for(unsigned i = 0; i < roots.size(); i++) {
        roots.at(i)->execute(in, out);
    }
    //Clear roots
    roots.clear();
}
//Does nothing because Shell* has no left and right children
void Shell::setChildren(Shell* lft, Shell* rht) {}

//Returns essentially what class type it is
string Shell::getType() {
    return "Shell";
}

//Prints out what class name it is
void Shell::printString() {
    cout << "Shell* " << endl;
}

//Prints out empty string because Shell has no string
string Shell::getString() {
    return "";
}

//Returns the succes member function
//Mainly used for Or op class
bool Shell::getSuccess() {
    return success;
}

//Sets Success member function
void Shell::setSuccess(bool boo) {
    success = boo;
}

//Returns empty string
string Shell::getDirection() {
    return "";
}

//Returns NULL because get Child is for its subclasses only
Shell* Shell::getChild(string& str) {
    return NULL;
}
