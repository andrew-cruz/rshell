#include <iostream>
#include <iterator>
#include <queue>
#include "../header/Shell.h"
#include "../header/And.h"
#include "../header/Or.h"
#include "../header/Command.h"
#include "../header/Test.h"
#include "../header/Parentheses.h"

#define FOUND false
#define NOTFOUND true

using namespace std;

Shell::Shell() : success(false) {}

void Shell::read(){
	// bool cont = NOTFOUND;

	cout << "CS100$ ";

	//While user input
	while(getline(cin,cmdLine)){
		//Parses anything after #
		Shell::parse(cmdLine);
		//Parses user input
		Shell::parse();
		//executes command line
		Shell::execute();
		cout << "CS100$ ";
	}
}

void Shell::parse(){


	// cout << "cmdLine is \n" << cmdLine << endl;
	//While commands are still in string
	while(cmdLine.length() != 0) {
		//If multiple commands found
		if( cmdLine.find(';') != string::npos) {
			//Store begining upto first semicolon of string into a substring
			string temp = cmdLine.substr(0, cmdLine.find(";"));
			//If substring contains test, creates Shell* of type Test and push back into queue
			// cout << "cmdLine is " << cmdLine << endl;
			if( temp.find('(') != string::npos ){
				Shell* newParen = new Parentheses(temp);
				commands.push(newParen);
			}
			//If substring contains && go create Shell* of type And and push back into queue
			else if( temp.find("&&") != string::npos ){
				Shell* tempAnd = new And(temp);
				commands.push(tempAnd);
			}
			//If substring contains || create a Shell* of type Or and push back into queue
			else if( temp.find("||") != string::npos){
				Shell* tempOr = new Or(temp);
				commands.push(tempOr);
			}
			//If substring contains test or [] create a Shell* of type Test and push back into queue
			else if( (temp.find("test") != string::npos) ||
		 		( (temp.find("[") != string::npos) && (temp.find("]") != string::npos) ) ) {
				Shell* tempTest = new Test(temp);
				commands.push(tempTest);
			}
			//If substring is just a simple command create a Shell* of type Command and push back into queue
			else{
				Shell* tempCmd = new Command(temp);
				commands.push(tempCmd);
			}
			//Erases the substring and reduces the string down
			cmdLine.erase( 0, cmdLine.find(";") + 1 );
		}
		else{
			//Push back a semicolon to go into if statment so we do not rewrite same code again
			cmdLine.push_back(';');
		}
	}
}


bool Shell::getSuccess(int index){
	return false;
}
void Shell::getCommand() {
	queue<Shell*> temp(commands);

	while(!temp.empty()) {
		temp.front()->getCommand();
		temp.pop();
	}

}

void Shell::execute(){
	while(commands.size() != 0){
		commands.front()->execute();
		commands.pop();
	}
}

string Shell::getNewCmd(){
	string temp = "EMPTY";
	return temp;
}

void Shell::parse(string strParse){
	//Filter out comments and exit
	if(cmdLine.find("#") != string::npos){
		cmdLine.erase( cmdLine.find("#"), cmdLine.size() - 1 );
		if(cmdLine.size() == 1)
			cmdLine.clear();
	}

	// cout << "cmdLine is " << cmdLine << endl;
}
