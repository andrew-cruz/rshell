#include "../header/Command.h"

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
    pid_t  pid;
        int    status;

        if ((pid = fork()) < 0) {     //fork a child process
             printf("*** ERROR: forking child process failed\n");
             exit(1);
        }
        else if (pid == 0) {          //for the child process:
             if (execvp(*argv, argv) < 0) {     // execute the command
                  printf("*** ERROR: exec failed\n");
                  exit(1);
             }
        }
        else {                                  // for the parent:
             while (wait(&status) != pid)       /// wait for completion
                  ;
        }
*/

}
