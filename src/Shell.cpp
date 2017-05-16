#include <iostream>
#include "../header/Shell.h"
#include "../header/And.h"
#include "../header/Or.h"
#include "../header/Command.h"

using namespace std;

Shell::Shell(){}

void Shell::read(){
	bool cont = true;
	while(cont){
		cout << "CS100$ ";
		//GEts user input
		getline(cin,cmdLine);
		//Parses anything after #
		Shell::parse(cmdLine);
		//If exit is found sets cont to false
		cont = Shell::cont();
		//Parses user input
		Shell::parse();
		//Executes input
		Shell::execute();
	}
}

void Shell::parse(){
	if(cmdLine.find("exit") != string::npos){
		cmdLine.erase( cmdLine.find("exit"), cmdLine.size() - 1 );
	}
	//While commands are still in string
	while(cmdLine.length() != 0) {
		//If multiple commands found
		if( cmdLine.find(';') != string::npos) {
			//Store begining upto first semicolon of string into a substring
			string temp = cmdLine.substr(0, cmdLine.find(";"));
			//If substring contains && go create Shell* of type And and push back into queue
			if( temp.find("&&") != string::npos ){
				Shell* tempAnd = new And(temp);
				commands.push(tempAnd);
			}
			//If substring contains || create a Shell* of type Or and push back into queue
			else if( temp.find("||") != string::npos){
				Shell* tempOr = new Or(temp);
				commands.push(tempOr);
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

bool Shell::cont(){
	if(cmdLine.find("exit") != string::npos)
		return false;
	else
		return true;
}

void Shell::parse(string strParse){
	//Filter out comments and exit
	if(cmdLine.find("#") != string::npos){
		cmdLine.erase( cmdLine.find("#"), cmdLine.size() - 1 );
	}
}

void Shell::execute(){
	while(commands.size() != 0){
		commands.front()->execute();
		commands.pop();
	}
}
