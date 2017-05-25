#include "../header/Paran.h"
#include "../header/Shell.h"
#include <iostream>

using namespace std;

Paran::Paran(){

}

Paran::Paran(string str) : Decorator(str){
    Paran::parse();
}

Paran::Paran(Shell* shPtr){
    shPtr->getCommand();
}

void Paran::parse(){
}

void Paran::parse(string strParse){

}

void Paran::execute(){

}
