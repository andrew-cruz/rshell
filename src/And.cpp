#include <iostream>
#include "../header/And.h"
#include "../header/Or.h"
#include "../header/Command.h"

And::And() : Shell() {}

And::And(string str) {
	And::parse(str);
}

void And::read() {}

void And::parse() {}

void And::parse(string strParse){
	string parsingStr = strParse;

	while(parsingStr.length() != 0){
		if(parsingStr.find("&&") != string::npos){
			string temp = parsingStr.substr(0, parsingStr.find("&&"));
			//If substring contains || create a Shell* of type Or and push back into vector
			if( temp.find("||") != string::npos){
				Shell* tempOr = new Or(temp);
				cmdAnd.push_back(tempOr);
			}
			//If substring is just a simple command create a Shell* of type Command and push back into vector
			else{
				Shell* tempCmd = new Command(temp);
				cmdAnd.push_back(tempCmd);
			}
			//Erases the substring and reduces the string down
			parsingStr.erase( 0, parsingStr.find("&&") + 2 );
		}
		else{
			//Append && to back of string so that it goes into if statement and no need to recopy same code
			parsingStr.append("&&");
		}
	}
}

void And::execute(){
	for(unsigned i = 0; i < cmdAnd.size(); i++) {
		cmdAnd.at(i)->execute();
	}
}

bool And::getSuccess(int index){
	return cmdAnd.at(index)->getSuccess(index);
}
