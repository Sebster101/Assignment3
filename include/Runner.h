#include <string>
using namespace std;

class Runner{
public:
	Runner ();
	~Runner();
	bool InputFile(string name);
	void Reset();

	string fileName;
	int size;
};