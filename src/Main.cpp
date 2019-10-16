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
	char decider;
	bool isRunning = true;
	while (isRunning == true){
		cout << "Welcome please enter the name of your file including extensions: " << endl;
		cin >> fName;
		r.InputFile(fName);
		cout << "Would you like to run again? (y/n) " << endl;
		cin >> decider;
		if (decider == 'n' || decider == 'N'){
			break;
			isRunning = false;
		} else if (decider == 'y' || decider == 'Y'){
			r.Reset();
			isRunning = true;
		} else {
			cout << "Invalid input" << endl;
		}
	}

	return 0;
}