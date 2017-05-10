#include "../header/Command.h"
#include "unistd.h"
// #include  <stdio.h>
// #include  <sys/types.h>
// #include <string>
// #include <string.h>
// #include <cstdlib>
// #include "sys/types.h"
// #include <sys/wait.h>
// #include <iostream>

using namespace std;

Command::Command() {}

void Command::parse() {

    //Assignes the vector commandline input to a char array
    // for(unsigned i = 0; i < line.length(); ++i){
    //     commandLine[i] = line.at(i);
    // }

    // //Used to get each for char array up to space or semicolon
    // char* token = strtok(commandLine, " ;");

    // //Used to iteate through cmd array
    // int i = 0;

    // //While token is not empty
    // while(token != NULL){

    //     //Dynamically reallocte size of cmd array at index i to size of token pointer
    //     cmd[i] = (char*) malloc(strlen(token) + 1);
    //     //Copies token into command at index i
    //     strcpy(cmd[i], token);
    //     //Sets token to next char string that is seperated by space or semicolon
    //     token = strtok(NULL, " ;");
    //     //Increment counter
    //     i++;
    // }

}

void Command::read() {}

void Command::execute() {
        //test cases?
        char a[10] = "echo";
        char b[10] = "hi";
        char c[10] = "ls";
        char d[10] = "-l";

        char e[10] = "echo";
        char f[10] = "hi";
        char g[10] = "ls";
        char h[10] = "-l";



        char* cmd1[20] = {a, b, NULL};
        char* cmd2[20] = {c, d, NULL};
        char* cmd3[20] = {e, f, g, h, NULL};

        char** test[20] = {cmd1, cmd2, cmd3};


    for (int i = 0; i < 3; i++){

             pid_t pid; //signed int type; representing a process ID
             int status; //indicates status

             if ((pid = fork()) < 0) { // <0 if there's an error
                  cout << "*** ERROR: forking child process failed\n"; //msg error in forking
                  exit(1); //exits from function
             }
             else if (pid == 0) { //in the child process
                  if (execvp(test[i][0], test[i]) < 0) {  //executes the commands
                       cout << "*** ERROR: exec failed\n";  //prints out msg if error
                       exit(1); //exits from function
                  }
             }
             else { //in the parent process
                  while (waitpid(-1, &status, 0) != pid) //waits until child is dead
                     cout << "WAITING....\n"  ; //included msg for testing purposes
             }
    }
}
