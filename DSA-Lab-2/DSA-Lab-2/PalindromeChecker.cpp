#include<iostream>
#include<string>
#include<cctype>

using namespace std;

template<class Type>
class Stack {
private:

	int top;
	int maxSize;
	Type* stack;

public:

	Stack(int maxSize) {
		top = -1;
		this->maxSize = maxSize;
		stack = new Type[maxSize];
	}

	bool isFull() {
		return (top == maxSize - 1);
	}
	bool isempty() {
		return (top == -1);
	}
	~Stack() {
		delete[] stack;
	}
	void push(Type item) {
		if (isFull()) {
			cout << "stack Overflow" << endl;
		}
		else {
			top++;
			stack[top] = item;
		}
	}
	void pop(Type& item) {
		if (isempty()) {
			cout << "stack underflow" << endl;
		}
		else {
			item = stack[top];
			top--;
		}
	}
};

int main() {
	int max;
	cout << "enter size:  ";
	cin >> max;
	cin.ignore();
	Stack<char>* palindrome = new Stack<char>(max);

	string inputString, outputString, filteredString;

	cout << "Enter a String:  ";
	getline(cin, inputString);

	for (int i = 0; i < inputString.size(); i++) {
		char character = inputString[i];
		if (isalnum(character)) {
			if(isupper(character)){
				character = tolower(character);
			}
			filteredString += character; 
		}
			
	}

	for (int i = 0; i < filteredString.size(); i++) {
		char character = filteredString[i];
		palindrome->push(character);
	}

	while (!palindrome->isempty()) {
		char character;
		palindrome->pop(character);
		outputString += character;
	}

	if (filteredString == outputString) {
		cout << "String is a palindrome \n";
	}
	else {
		cout << "String is not a palindrome \n";
	}

	delete palindrome;

	return 0;
}
