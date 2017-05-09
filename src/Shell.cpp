#include <iostream>
#include <string>
#include <stdio.h>
#include "../header/Shell.h"
#include "../header/Command.h"

using namespace std;

Shell::Shell(){
}

void Shell::read(){
	bool leave = false;

	while(!leave){
		Shell* a = new Command();
		cout << "Assn2$ ";
		getline(cin, a->line);
		if(a->line == "exit")
			leave = true;
		if(leave)
			break;
		a->parse();
		a->execute();
	}
}

void Shell::parse(){}

void Shell::print(){}