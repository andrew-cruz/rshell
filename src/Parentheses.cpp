#include "../header/Parentheses.h"

#include <iostream>
#include <stack>

using namespace std;

Parentheses::Parentheses() {}

Parentheses::Parentheses(string str){
    // Parentheses::parse(str);
    Parentheses::setVector(str);
    Parentheses::parse(str);
    Parentheses::parse();
}

void Parentheses::parse() {
    stack<string> tempStrStk;

    for(unsigned i = 0; i < precVec.size(); i++){
        //POP OUT OF STACK UNTIL ReACHING (
        if(v.at(i) == ")"){
            //pop
            tempStrStk.top();
        }
        else{
            tempStrStk.push(precVec.at(i));
        }
    }





}

void Parentheses::parse(string str){
    for(unsigned i = 0; i < precVec.size(); i++){
        cout << "precedenceStk[" << i << "] = " << precVec.at(i) << endl;
    }
}

void Parentheses::setVector(string str){
    string temp;
    for(unsigned i = 0; i < str.length(); i++){
        if( str.at(i) == '(' || str.at(i) == ')' ){
            if( !temp.empty() ){
                precVec.push_back(temp);
                temp.clear();
            }
            temp = str.at(i);
            precVec.push_back(temp);
            temp.clear();
        }
        else{
            temp.push_back( str.at(i) );
        }
    }

    if(!temp.empty()){
        precVec.push_back(temp);
    }
}

string Parentheses::getNewCmd(){
    return newCmds;
}
