#ifndef COMMAND_H
#define COMMAND_H

#define SIZE_OF_ARRAY 100

#include "Shell.h"

class Command : public Shell{
protected:
	string cmd;
	char* command[SIZE_OF_ARRAY];
public:
	Command();
	Command(string);
	//Inherited
	void read();
	void parse();
	void parse(string);
	void execute();
	//Unique to Class
	void exec();
};

#endif
