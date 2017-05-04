#include "../header/Command.h"
#include "unistd.h"
#include "sys/types.h"
#include <cstdlib>
#include <sys/wait.h>
#include <string>

/*
private:
    char* cmd[];
*/
Command::Command() {
}

void Command::parse() {
    // Command* a = new Command();

    // int j = 0;
    // for(int i = 0; i < command.length(); ++i){
    //     if(command.at(i) == ';'){
    //         a->cmd.push_back('\0');
    //         cmdLine.push_back(a);
    //         j = 0;
    //     }
    //     else{
    //         a->cmd.push_back(command.at(i));
    //         j++;
    //     }
    // }

    // a->cmd.push_back('\0');
    //         cmdLine.push_back(a);

    // Shell::print();
}

void Command::read() {

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

        // pid_t pid; //integer type which is capable of representing a process ID
        // int status;

        // if ((pid = fork()) < 0) {     //fork a child process
        //      printf("*** ERROR: forking child process failed\n");
        //      exit(1);
        // }
        // else if (pid == 0) {          //for the child process:
        //  if (execvp(*cmd, cmd) < 0) {     // execute the command
        //           printf("*** ERROR: exec failed\n");
        //           exit(1);
        //      }
        // }
        // else {                                  // for the parent:
        //      while (waitpid(-1, &status, 0) != pid)       /// wait for completion
        //           ;
        // }

}
