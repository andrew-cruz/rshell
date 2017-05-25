#ifndef PARAN_H
#define PARAN_H

#include "../header/Decorator.h"
#include "../header/Shell.h"

class Paran : public Decorator{
private:

public:
    //Constructor
    Paran();
    Paran(string);
    Paran(Shell*);
    //Need defintion
    void parse();
	void parse(string);
	void execute();
};

#endif
