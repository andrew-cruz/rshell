#include <iostream>
#include <string>
#include <stdio.h>
#include "../header/Shell.h"

using namespace std;

Shell::Shell(){
}

void Shell::read(){
	cout << "Assn2$ ";
	getline(cin, line);
	parse();
	execute();
}

void Shell::parse(){}

void Shell::print(){}