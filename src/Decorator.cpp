#include "../header/Decorator.h"
#include "../header/Command.h"
#include "../header/Paran.h"
#include <iostream>

using namespace std;

Decorator::Decorator(){

}

Decorator::Decorator(string str){
    Decorator::parse(str);
}

void Decorator::parse(string strParse){
    string temp;
    // int cnt = 0;

    for(unsigned i = 0; i < strParse.length(); i++){
       if(strParse.at(i) == '(' || strParse.at(i) == ')') {
           if(temp.size() != 0){
               stkCmd.push(temp);
               temp.clear();
           }
           temp = strParse.at(i);
           stkCmd.push(temp);
           temp.clear();
       }
       else{
           temp.push_back(strParse.at(i));
       }
   }

   Decorator::parse();
}

void Decorator::parse(){
    stack<string> temp (stkCmd);

    while(!temp.empty()){
        cout << temp.top() << endl;
        temp.pop();
    }
}

void Decorator::execute(){

}
