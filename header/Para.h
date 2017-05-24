#ifndef PARA_H
#define PARA_H

#include "MonoShell.h"

class Para : public MonoShell{
  private:
    vector<Shell*> cmdPara;
  public:
    Para();
    // Para(string){};
    Para(string);


};

#endif
