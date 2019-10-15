#ifndef genStack_h
#define genStack_h

template <class tempStack>
class genStack
{
public:
	int first;
	int max;
	tempStack *tempStackArray;

	genStack();
	genStack(int sizeStack);
	~genStack();
	tempStack peek();
	tempStack pop();
	void push(tempStack input);
	
	bool isEmpty();

};

template <class tempStack>
genStack<tempStack>::genStack(){};

template <class tempStack>
genStack<tempStack>::~genStack(){
	delete tempStackArray;
};

template<class tempStack>
genStack<tempStack>::genStack(int sizeStack)
{
	tempStackArray = new tempStack[sizeStack];
	max = sizeStack;
	first = -1;
}

template<class tempStack>
tempStack genStack<tempStack>::peek(){
	return tempStackArray[first];
}
template<class tempStack>
tempStack genStack<tempStack>::pop(){
	if (first != -1)
	{
		return tempStackArray[first--];
	}

	else{
		return 0;
	}
}
template<class tempStack>
void genStack<tempStack>::push(tempStack input)
{
	tempStackArray[++first] = input;
};

template <class tempStack>
bool genStack<tempStack>::isEmpty(){
	if (first == -1){
		return true;
	} else
		return false;
};


#endif