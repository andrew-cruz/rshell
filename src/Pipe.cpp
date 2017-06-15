#include "../header/Pipe.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

//Initialize member obj to BULL
Pipe::Pipe() {
    left = NULL;
    right = NULL;
}

//Execute both left and right children
void Pipe::execute(int in, int out) {
    int pipefd[2];
    int pid;

    // make a pipe (fds go in pipefd[0] and pipefd[1])
    pipe(pipefd);
    pid = fork();

    if (pid == 0) { // in child process
        // replace stdin with input
        if (dup2(pipefd[0], 0) == -1) {
            perror("ERROR dup2(in,0) ");
            exit(1);
        }
        // close unused half of pipe
        close(pipefd[1]);
        right->execute(pipefd[0], pipefd[1]);
    } else { //parent process
        // replace stdout with pipie's output
        if(dup2(pipefd[1], 1) == -1) {
            perror("ERROR dup2(in,1) ");
            exit(1);
        }

        // close unused input half of pipe
        close(pipefd[0]);
        left->execute(pipefd[1], pipefd[0]);
    }
}

//Sets the left and right children to passes in parameters
void Pipe::setChildren(Shell* lft, Shell* rht) {
    left  = lft;
    right = rht;
}

//Prints the children of the obj
void Pipe::printString() {
    if (left && right){
        this->left->printString();
        cout << " | ";
        this->right->printString();
    } else {
        cout << " | ";
    }
}

//Returns the class it is in
string Pipe::getString() {
    return " | ";
}

//Returns what type of obj it is
string Pipe::getDirection() {
    return "|";
}

Shell* Pipe::getChild(string& child) {
    if (child == "left") {
        return left;
    }

    else if (child == "right") {
        return right;
    }
    return NULL;
}
