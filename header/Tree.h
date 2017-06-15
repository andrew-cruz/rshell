#ifndef TREE_H
#define TREE_H

#include "Shell.h"

class Tree {
private:
    Shell* root;
public:
    Tree(string);
    void printTree();
    bool isOperator(Shell*);
    bool isOperator(const char&);
    Shell* constructTree(const string&);
    Shell* shellPtrConstruct(const string&);
    vector<Shell*> infixToPostfix(const vector<Shell*>&);
    vector<Shell*> setVector(const string&);
    Shell* getRoot();

    bool precedenceGt(Shell*, Shell*);
    int weight(Shell*);
    bool isArrow(Shell*);

};


#endif
