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
}