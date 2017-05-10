#ifndef SHELL_H
#define SHELL_H

#include <vector>
#include <string>

using namespace std;

class Shell {
protected:
	string line;
<<<<<<< HEAD
	char** cmdArg[100];
	// char* ok[100];
=======
	char commandLine[100];
	char* cmd[100];
>>>>>>> 0781e6d19b37098944eacbafa106d0fd0e33176d
	int numCmd;
	// char commandLine[100];
public:
	Shell();
	void read();
	void print();
	virtual void parse();
	virtual void execute() = 0;
};

#endif
