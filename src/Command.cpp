#include "../header/Command.h"
#include "unistd.h"
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
    
    // int size = 100;

    // // cout << "Size of cmdArg before parsing is " << sizeof(cmdArg) << endl;
    // //Will Store the each command with corrrespoding arguments
    // // char* a[1000];
    // char* cmd[100];
    // char temp[100];

    //     for(int i = 0; i < size; ++i){
    //         cmd[i] = NULL;
    //         temp[i] = '\0';
    //     }
    // //Initilize first index
    // cmd[0] = new char[250];

    // //Will be used to traverse each index in a[index]
    // int indexChr = 0;

    // //Used to traverse each subindex of a[index][j]
    // int indexPtr = 0;

    // //Used to travers cmdArg
    // int indexPtrPtr = 0;

    // int numCmd = 0;
    // //Assignes the vector commandline input to a char array
    // for(unsigned i = 0; i < line.length(); ++i){
        

    //     if(line.at(i) == ';' || (i + 1) == line.length()){
            
    //         cout << "if\n";
    //         cout << *cmd[0] << endl;
            
    //         if(cmd[0] == ' '){
    //             cout << "EMPTY CHAR*\n";
    //         }
    //         else{
    //             cmd[indexPtr] = NULL;


    //             cout << "\n********************\n";

    //             cout << "Pusing the " << indexPtrPtr << " command\n";
                
    //             for(int j = 0; j < indexPtr; j++ ){
    //                 cout << "cmd[" << j << "] is " << cmd[j] << endl;
    //             }

    //             cout << "\n********************\n";

    //             cmdArg[indexPtrPtr] = cmd;

    //             indexPtrPtr++;

    //             indexPtr = 0;

    //             memset(cmd, '\0', sizeof(temp));

    //             numCmd++;
    //         }
    //     }
    //     else if(line.at(i) == ' '){ //When ; is found move up in index and push new char arrat at index
    //         // cmd[index][j] = '\0';
    //         // numCmd++;
    //         // cmd[index] = new char[250];

    //         //Stores temp into cmd at indexPtr
    //         cout << "else if\n";
    //         cmd[indexPtr] = temp;
    //         indexPtr++;

    //         for(int j = 0 ; j < indexChr; j++){
    //             cout << "Temp[" << j <<"] is " << temp[j] << endl;
    //         }

    //         indexChr = 0;

    //         //Resets temp to empty array
    //         memset(temp, '\0', sizeof(temp));
    //     }
    //     else{
    //         cout << "else\n";
    //         temp[indexChr] = line.at(i);
    //         indexChr++;
    //     }
    // }

    // // numCmd++;

    // cout << "Number of commands pushed into cmdArg is " << numCmd << endl;

    // cout << "Size of cmdArg is " << sizeof(cmdArg) << endl;

    // for(int i = 0; i < numCmd; i++){
    //     cout << "cmdArg[" << i << "] is " << **cmdArg[i] << endl;
    // }





    // numCmd++;

    // //Prints out what is inside of each index of cmd
    // for(int i = 0; i < numCmd; i++){
    //     cout << "Cmd at " << i << " is "<< cmd[i] << endl;
    // }


    //Now need to parse each individual index to get rid of space and semicolon

    // for(int i = 0; i < numCmd; i++){








    // }






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




    /*
        EVERYTHING BEFORE THIS WORKS
    */

/*

                // int i = 0;

                // char* b[250];    // for(int i = 0; i < numCmd; ++i){
            //     int j = 0;
                
            //     // char* token = strtok(a[j], " ;");

            //     // cout << "Token is " << token << endl;
            //     // while(token != NULL){
            //         // b[i] = new char[250];
            //         // Dynamically reallocte size of cmd array at index i to size of token pointer
            //         // b[i] = (char*) malloc(strlen(token) + 1);
            //         //Copies token into command at index i 
            //         // strcpy(b[i], token);
            //         //Sets token to next char string that is seperated by space or semicolon
            //         // token = strtok(NULL, " ;");
            //         //Incerement counter
            //         // cout << "Token is " << token << endl;
                    
            //         j++;
            //     // }

            // }
            //     // for(int i = 0; i < numCmd; i++){
             // cout << "B at " << i << " is "<< b[i] << endl;
            // }
               

            // for(int w = 0; w < i; w++){
            //     cout << "Yes[" << w << "] is -> " << *yes[w] << endl;
            // }



            // //Used to get each for char array up to space or semicolon
            // char* token = strtok(commandLine, " ");

                
            // //Used to iteate through cmd array
            // int i = 0;

            // //While token is not empty
            // while(token != NULL){

            //     //Dynamically reallocte size of cmd array at index i to size of token pointer
            //     cmd[i] = (char*) malloc(strlen(token) + 1);
            //     //Copies token into command at index i 
            //     strcpy(cmd[i], token);
            //     //Sets token to next char string that is seperated by space or semicolon
            //     token = strtok(NULL, " ");
            //     //Incerement counter
            //     i++;
            // }

            //     cout << endl << "-----------------------\n";
            //     for(int j = 0; j < i; j++)
            //         cout << cmd[j] << endl;
            //     cout << endl << "-----------------------\n";


            //     int start = 0;
            //     for(int j = 0; j < i; j++){
            //         if( strchr(cmd[j],';') ){

            //             cout << "\n--------\nFound ; at index " << j << endl;

            //             char* a[100];

            //             for(int k = start; k < j; ++k){
            //                 a[k] = cmd[j];
            //                 cout << "a[k] is " << a[k] << endl;
            //             }
            //             start = j;

            //             cout << "Now starting is " << j << endl;
            //         }
            //     }


*/

}

void Command::read() {}

void Command::execute() {
    //     char a[10] = "echo";
    //     char b[10] = "hi";
    //     //;
    //     char c[10] = "ls";
    //     char d[10] = "-l";
    //     //;
    //     char e[10] = "echo";
    //     char f[10] = "hi";
    //     char g[10] = "ls";
    //     char h[10] = "-l";



    //     char* cmd1[20] = {a,b, NULL};
    //     char* cmd2[20] = {c,d, NULL};
    //     char* cmd3[20] = {e,f,g,h, NULL};

    //     char** test[20] = {cmd1, cmd2,cmd3};


    for(int i = 0; i < 3; i++){
             pid_t  pid;
             int    status;
             
             if ((pid = fork()) < 0) {     /* fork a child process           */
                  printf("*** ERROR: forking child process failed\n");
                  exit(1);
             }
             else if (pid == 0) { 
               /* for the child process:         */
                  if (execvp(cmdArg[i][0], cmdArg[i]) < 0) {     /* execute the command  */
                       printf("*** ERROR: exec failed\n");
                       exit(1);
                  }
             }
             else {   
                              /* for the parent:      */
                  while (waitpid(-1, &status, 0) != pid)       /* wait for completion  */
                     cout << "WAITING....\n"  ;
             }
    }
}