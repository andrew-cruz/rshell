#ifndef OR_H
#define OR_H

#include "../header/Shell.h"

class Or : public Shell{
protected:
    vector<Shell*> cmdOr;
public:
    Or();
    Or(string);
    Or(Shell*, Shell*);
    //Inherited
    void read();
    void getCommand();
    void parse();
    void parse(string);
    void execute();
    bool getSuccess(int);
};

#endif
