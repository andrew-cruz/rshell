#include "../header/Command.h"
#include "unistd.h"
#include <vector>
#include <string>
// #include  <stdio.h>
// #include  <sys/types.h>
// #include <string>
// #include <string.h>
// #include <cstdlib>
// #include "sys/types.h"
// #include <sys/wait.h>
// #include <iostream>

using namespace std;

Command::Command() {
    numCmd = 0;
}


void Command::parse() {
    //Atempt number 2
        /*
            int size = 100;

            // cout << "Size of cmdArg before parsing is " << sizeof(cmdArg) << endl;
            //Will Store the each command with corrrespoding arguments
            // char* a[1000];
            char* cmd[100];
            char temp[20];

                for(int i = 0; i < size; ++i){
                    cmd[i] = NULL;
                    temp[i] = '\0';
                }
            //Initilize first index
            cmd[0] = new char[250];

            //Will be used to traverse each index in a[index]
            int indexChr = 0;

            //Used to traverse each subindex of a[index][j]
            int indexPtr = 0;

            //Used to travers cmdArg
            int indexPtrPtr = 0;

            int numCmd = 0;
            //Assignes the vector commandline input to a char array
            for(unsigned i = 0; i < line.length(); ++i){
                

                if(line.at(i) == ';' || (i + 1) == line.length()){
                    
                    if(strcmp(cmd[0]," ")){
                        cout << "EMPTY CHAR*\n";
                    }
                    else{
                        cout << "\n********************\n";

                        cout << "Pusing the " << indexPtrPtr << " command\n";
                        
                        for(int j = 0; j < indexPtr; j++ ){
                            cout << "cmd[" << j << "] is " << cmd[j] << endl;
                        }

                        cout << "\n********************\n";

                        cmdArg[indexPtrPtr] = cmd;

                        indexPtrPtr++;

                        indexPtr = 0;

                        cout << "Clearing cmd......\n";
                        memset(cmd, ' ', sizeof(temp));

                        numCmd++;
                    }
                }
                else if(line.at(i) == ' '){ //When ; is found move up in index and push new char arrat at index
                    // cmd[index][j] = '\0';
                    // numCmd++;
                    // cmd[index] = new char[250];

                    //Stores temp into cmd at indexPtr
                    cout << "else if\n";
                    

                    for(unsigned a = 0; a < sizeof(temp); a++){
                        cout << "temp[" << a << "] is " << temp[a] << endl;
                    }

                    cmd[indexPtr] = temp;
                    indexPtr++;

                    for(int j = 0 ; j < indexChr; j++){
                        cout << "Temp[" << j <<"] is " << temp[j] << endl;
                    }

                    indexChr = 0;

                    //Resets temp to empty array
                    memset(temp, '\0', sizeof(temp));
                }
                else{
                    // cout << "else\n";
                    temp[indexChr] = line.at(i);
                    indexChr++;
                }


            }

            // numCmd++;

            cout << "Number of commands pushed into cmdArg is " << numCmd << endl;

            cout << "Size of cmdArg is " << sizeof(cmdArg) << endl;

            for(int i = 0; i < numCmd; i++){
                cout << "cmdArg[" << i << "] is " << **cmdArg[i] << endl;
            }





            numCmd++;

            //Prints out what is inside of each index of cmd
            for(int i = 0; i < numCmd; i++){
                cout << "Cmd at " << i << " is "<< cmd[i] << endl;

            }


            // Now need to parse each individual index to get rid of space and semicolon

            for(int i = 0; i < numCmd; i++){

            }*/                  

    //Attempt number 1
/*
    char* cmd[100];
    char commandLine[1000];
    // Assignes the vector commandline input to a char array
    for(unsigned i = 0; i < line.length(); ++i){
        commandLine[i] = line.at(i);
    }

    //Used to get each for char array up to space or semicolon
    char* token = strtok(commandLine, " ;");

    //Used to iteate through cmd array
    int i = 0;

    //While token is not empty
    while(token != NULL){

        //Dynamically reallocte size of cmd array at index i to size of token pointer
        cmd[i] = (char*) malloc(strlen(token) + 1);
        //Copies token into command at index i
        strcpy(cmd[i], token);
        //Sets token to next char string that is seperated by space or semicolon
        token = strtok(NULL, " ;");
        //Increment counter
        i++;
    }

    cmd[i] = NULL;

    for(int j = 0; cmd[j] != NULL; j++)
            cout << "*cmd[" << j << "] is " << cmd[j] << endl;

    //cmd[i] = NULL;



    cmdArg[0] = {cmd[0]};
    cmdArg[1] = {cmd[1],cmd[2]};
    cmdArg[2] = {cmd[3],cmd[4]};
    cmdArg[3] = {cmd[5],cmd[6]};
*/


    //THIS WORKS FOR SINGLE COMMANDS ONLY
    // char* cmd[100];


    // for(unsigned i = 0; i < line.length(); i++){
        // cout << i << ") " << line.at(i) << endl;
    // }

    std::vector<string> v;
    string a;
    
    // GETTING RID OF ; AND SEPERATING COMMANDS 
    while( line.find(" ") != string::npos ){
        
        a = line.substr( 0,  line.find(" "));
        // cout << "A is " << a << endl;
        if(a.find(";") != string::npos){
            
            a.erase(a.find(";"),1);
            v.push_back(a);
            v.push_back("NULL");
        }
        else{
            v.push_back(a);
        }
        // cout << "\terasing from 0 - " << line.find(";") + 1 << endl;
        // for(unsigned i = 0; i < line.find(";") + 1; i++){
        //     cout << line.at(i) << endl;
        // }
        line.erase(0, line.find(" ") + 1);

        // for(unsigned i = 0; i < line.length(); i++){
        // cout << "\t\t" << i << ") " << line.at(i) << endl;
        // }
    }

    cout << "line is " << line << endl;

    if(line.find(";") != string::npos){
            line.pop_back();
            v.push_back(line);
            v.push_back("NULL");
    }
    else{
        v.push_back(line);
        v.push_back("NULL");
    }

    for(unsigned i = 0; i < v.size(); i++){
        cout << v.at(i) << endl;
    }


    // char* cmd1[20];
    //     cmd1[0] = a;
    //     cmd1[1] = b;
    //     cmd1[2] =  NULL;

    /*

        char* cmd1[20];
            cmd1[0] = v.at(0);
            cmd1[1] = v.at(1);
            cmd1[2] = v.at(2);
        char* cmd2[30];
            cmd2[0] = v.at(3);
            cmd2[1] = v.at(4);
            cmd2[2] = v.at(5);

        vector<char*[]> a;

            a.at(0).at(0) = v.at(0);
            a.at(0).at(1) = v.at(1);
            a.at(0).at(2) = v.at(2);

            a.at(1).at(0) = v.at(3);
            a.at(1).at(1) = v.at(4);
            a.at(1).at(2) = v.at(5); 

    */

    std::vector<char*[100]> c;
    //.at(d).at(g) = .at(i)
    int d = 0;
    int g = 0;
    for(int i = 0; i < v.size(); i++){
        if(v.at(i) == "NULL"){
            d++;
            g = 0;
        }
        char* w = v.at(i).c_str();

        c.at(d).at(g) = w;
        g++;
    }





    //GETTING RID OF SPACES WITH EACH INDIVIDUAL ARGUMENT

    // std::vector<string> args;

    // for(unsigned i = 0; i < v.size(); i++){
    //     // cout << v.at(i) << endl;
    //     //ERASES first space
    //     if(v.at(i).at(0) == ' '){
    //         v.at(i).erase(0,1);
    //     }
    //     if(v.at(i).find(" ") != string::npos){

    //         for(int j = 0; j < v.at(i).length(); j++){
    //             if(v.at(i).at(j) == ' '){
    //                 args.push_back( v.at(i).substr(0, j + 1));
    //             }
    //         }

    //         // while(v.at(i).find(" ") != string::npos){
    //         //     int i = v.at(i).find(" ");

    //         // }


    //     }
    // }


    // for(unsigned i = 0; i < v.size(); i++){
    //     cout << v.at(i) << endl;

    // }

    // // cout << "ARGS\n";
    // for(unsigned i = 0; i < args.size(); i++){
    //     cout << args.at(i) << endl;
    // }

    // std::vector<char*> g;
    // //Have to s

    // int counter = 1;
    // for(unsigned i = 0; i < v.size(); i++){


    //     //If spaces found we need to do work
    //     if(v.at(i).find(" ") != string::npos){
    //         cout << "We need work\n";
    //         cout << v.at(i) << endl;


    //     }
    //     else{
    //         char* c = new char [v.at(i).length() + 1];
    //         //char c[]
            
    //         strcpy(c, v.at(i).c_str());

    //         //char c[] = 'l','s'

    //         g.push_back(c);

            
    //         counter++;
    //     }


    // }


/********************************?*/


    // for(unsigned i = 0; i < counter - 1; ++i){
    //     cout << b[i] << endl;
    // }

    // cout << sizeof(b);
    // for(unsigned i = 0; i < line.length(); ++i){
    //     commandLine[i] = line.at(i);
    // }





  
    // //Used to get each 
    //   char* token = strtok(commandLine, " ");
      
    //   int i = 0;
    
    //   // cout << "\tSize is " << sizeof(token) << endl;


    //  while(token != NULL){
 
    //      cmd[i] = (char*) malloc(strlen(token) + 1);
    //      strcpy(cmd[i], token);
 
    //      token = strtok(NULL, " ");
    //      i++;
    //   }




}






void Command::read() {}

void Command::execute() {
    //This is the type of object that we want
    
        // char a[10] = {'e','c','h','o'};
        // char b[10] = {'h','i'};
        
        // char c[10] = "ls";
        // char d[10] = "-l";
        
        // char e[10] = "echo";
        // char f[10] = "hi";
        // char g[10] = "ls";
        // char h[10] = "-l";

        // char* cmd1[20];
        //     cmd1[0] = a;
        //     cmd1[1] = b;
        //     cmd1[2] =  NULL;
        // char* cmd2[20] = {c,d, NULL};
        // char* cmd3[20] = {e,f,g,h, NULL};

        // char** test[20];
        //     test[0] = cmd1;
        //     test[1] = cmd2;
        //     test[2] = cmd3;
    

    // pid_t  pid;
    // int    status;

    // if ((pid = fork()) < 0) {     /* fork a child process           */
    //   printf("*** ERROR: forking child process failed\n");
    //   exit(1);
    // }
    // else if (pid == 0) { 
    // /* for the child process:         */
    //   if (execvp(test[0][0], test[0]) < 0) {     /* execute the command  */
    //        printf("*** ERROR: exec failed\n");
    //        exit(1);
    //   }
    // }
    // else {   
    //               /* for the parent:      */
    //   while (waitpid(-1, &status, 0) != pid)       /* wait for completion  */
    //      cout << "WAITING....\n"  ;
    // }
}

