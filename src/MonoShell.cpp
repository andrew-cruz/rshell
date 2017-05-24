#include <iostream>
#include "../header/MonoShell.h"

using namespace std;

MonoShell::MonoShell(string cmdL){
    monoCmd = cmdL;
    MonoShell::parse(monoCmd);
}

MonoShell::MonoShell(Shell* monoShell){
    monoStack.push(monoShell);
}

void MonoShell::read() {}

void MonoShell::parse() {
/*
    //While string not 0
    while(monoCmd.length != 0){
        //If ( found make new para type
        //Then push back into stack
        if(monoCmd.find('(') != string::npos){
            string subtr = monoCmd.substr( monoCmd.find('('), monoCmd.rfind(')') - monoCmd.find('('));
            Shell* newPara = new Para(substr);
            monoStack.push(newPara);
            monoCmd.erase(monoCmd.find('('), monoCmd.rfind(')') - monoCmd.find('('));
        }
        //If right side has no parenthesis
        else if(monoCmd.at(0) != '('){
            monoCmd.insert(0,"(");
            monoCmd.append(")");
        }
        //NO MORE PARENTHESIS IN MONOCMD
        else{
            //If && found create substr from && to end of str and create new
            //&& obj and pass in left and right conditions
            //Take off right cmd from stack and push in new And obj into stack
            if(monoCmd.find("&&") != string::npos){
                string substring = monoCmd.substr(monoCmd.find("&&"), monoCmd.length() - 1);
                Shell* newCmd = new Command(substring);
                Shell* newAnd = new And(monoStack.top(), newCmd);
                monoStack.pop();
                monoStack.push(newAnd);
            }
            //If || found create substr from || to end of str and create new
            //|| obj and pass in left and right conditions
            //Take off right cmd from stack and push in new Or obj into stack
            else if(monoCmd.find("||") != string::npos){
                string substring = monoCmd.substr(monoCmd.find("||"), monoCmd.length() - 1);
                Shell* newCmd = new Command(substring);
                Shell* newOr = new Or(monoStack.top(), newCmd);
                monoStack.pop();
                monoStack.push(newOr);
            }

            monoCmd.clear();
        }
    }
*/
}

void MonoShell::parse(string strParse){
    string temp;
    for(unsigned i = 0; i < strParse.length(); i++){
        if(strParse.at(i) == '(' || strParse.at(i) == ')'){
            if(temp.size() != 0){
                monoVec.push_back(temp);
                temp.clear();
            }
            temp = strParse.at(i);
            monoVec.push_back(temp);
            temp.clear();
        }
        else{
            temp.push_back(strParse.at(i));
        }
    }

    cout << "Vector now is\n";

    for(unsigned i = 0; i < monoVec.size(); i++ ){
        cout << monoVec.at(i) << endl;
    }
}
