#include <iostream>
#include <string>
#include <stdio.h>
#include "../header/Shell.h"
#include "../header/Command.h"

using namespace std;

//Empty shell constructor
Shell::Shell() {}

/*
	@desc: reads in user input, parses the input, and execute the input
		   if user inputs exit, terminates the program

	@param: na
	@return: void
*/
void Shell::read() {
	bool leave = false;

	while (!leave) {

		Shell* a = new Command();
		cout << "$ ";
		getline(cin, a->line);

		if (a->line == "exit") {
			cout << endl;
			break;
		}

		a->parse();
		a->execute();
	}
}

//Function is overwritten in child classes
void Shell::parse() {}
