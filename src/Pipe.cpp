#include "../header/Pipe.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

// http://www.cs.loyola.edu/~jglenn/702/S2005/Examples/dup2.html


Pipe::Pipe(){
    left = NULL;
    right = NULL;
}

void Pipe::execute() {
    int status;
    int i;

    // arguments for commands; your parser would be responsible for
    // setting up arrays like these

    // char *cat_args[] = {"cat", "scores", NULL};
    // char *grep_args[] = {"grep", "Villanova", NULL};
    // char *cut_args[] = {"cut", "-b", "1-10", NULL};

    // make 2 pipes (cat to grep and grep to cut); each has 2 fds

    int pipes[4];
    pipe(pipes); // sets up 1st pipe
    pipe(pipes + 2); // sets up 2nd pipe

    // we now have 4 fds:
    // pipes[0] = read end of cat->grep pipe (read by grep)
    // pipes[1] = write end of cat->grep pipe (written by cat)
    // pipes[2] = read end of grep->cut pipe (read by cut)
    // pipes[3] = write end of grep->cut pipe (written by grep)

    // Note that the code in each if is basically identical, so you
    // could set up a loop to handle it.  The differences are in the
    // indicies into pipes used for the dup2 system call
    // and that the 1st and last only deal with the end of one pipe.

    // fork the first child (to execute cat)

    if (fork() == 0) {
        // replace cat's stdout with write part of 1st pipe

        dup2(pipes[1], 1);

        // close all pipes (very important!); end we're using was safely copied

        close(pipes[0]);
        close(pipes[1]);
        close(pipes[2]);
        close(pipes[3]);

        // execvp(*cat_args, cat_args);
    } else {
    // fork second child (to execute grep)

        if (fork() == 0) {
            // replace grep's stdin with read end of 1st pipe

            dup2(pipes[0], 0);

            // replace grep's stdout with write end of 2nd pipe

            dup2(pipes[3], 1);

            // close all ends of pipes

            close(pipes[0]);
            close(pipes[1]);
            close(pipes[2]);
            close(pipes[3]);

            // execvp(*grep_args, grep_args);
        } else {
            // fork third child (to execute cut)

            if (fork() == 0) {
                // replace cut's stdin with input read of 2nd pipe

                dup2(pipes[2], 0);

                // close all ends of pipes

                close(pipes[0]);
                close(pipes[1]);
                close(pipes[2]);
                close(pipes[3]);

                // execvp(*cut_args, cut_args);
            }
        }
    }

    // only the parent gets here and waits for 3 children to finish

    close(pipes[0]);
    close(pipes[1]);
    close(pipes[2]);
    close(pipes[3]);

    for (i = 0; i < 3; i++)
        wait(&status);



    //========================================================

    // cout << "left:" << left->getString() << endl;
    // cout << "right:" << right->getString() << endl;

    // int fdPipe[2];
    // int pid;

    // // char* const* cat_args[] = {"cat", "scores", NULL}; //left
    // // char* const* grep_args[] = {"grep", "Villanova", NULL}; //right->

    // // make a pipe (fds go in pipefd[0] and pipefd[1])
    // pipe(fdPipe);
    // pid = fork();
    // cout << "1: PID IS: " << pid << endl;
    // if (pid == 0) {
    //     cout << "2: PID IS: " << pid << endl;
    //     // waitpid(-1, &pid, 0);
    //     // child gets here and handles "grep Villanova"
    //     // replace standard input with input part of pipe
    //     dup2(fdPipe[0], 0);
    //     cout << "3: PID IS: " << pid << endl;
    //     // close unused hald of pipe
    //     close(fdPipe[1]);
    //     cout << "4: PID IS: " << pid << endl;
    //     // execute grep
    //     right->execute();
    //     cout << "5: PID IS: " << pid << endl;
    // } else {

    //     // parent gets here and handles "cat scores"
    //     // replace standard output with output part of pipe

    //     cout << "6: PID IS: " << pid << endl;
    //     dup2(fdPipe[1], 1);
    //     // close unused unput half of pipe

    //     cout << "7: PID IS: " << pid << endl;
    //     close(fdPipe[0]);
    //     // execute cat
    //     cout << "8: PID IS: " << pid << endl;
    //     left->execute();
    //     cout << "9: PID IS: " << pid << endl;
    // }

    //==========================================================

    // int pipeChild[2];
    // int pipeParent[2];

    // pid_t pid;

    // if (pipe(pipeChild) < 0) {
    //     perror("ERROR IN PIPE CLASS: CHILD PIPE");
    //     exit(1);
    // }

    // if (pipe(pipeParent) < 0) {
    //     perror("ERROR IN PIPE CLASS: PARENT PIPE");
    //     exit(1);
    // }

    // pid = fork();

    // if(pid == -1) {
    //     perror("ERROR IN PIPE CLASS: FORK()");
    //     exit(1);
    // }

    // if(pid == 0) {
    //     cout << "hi\n";
    // } else {
    //     cout << "bye\n";
    // }
}

void Pipe::setChildren(Shell* lft, Shell* rht) {
    left = lft;
    right = rht;
}

void Pipe::printString(){
    if(left && right){
        this->left->printString();
        cout << " | ";
        this->right->printString();
    }
    else{
        cout << " | ";
    }
}

string Pipe::getString() {
    return " | ";
}
