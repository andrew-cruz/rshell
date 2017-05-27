#include <iostream>
#include "../header/And.h"
#include "../header/Or.h"
#include "../header/Command.h"
#include "../header/Test.h"

Or::Or() : Shell() {}

Or::Or(string str) {
	Or::parse(str);
}

Or::Or(Shell* left, Shell* right){
	cmdOr.push_back(left);
	cmdOr.push_back(right);
}
void Or::getCommand() {
	for(unsigned i = 0; i < cmdOr.size(); ++i) {
		if(i != 0 )
			cout << " || ";
		cmdOr.at(i)->getCommand();
		if( i == 0)
			cout << " || ";
	}
}

void Or::parse(string strParse){
	string parsingStr = strParse;

	while(parsingStr.length() != 0){
		if(parsingStr.find("||") != string::npos){
			string temp = parsingStr.substr(0, parsingStr.find("||"));
			//If substring contains || create a Shell* of type Or and push back into vector
			if( temp.find("&&") != string::npos){
				Shell* tempAnd = new And(temp);
				cmdOr.push_back(tempAnd);
			} else if( temp.find("test") != string::npos ){
				Shell* tempTest = new Test(temp);
				cmdOr.push_back(tempTest);
			} else if( (temp.find("[") != string::npos) &&
				(temp.find("]") != string::npos) ) {
				Shell* tempTest = new Test(temp);
				cmdOr.push_back(tempTest);
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
		// cout << "Or execute\n";
		cmdOr.at(i)->execute();
		if( cmdOr.at(i)->getSuccess(i) ){
			break;
		}
	}
}

bool Or::getSuccess(int index){
	return cmdOr.at(index)->getSuccess(index);
}
