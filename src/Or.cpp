#include <iostream>
#include "../header/And.h"
#include "../header/Or.h"
#include "../header/Command.h"

Or::Or() : Shell() {}

Or::Or(string str) {
	Or::parse(str);
}

void Or::read() {}

void Or::parse() {}

void Or::parse(string strParse){
	string parsingStr = strParse;

	while(parsingStr.length() != 0){
		if(parsingStr.find("||") != string::npos){
			string temp = parsingStr.substr(0, parsingStr.find("||"));
			//If substring contains || create a Shell* of type Or and push back into vector
			if( temp.find("&&") != string::npos){
				Shell* tempAnd = new And(temp);
				cmdOr.push_back(tempAnd);
			}
			//If substring is just a simple command create a Shell* of type Command and push back into vector
			else{
				Shell* tempCmd = new Command(temp);
				cmdOr.push_back(tempCmd);
			}
			//Erases the substring and reduces the string down
			parsingStr.erase( 0, parsingStr.find("||") + 2 );
		}
		else{
			//Append && to back of string so that it goes into if statement and no need to recopy same code
			parsingStr.append("||");
		}
	}
}

void Or::execute(){
	for(unsigned i = 0; i < cmdOr.size(); i++) {
		cmdOr.at(i)->execute();
	}
}
