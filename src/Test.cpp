#include <iostream>
#include <stdexcept>
#include "../header/Shell.h"
#include "../header/And.h"
#include "../header/Or.h"
#include "../header/Command.h"
#include "../header/Test.h"
using namespace std;

Test::Test() : Shell() {}

Test::Test(string str) {
	Test::print(str);
	Test::parse(str);
}

void Test::read() {}
void Test::parse() {}
void Test::parse(string strParse) {
    string parsingStr = strParse;

	while(parsingStr.length() != 0){
		if(parsingStr.find("test") != string::npos){
			string temp = parsingStr.substr(0, parsingStr.find("test"));
			//If substring contains || create a Shell* of type Or and push back into vector
			if( temp.find("||") != string::npos){
				Shell* tempOr = new Or(temp);
				cmdTest.push_back(tempOr);
			} else if( temp.find("&&") != string::npos ) {
				Shell* tempAnd = new And(temp);
				cmdTest.push_back(tempAnd);
			}
			//If substring is just a simple command create a Shell* of type Command and push back into vector
			else {
				Shell* tempCmd = new Command(temp);
				cmdTest.push_back(tempCmd);
			}
			//Erases the substring and reduces the string down
			parsingStr.erase( 0, parsingStr.find("test") + 4 );
		}
		else {
			//Append && to back of string so that it goes into if statement and no need to recopy same code
			parsingStr.append("test");
		}
	}

}

void Test::print(string str) {
	for (unsigned i = 0; i < str.length(); ++i) {
	//	str[i]->
	}
}
void Test::execute() {
	cout << "in test::execute\n";

   // if()

// if() { //if first char is '-'
// 	if -e
// 		then checks if the file/directory exists
// 		if(exists) {
// 			cout << "(True)\n";
// 			success == true
// 		} else {
// 			cout << "(False)\n";
// 			success == false;
// 		}
// 	else if -f
// 		then checks if the file/directory exists and is a regular file
// 		using S_ISREG

// 	else if -d
// 		then checks if the file/directory exists and is a directory
// 		using S_ISDIR
// }
// else
// 	do -e //perhaps append "-e"?

}
bool Test::getSuccess(int index) {
    return cmdTest.at(index)->getSuccess(index);
}



//need to work with || and &&
//works with []
//must use stat() command
	//S_ISDIR and S_ISREG macros
/*
parse first "word" : test

	if( temp.find("test") != string::npos ){
				Shell* tempTest = new Test(temp);
				commands.push(tempTest);
			}



if (word is test) {
	then parse "word" : flags

	if(first char is '-') {
		if -e
			then checks if the file/directory exists
			if(exists) {
				cout << "(True)\n";
				success == true
			} else {
				cout << "(False)\n";
				success == false;
			}
		else if -f
			then checks if the file/directory exists and is a regular file
			using S_ISREG

		else if -d
			then checks if the file/directory exists and is a directory
			using S_ISDIR
	}
	else
		do -e //perhaps append "-e"?
}
else
	... continues as usual

*/
