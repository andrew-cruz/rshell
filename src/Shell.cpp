#include <iostream>
#include <string>
#include "../header/Shell.h"

using namespace std;

Shell::Shell(){
}

void Shell::read(){
	cout << "Assn2$ ";
	getline(cin,command);
	//Calls Command's Parse
	parse();
}

void Shell::parse(){
	Shell* newCmd = new Command();

	for(int i = 0; i < command.size(); ++i){
		if(command.at(i) == ';'){
			newCmd->a.push_back()

		}
		else{
			newCmd->a.push_back(command.at(i));
		}
	}

}

void Shell::print(){
	cout << cmdLine.size() << endl;
	// for(int i = 0; i < cmdLine.size(); ++i){

	// 	for(int j = 0; j < cmdLine.at(i)->cmd.size(); ++j){
	// 		cout << cmdLine.at(i)->cmd.at(j);
	// 	}
	// }
	// cout << endl;
}