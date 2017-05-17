#ifndef OR_H
#define OR_H

#include "../header/Shell.h"

class Or : public Shell{
protected:
	vector<Shell*> cmdOr;
public:
	Or();
	Or(string);
	//Inherited
	void read();
	void parse();
	void parse(string);
	void execute();
};

#endif
