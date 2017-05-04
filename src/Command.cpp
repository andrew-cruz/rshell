#include "../header/Command.h"
#include <cstdlib>
#include "unistd.h"
#include "sys/types.h"
#include <sys/wait.h>

/*
private:
    char* cmd[];
*/
Command::Command() {
}

void Command::parse() {
	Shell* newCmd = new Command();
	int i;

	for( i= 0; i < command.length(); i++){
		if(command.at(i) == ';'){
			cout << "end of command\n";
		}
		else{
			newCmd->setCmd(i,command.at(i));
		}
	}

	
	newCmd->setCmd(i,'\0');
	
	newCmd->printCmd();

	cout << "End of all commands\n";
}

void Command::setCmd(int index, char value){
	cmd[index] = value;
}

void Command::read() {

}

void Command::printCmd(){
	cout << "Print fcn";
	for(int i = 0; cmd[i] != '\0'; ++i){
		cout << cmd[i];
	}
}

void Command::execute() {
    //use fork, execvp, and waitpid
    //must have a special built-in command of exit which exits your shell.
    // # character should be considered a comment.

    /*
    .If pid is greater than 0, waitpid() waits for termination of the
        specific child whose process ID is equal to pid.
    .If pid is equal to zero, waitpid() waits for termination of any child
        whose process group ID is equal to that of the caller.
    .If pid is -1, waitpid() waits for any child process to end.
    .If pid is less than -1, waitpid() waits for the termination of any child whose
        process group ID is equal to the absolute value of pid.
    */

        pid_t pid; //integer type which is capable of representing a process ID
        int status;

        if ((pid = fork()) < 0) {     //fork a child process
             printf("*** ERROR: forking child process failed\n");
             exit(1);
        }
        else if (pid == 0) {          //for the child process:
         if (execvp(*cmd, cmd) < 0) {     // execute the command
                  printf("*** ERROR: exec failed\n");
                  exit(1);
             }
        }
        else {                                  // for the parent:
             while (waitpid(-1, &status, 0) != pid)       /// wait for completion
                  ;
        }

}
