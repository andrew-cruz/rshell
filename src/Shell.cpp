#include <iostream>
#include <string>
#include "../header/Shell.h"

using namespace std;

Shell::Shell(){
	
}

void Shell::read(){
	string cmd; 

	cout << "Assn2$ ";
	getline(cin, cmd);

	while(cmd != "exit"){
		parse();
		execute();
		cout << "Assn2$ ";
		getline(cin,cmd);
	}

	this->cmd = cmd;
}

void Shell::parse(){}