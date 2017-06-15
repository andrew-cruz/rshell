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

//Macro for array size
#define ARRAY_SIZE 100

//Does not ned to initilize anything
Command::Command() {}

//Sets command to a passes in string
Command::Command(const string& str){
    command = str;
}

//Executes the command member variable
void Command::execute(int in, int out) {
	//Creates array we pass into execvp
    char* cmd[ARRAY_SIZE];
    //Copy cmd c string into char * str
	char* str = strdup(command.c_str());
	//Get rid of whitespaces, semicolons, and apostrophes
	char* token = strtok(str, " ;\"");
	//Used to traverse Command
	int i  = 0;
	//Used to traverse str from white space to white space
	while (token != NULL){
		cmd[i] = token;
		token = strtok(NULL, " ;\"");
		i++;
	}
	//Set last element equal to NULL
	cmd[i] = NULL;

    if ( strncmp( cmd[0], "exit", 4 )  == 0) {
		cout << endl;
		exit(1);
	}
	
	pid_t pid;
	int status;
	//Erro if PID is less than 0
	if ( (pid = fork()) < 0) {
        setSuccess(false);
		perror ("ERROR FORKING FAILED ");
	}
	//If 0 then we are in child process
	else if (pid == 0) {
		//If excecvp returns a -1 we have an error
		if(execvp(cmd[0], cmd) == -1) {
			setSuccess(false);
			perror("ERROR EXEC FAIL ");
			exit(1);
		}
	}
	else if(pid > 0) {
		if(waitpid(pid,&status,0) == -1) {
			perror("WAITING.. ");
		}
		if(WEXITSTATUS(status) != 0) {
			setSuccess(false);
		}
	}
}

//Prints out the string command
void Command::printString() {
    cout << command;
}

//Returns the string command
string Command::getString() {
    return command;
}
