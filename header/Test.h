#ifndef TEST_H
#define TEST_H
#include "../header/Shell.h"
#include <string>
#include <vector>

using namespace std;

class Test : public Shell {
    protected:
    	vector<Shell*> cmdTest;
    public:
    	Test();
    	Test(string);
    	//Inherited
    	void read();
    	void parse();
    	void parse(string);
    	void execute();
    	bool getSuccess(int);
    	void print(string);
};
#endif
