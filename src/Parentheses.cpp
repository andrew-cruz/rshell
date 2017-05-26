#include "../header/Parentheses.h"
#include "../header/Shell.h"
#include "../header/And.h"
#include "../header/Or.h"
#include "../header/Command.h"
#include "../header/Test.h"

#include <iostream>

using namespace std;

Parentheses::Parentheses(string str){
    Parentheses::parse(str);
}
Parentheses::Parentheses(Shell* shPtr){
    cout << "Para\n";
	shPtr->getCommand();
}
void Parentheses::parse(string strParse){
    string temp = strParse;
    string temp2;
    Shell* newParan;

    if(temp.find('(') != string::npos){
        //Parse up to 1st (
        temp2 = temp.substr(temp.find('('), temp.size() - 1);
        newParan = new Parentheses(temp2);

        temp.erase(temp.find('('), temp.size() - 1);
    }

    while(temp.find(')') != string::npos){
        temp.erase( temp.find(')') , 1);
    }

    while(temp.length() != 0){
        size_t indexAnd = temp.find("&&");
        size_t indexOr = temp.find("||");
        size_t npos = string::npos;

        if( indexAnd != npos ){
            Shell* tempAnd = new And(temp);
            cmdPara.push_back(tempAnd);
            temp.erase(0, indexAnd);
        }
        else if( indexOr != npos ) {
            Shell* tempOr = new Or(temp);
            cmdPara.push_back(tempOr);
            temp.erase(0, indexOr);
        }
        else{
            if(temp.find("test") != string::npos){
                Shell* tempTest = new Test(temp);
                cmdPara.push_back(tempTest);
            }
            else{
                Shell* tempCmd = new Command(temp);
                cmdPara.push_back(tempCmd);
            }
            temp.clear();
        }
    }

}
