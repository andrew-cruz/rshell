#include "../header/Para.h"

// Para::Para(string str){
//     // Para::parse(str);
// }

// void Para::parse(string parseString){

// }

Para::Para(string str){
    MonoShell::MonoShell(str);
    Para::parse();
}

Para::Para(Shell* sPtr){
    cmdPara.push_back(sPtr);
}

void Para::parse(string a){
    cout << "Parsing A\n";


}

void Para::execute(){
    cout << "Executing somethin\n";
}
