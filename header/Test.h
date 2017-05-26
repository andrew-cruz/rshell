#ifndef TEST_H
#define TEST_H
#include "../header/Shell.h"
#include <string>
#include <vector>

using namespace std;

class Test : public Shell {
    protected:
        string testStr;
        //vector<Shell*> cmdTest;
    public:
    	Test();
    	Test(string);
    	//Inherited
    	void read();
        void getCommand();
    	void parse();
    	void parse(string);
    	void execute();
    	bool getSuccess(int);
};
#endif
