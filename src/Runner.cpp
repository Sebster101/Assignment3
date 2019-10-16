#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include "TempStack.h"
#include "Runner.h"

using namespace std;

genStack<char> P(4);
genStack<char> B(4);
genStack<char> CB(4);
char tester;

genStack<int> Pline(4);
genStack<int> Bline(4);
genStack<int> CBline(4);

Runner::Runner(){};

Runner::~Runner(){};

bool Runner::InputFile(string name){
	ifstream file1;
	file1.open(name.c_str());
	string line;
	char character;
	int lineLength;
	int lineNum = 1;
	bool noError = true;


	if (file1.is_open()){
		while (getline(file1, line) && noError == true)
		{
			lineNum++;
			lineLength = line.length();
			for (int i = 0; i < lineLength; i++){
				character = line[i];
				switch (character){

					case('('):
					{
						P.push(line[i]);
						Pline.push(lineNum);
						break;
					}
					case(')'):
					{
						if (P.isEmpty()){
							cout << "Failed";
							noError = false;
							int lineReport = Pline.pop();
							cout << "Error on line "<< lineReport << "Expected (" << endl;
						} else {
							char pop;
							pop = P.peek();
							if (pop = '('){
								P.pop();
							}
						}
						break;
					}
					case('['):
					{
						B.push(line[i]);
						Bline.push(lineNum);
						break;
					}
					case(']'):
					{
						if (B.isEmpty()){
							cout << "Failed";
							noError = false;
							int lineReport = Bline.pop();
							cout << "Error on line "<< lineReport << "Expected [" << endl;
						} else {
							char pop;
							pop = B.peek();
							if (pop = '['){
								B.pop();
							}
						}
						break;
					}
						case('{'):
						{
						CB.push(line[i]);
						CBline.push(lineNum);
						break;
					}
						case('}'):
						{
						if (CB.isEmpty()){
							cout << "Failed";
							noError = false;
							int lineReport = CBline.pop();
							cout << "Error on line "<< lineReport << " Expected {" << endl;
						} else {
							char pop;
							pop = CB.peek();
							if (pop = '}'){
								CB.pop();
							}
						}
					}
					break;
					
				};
			}

		}

		if (noError = true){
			if (!P.isEmpty()){
				noError = false;
				int lineReport = Pline.pop();
				cout << "Error on line "<< lineReport << " Expected )" << endl;
			} else if (!B.isEmpty()){
				noError = false;
				int lineReport = Bline.pop();
				cout << "Error on line "<< lineReport << " Expected ]" << endl;
			} else if (!CB.isEmpty()){
				noError = false;
				int lineReport = CBline.pop();
				cout << "Error on line "<< lineReport << " Expected }" << endl;
			} else {
				cout << "No errors found" << endl;
			}
		}

	}
	else{
		cout << "File not Found" << endl;
	}
}
void Runner::Reset(){
	while (!P.isEmpty()){
		P.pop();
	}
	while (!B.isEmpty()){
		B.pop();
	}
	while (!CB.isEmpty()){
		CB.pop();
	}
	while (!Pline.isEmpty()){
		Pline.pop();
	}
	while (!Bline.isEmpty()){
		Bline.pop();
	}
	while (!CBline.isEmpty()){
		CBline.pop();
	}
}