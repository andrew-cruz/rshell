#ifndef COMMAND_H
#define COMMAND_H

#include "Cmd.h"

class Command : public Cmd {
private:
    string command;
public:
    //Constructor
    Command();
    Command(const string&);
    //Inheritied
    void execute(int, int);
    //Getter
    void printString();
    string getString();
};

#endif
