#include <iostream>
#include "../header/Shell.h"
#include "../header/Command.h"

using namespace std;

int main() {
	Shell* shell = new Command();

	shell->read();

	return 0;
}
