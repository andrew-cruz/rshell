#include "../header/Command.h"
#include "unistd.h"
#include <vector>
#include <string>

using namespace std;

//Empty constructor
Command::Command() {}

/*
    @desc Parses through user input by storing each command and argument in
          an index of the class member char pointer array
    @param na
    @return void
*/
void Command::parse() {
    //Copying string into char array and parsing is stopped if # is found
    for (unsigned i = 0; i < line.length(); ++i) {
        if (line.at(i) == '#' || line.at(i) == ';') {
            break;
        }

        commandLine[i] = line.at(i);
    }

    //Store array characters up to the first space or ;
    char* token = strtok(commandLine, " ;");
    int index = 0;

    //Moves through char array to get remaining commands and arguments
    while (token != NULL) {
        cmd[index] = (char*) malloc(strlen(token) + 1);
        strcpy(cmd[index], token);
        token = strtok(NULL, " ");
        index++;
    }
}

//Base class functionallity is kept
void Command::read() {}

/*
    @desc: Creates a process idenitfier which is then cloned using fork()
           If the pid is less than 0 then an error has occured and a perror is called
           If pid is equal to 0 it is in the child process
           If pid is greater than 0 then the parent process must wait for the child
           process to be terminted
    @param: none
    @return: void
*/
void Command::execute() {

    pid_t  pid;
    int    status;

    if ( (pid = fork()) < 0) {
        perror ("ERROR: forking failed\n");
        exit(1);
    }
    else if (pid == 0) {
        //In child process
        if (execvp(cmd[0], cmd) < 0) {
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
