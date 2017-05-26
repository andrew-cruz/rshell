#include <iostream>
#include <stdexcept>
#include <string>
#include <sys/stat.h>
#include <cstdlib>
#include <unistd.h>
#include <sys/types.h>
#include "../header/Test.h"
using namespace std;


Test::Test() : Shell() {}

Test::Test(string str) {
	Test::parse(str);
}

void Test::getCommand() {
	cout << testStr << endl;

}
void Test::parse(string strParse) {
	//if beginning of string is "test", deletes it
	//strParse.erase(strParse.find("["));
	if( ( (strParse.find("[") != string::npos) && (strParse.find("]") != string::npos) )
		&& (strParse.find("test") != string::npos) ) {
			perror("ERROR: Can't have both test and []\n");
			exit(1);
	}

	if( (strParse.find("[") != string::npos) && (strParse.find("]") != string::npos) ) {
		strParse.erase(strParse.find("["), 1);
		strParse.erase(strParse.find("]"), 1);
	}
	if (strParse.find("test") != string::npos) {
		strParse.erase(strParse.find("test"), strParse.find("test") + 4);
	}

	//if no "-" is found, appends it to the beginning
	if(strParse.find("-") == string::npos) {
	 	string dashE = "-e ";
	 	strParse.insert(0,dashE);
	 }
	testStr = strParse;
}

void Test::execute() {
	pid_t pid;
	int status;
	struct stat sb;

	if(testStr.find("-e") != string::npos) {
		//checks if file/path exists
		//deletes -e so file/path can be provided
		testStr.erase(0, testStr.find("-e") + 2);
		//puts null at end of char*
		char* cstr = strdup(testStr.c_str());
		//Get rid of whitespaces and semicolons
		char* token = strtok(cstr, " ");
		cstr = token;

		if ( (pid = fork()) < 0) {
			perror ("ERROR: forking failed\n");
			success = false;
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

		success = true;
	} else if (testStr.find("-f") != string::npos) {
		//checks if the file/directory exists and is a regular file
		//deletes -f so file/path can be provided
		testStr.erase(0, testStr.find("-f") + 2);
		//puts null at end of char*
		char* cstr = strdup(testStr.c_str());
		//Get rid of whitespaces and semicolons
		char* token = strtok(cstr, " ");
		cstr = token;
		//similar
		if ( (pid = fork()) < 0) {
			perror ("ERROR: forking failed\n");
			success = false;
			exit(1);
			// return false;
		}
		else if (pid == 0) {
			//In child process
			if(stat(cstr, &sb) == 0 && S_ISREG(sb.st_mode)) {
				cout << "(True)\n";
			} else {
				cout << "(False)\n";
			}
		}
		else {
			//In parent process
			while (waitpid(-1, &status, 0) != pid) {}
		}
		success = true;
	} else if (testStr.find("-d") != string::npos) {
		//checks if the file/directory exists and is a directory
		//deletes -d so file/path can be provided
		testStr.erase(0, testStr.find("-d") + 2);
		//puts null at end of char*
		char* cstr = strdup(testStr.c_str());
		//Get rid of whitespaces and semicolons
		char* token = strtok(cstr, " ");
		cstr = token;

		if ( (pid = fork()) < 0) {
			perror ("ERROR: forking failed\n");
			success = false;
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
		success = true;
	} else {
		perror("ERROR: INVALID FLAG!\n");
		exit(1);
	}
}

bool Test::getSuccess(int index) {
    return success;
}
