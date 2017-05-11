#ifndef SHELL_H
#define SHELL_H

#include <vector>
#include <string>

using namespace std;

class Shell {
protected:
	string line;
	char** cmdArg[100];
	// char* ok[100];
	int numCmd;
	char commandLine[100];
	char* cmd[100];
public:
	Shell();
	void read();
	void print();
	virtual void parse();
	virtual void execute() = 0;
};

#endif
