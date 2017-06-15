#include "../header/Arrow.h"
#include "../header/SubArrow.h"
#include "../header/Pipe.h"

#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

//Initilizes type to NULL
Arrow::Arrow() {
    type = NULL;
}

Arrow::Arrow(const string& str) {
    //if >, create a new RightArrow object
    if (str == ">"){    
        type = new RightArrow();
    } 
    //if >>, create a new double arrow object
    else if (str == ">>"){
        type = new RightRArrow();
    } 
    //if |, create a new Pipe object
    else if (str == "|"){ //added bar
        type = new Pipe();
    } 
    //if <, create a new leftArrow object
    else {
        type = new LeftArrow();
    }
}

void Arrow::execute(int in, int out) {
    string l = "left";
    string r = "right";
    string fileName;
    if (type->getDirection() == ">") {
        // when opening the file, make it write only, delete everything inside,
        //create a file if doesn't exist, user has read/write permission,
        //group has read/write permission
        fileName = type->getChild(r)->getString();
        out = open(fileName.c_str(), O_WRONLY | O_TRUNC | O_CREAT, 
        S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);
        
        	//If dup returns -1 we have an error
		if (dup2(in,0) == -1) {
			perror("ERROR dup2(in,0) ");
			setSuccess(false);
			return;
		}
		//IF dup returns -1 we have an error
		if (dup2(out,1) == -1) {
			perror("ERROR dup2(out,1) ");
			setSuccess(false);
			return;
		}
        
        type->getChild(l)->execute(in, out);
    }
    else if (type->getDirection() == ">>") {
         // when opening the file, make it write only, make an addendum,
        //create a file if doesn't exist, user has read/write permission,
        //group has read/write permission
        fileName = type->getChild(r)->getString();
        out = open(fileName.c_str(), O_WRONLY | O_APPEND | O_CREAT,
        S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);
        
        	//If dup returns -1 we have an error
		if (dup2(in,0) == -1) {
			perror("ERROR dup2(in,0) ");
			setSuccess(false);
			return;
		}
		//IF dup returns -1 we have an error
		if (dup2(out,1) == -1) {
			perror("ERROR dup2(out,1) ");
			setSuccess(false);
			return;
		}
        type->getChild(l)->execute(in, out);
    }
    else if (type->getDirection() == "<") {
        //when opening the file, make it read only
        fileName = type->getChild(r)->getString();
        in = open(fileName.c_str(), O_RDONLY);
        
        //If dup returns -1 we have an error
		if (dup2(in,0) == -1) {
			perror("ERROR dup2(in,0) ");
			setSuccess(false);
			return;
		}
		//IF dup returns -1 we have an error
		if (dup2(out,1) == -1) {
			perror("ERROR dup2(out,1) ");
			setSuccess(false);
			return;
		}
		
        type->getChild(l)->execute(in, out);
    }
    else if (type->getDirection() == "|") {
        type->execute(in, out);
    }
}

//Sets the children for the type obj
void Arrow::setChildren(Shell* left, Shell* right) {
    type->setChildren(left, right);
}

//Prints the children of the type obj
void Arrow::printString() {
    type->printString();
}

//Returns the direction in which the arrow is pointing
string Arrow::getDirection() {
    return type->getDirection();
}

//Gets the children of type
Shell* Arrow::getChild(string& child){
    return type->getChild(child);
}

//Returns what type of obj it is 
string Arrow::getType() {
    return "arrow";
}

//Returns the String of what type of arrow or pipe it is
string Arrow::getString() {
    return type->getString();
}
