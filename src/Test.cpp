#include <iostream>
#include <stdexcept>
#include <string>
#include <sys/stat.h>
#include <cstdlib>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include "../header/Test.h"

using namespace std;

Test::Test() { }

Test::Test(const string& str) {
    test = str;
}

void Test::execute(int in, int out) {
    this->parseStr();
    pid_t pid;
    int status;
    struct stat sb;

    if (test.find("-e") != string::npos) {
       //checks if file/path exists
       //deletes -e so file/path can be provided
       test.erase(0, test.find("-e") + 2);
       //puts null at end of char*
       char* cstr = strdup(test.c_str());
       //Get rid of whitespaces
       char* token = strtok(cstr, " ");
       cstr = token;

       if ( (pid = fork() ) < 0) {
           cerr << "ERROR: forking failed\n";
       //	success = false;
           exit(1);
           // return false;
       }
       else if (pid == 0) {
           //In child process
           if(stat(cstr, &sb) == 0) {
               cout << "(True)\n";
           } else {
               cout << "(False)\n";
           }
       }
       else {
           //In parent process
           while (waitpid(-1, &status, 0) != pid) {}
       }

   //	success = true;
   } else if (test.find("-f") != string::npos) {
       //checks if the file/directory exists and is a regular file
       //deletes -f so file/path can be provided
       test.erase(0, test.find("-f") + 2);
       //puts null at end of char*
       char* cstr = strdup(test.c_str());
       //Get rid of whitespaces
       char* token = strtok(cstr, " ");
       cstr = token;
       //similar
       if ( (pid = fork()) < 0) {
           cerr << "ERROR: forking failed\n";
           //success = false;
           exit(1);
           // return false;
       }
       else if (pid == 0) {
           //In child process
           if (stat(cstr, &sb) == 0 && S_ISREG(sb.st_mode) ) {
               cout << "(True)\n";
           } else {
               cout << "(False)\n";
           }
       }
       else {
           //In parent process
           while (waitpid(-1, &status, 0) != pid) {}
       }
   //	success = true;
   } else if (test.find("-d") != string::npos) {
       //checks if the file/directory exists and is a directory
       //deletes -d so file/path can be provided
       test.erase(0, test.find("-d") + 2);
       //puts null at end of char*
       char* cstr = strdup(test.c_str());
       //Get rid of whitespaces
       char* token = strtok(cstr, " ");
       cstr = token;

       if ( (pid = fork()) < 0) {
           cerr << "ERROR: forking failed\n";
            //success =  false;
            exit(1);
            // return false;
       }
       else if (pid == 0) {
           //In child process
           if(stat(cstr, &sb) == 0 && S_ISDIR(sb.st_mode)) {
               cout << "(True)\n";
           } else {
               cout << "(False)\n";
           }
       }
       else {
           //In parent process
           while (waitpid(-1, &status, 0) != pid) {}
       }
   //	success = true;
   }
}

void Test::printString() {
    cout << test;
}

string Test::getString() {
    return test;
}

void Test::parseStr() {
    string strParse = test;
    // test        -e     bin/rshell
    if ( ( ( strParse.find("[") != string::npos) &&
		(strParse.find("]") != string::npos) )
			&& (strParse.find("test") != string::npos) ) {
			cerr << "ERROR: Can't have both test and []\n";
			return;
	}
	//finds [], then deletes it
	if ( (strParse.find("[") != string::npos) &&
		(strParse.find("]") != string::npos) ) {
			strParse.erase(strParse.find("["), 1);
			strParse.erase(strParse.find("]"), 1);
	}
	//finds excess [], errors out
	if ( (strParse.find("[") != string::npos) ||
		(strParse.find("]") != string::npos) ) {
			cerr << "ERROR: excess amount of brackets!\n";
			return;
	}
	//finds test then deletes it
	if (strParse.find("test") != string::npos) {
		strParse.erase(strParse.find("test"), strParse.find("test") + 4);
	}

	string tempFlag;
	string tempPath;
	//finds whitespace, deletes it
	while (strParse.at(0) == ' ') {
		if (!strParse.empty() ) {
			strParse.erase(0,1);
		}
	}
	//parses through user input, distinguishes flag
	for (unsigned i = 0; i < strParse.length(); ++i ) {
		if (strParse.at(i) != ' ')
			tempFlag += (strParse.at(i) );
		else
			break;
	}

	//erases whitespace found after the flag
	unsigned j = 0;
	while (j < strParse.length() ) {
		if (strParse.at(j) != '-' && strParse.at(j) == ' ')
			strParse.erase(0,1);
		++j;
	}
	//separates flag from path
	strParse.erase(0,strParse.find(tempFlag) + tempFlag.length());

	tempPath = strParse;
	if (tempPath == " ") {
		tempPath.clear();
	}

	//if within that path, a flag is hidden then distinguishes flag
	if (tempPath.find("-") != string::npos) {
		for (unsigned i = 0; i < tempPath.length(); ++i) {
			if (tempPath.at(i) != ' ')
				tempFlag += (tempPath.at(i));
			else
				break;
		}
		//separates flag from path
		tempPath.erase(0,tempPath.find(tempFlag) + tempFlag.length());
	} else if (tempFlag.empty()) {	//if either flag or path is empty, append -e
		tempFlag = "-e";
		strParse = tempFlag + " " + strParse;
	} else if (tempPath.empty()) {
		strParse = "";
		tempPath = tempFlag;
		tempFlag = "-e";
		strParse = tempFlag + " " +tempPath;
	}

	if (tempFlag == "-e") { //adds flag and path to strParse
		strParse = "";
		strParse = tempFlag + " " + tempPath;
	} else if (tempFlag == "-d") {
		strParse = "";
		strParse = tempFlag + " " + tempPath;
	} else if (tempFlag == "-f") {
		strParse = "";
		strParse = tempFlag + " " + tempPath;
	} else {
		cerr << "ERROR: INVALID FLAG!\n";
		test = "";
		return;
	}

	test = strParse;
}
