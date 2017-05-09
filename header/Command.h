#ifndef COMMAND_H
#define COMMAND_H

#include <iostream>
#include <vector>
#include "Shell.h"

class Command : public Shell {
protected:
	
public:
    Command();
    void parse();
    void read();
    void execute();
};

#endif
