#ifndef AND_H
#define AND_H

#include "../header/Shell.h"

class And : public Shell{
protected:
	vector<Shell*> cmdAnd;
public:
	And();
	And(string);
	//Inherited
	void read();
	void parse();
	void cont();
	void parse(string);
	void execute();
};


#endif
