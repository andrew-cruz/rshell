#include "../header/Command.h"
#include "../header/Shell.h"
#include "../header/And.h"
#include "../header/Or.h"

int main(){
	//Does not matter what type the Shell* points to because the read function for all classes is the same
	Shell* a = new Command();

	a->read();

}
