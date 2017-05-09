#include "../header/Command.h"
#include  <stdio.h>
#include  <sys/types.h>
#include <string>
#include <string.h>
#include <cstdlib>
#include "unistd.h"
#include "sys/types.h"
#include <sys/wait.h>
#include <iostream>

using namespace std;

Command::Command() {
}

void Command::parse() {
    for(int i = 0; i < line.length(); ++i){
        commandLine[i] = line.at(i);
    }

    char* token = strtok(commandLine, " ;");
    
    int i = 0;

    while(token != NULL){

        cmd[i] = (char*) malloc(strlen(token) + 1);
        strcpy(cmd[i], token);

        token = strtok(NULL, " ");
        i++;
    }
}

void Command::read() {

}

void Command::execute() {
    cout << "EXECUTE..........\n";
     pid_t  pid;
     int    status;
     
     if ((pid = fork()) < 0) {     /* fork a child process           */
          printf("*** ERROR: forking child process failed\n");
          exit(1);
     }
     else if (pid == 0) { 
       /* for the child process:         */
          if (execvp(cmd[0], cmd) < 0) {     /* execute the command  */
               printf("*** ERROR: exec failed\n");
               exit(1);
          }
     }
     else {   
                      /* for the parent:      */
          while (waitpid(-1, &status, 0) != pid)       /* wait for completion  */
             cout << "WAITING....\n"  ;
     }
}

