#include "../header/Parentheses.h"

#include <iostream>
#include <stack>

using namespace std;

Parentheses::Parentheses() {}

Parentheses::Parentheses(string str){
    Parentheses::parse(str);
}

void Parentheses::parse(string str){
    // cout << "Passes in str is " << str << endl;

    stack<string> precedenceStk;
    string temp;
    for(unsigned i = 0; i < str.length(); i++){
        if( str.at(i) == '(' || str.at(i) == ')' ){
            if( !temp.empty() ){
                precedenceStk.push(temp);
                temp.clear();
            }
            temp = str.at(i);
            precedenceStk.push(temp);
            temp.clear();
        }
        else{
            temp.push_back( str.at(i) );
        }
    }

    if(!temp.empty()){
        precedenceStk.push(temp);
    }

    while(!precedenceStk.empty()){
        cout << precedenceStk.top() << endl;
        precedenceStk.pop();
    }
}

string Parentheses::getNewCmd(){
    return newCmds;
}
