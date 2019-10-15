#include "TempStack.h"
#include "Runner.h"
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
	Runner r;
	string fName;
	cout << "Welcome please enter the name of your file including extensions: " << endl;
	cin >> fName;
	r.InputFile(fName);

	return 0;
}