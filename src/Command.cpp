#include "../header/Command.h"
#include <iostream>
#include <sys/wait.h>
#include <sys/types.h>
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdexcept>

using namespace std;

Command::Command() : Shell() {}

Command::Command(string str) {
	Command::parse(str);
}

void Command::parse(string strParse) {
	cmd = strParse;
}

void Command::getCommand() {
	cout << cmd << " ";
}

void Command::execute(){
	//Copy cmd c string into char * str
	// cout << "We are executing " << cmd << endl;
	char* str = strdup(cmd.c_str());
	//Get rid of whitespaces, semicolons, and apostrophes
	char* token = strtok(str, " ;\"");
	//Used to traverse Command
	int i  = 0;
	//Used to traverse str from white space to white space
	while(token != NULL){
		command[i] = token;
		token = strtok(NULL, " ;\"");
		i++;
	}
	//Set last element equal to NULL
	command[i] = NULL;

	Command::exec();
}



bool Command::getSuccess(int index){
	return success;
}

void Command::exec(){
	//Execute command
	pid_t pid;
	int status;

	if ( (pid = fork()) < 0) {
		perror ("ERROR: forking failed\n");
		success = false;
		exit(1);
		// return false;
	}
	else if (pid == 0) {
		//In child process
		if (execvp(command[0], command) < 0) {
			perror("ERROR: exec failed\n");
			success = false;
			exit(1);
			// return false;
		}
	}
	else {
		//In parent process
		while (waitpid(-1, &status, 0) != pid) {}
	}

	success = true;
}
