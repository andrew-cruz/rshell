#include "../header/Arrow.h"
#include "../header/SubArrow.h"

#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>


Arrow::Arrow() {
    type = NULL;
}

Arrow::Arrow(const string& str){
    // cout << "Creating Arrow " << str << endl;
    if (str == ">"){
        type = new RightArrow();
    }
    else if (str == ">>"){
        type = new RightRArrow();
    }
    else if (str == "|"){ //added bar
        type = new Pipe();
    }
    else {
        type = new LeftArrow();
    }
}

void Arrow::execute() {

    char a[] = "cat";
    int in, out;
    char *grep_args[] = {a, NULL};

    // open input and output files

    in = open("test.txt", O_RDONLY);
    out = open("out.txt", O_WRONLY | O_TRUNC | O_CREAT, S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);

    // replace standard input with input file

    dup2(in, 0);

    // replace standard output with output file

    dup2(out, 1);

    // close unused file descriptors

    close(in);
    close(out);

    // execute grep

    execvp("cat", grep_args);


}

void Arrow::setChildren(Shell* left, Shell* right) {
    type->setChildren(left,right);
}

void Arrow::printString() {
    type->printString();
}

string Arrow::getDirection() {
    return type->getDirection();
}

Shell* Arrow::getChild(string& child){
    return type->getChild(child);
}

string Arrow::getType() {
    return "arrow";
}

string Arrow::getString() {
    return type->getString();
}
