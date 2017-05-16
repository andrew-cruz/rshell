#include "../header/Command.h"
#include <iostream>
#include <sys/wait.h>
#include  <sys/types.h>
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

using namespace std;

Command::Command(){}

Command::Command(string str){
	Command::parse(str);
}

void Command::read(){}

void Command::parse(){}

void Command::parse(string strParse){
	cmd = strParse;
}

void Command::execute(){
	//Copy cmd c string into char * str
	char* str = strdup(cmd.c_str());
	//Get rid of whitespaces and semicolons
	char* token = strtok(str, " ;");
	//Used to traverse Command
	int i  = 0;
	//Used to traverse str from white space to white space
	while(token != NULL){
		command[i] = token;
		token = strtok(NULL, " ;");
		i++;
	}
	//Set last element equal to NULL
	command[i] = NULL;

	Command::exec();
}

void Command::exec(){
	//Execute command
 	pid_t  pid;
    int    status;
    if ( (pid = fork()) < 0) {
        perror ("ERROR: forking failed\n");
        exit(1);
    }
    else if (pid == 0) {
        //In child process
        if (execvp(command[0], command) < 0) {
            perror("ERROR: exec failed\n");
            exit(1);
        }
    }
    else {
        //In parent process
        while (waitpid(-1, &status, 0) != pid)
            cout << "waiting....\n";
    }
}
