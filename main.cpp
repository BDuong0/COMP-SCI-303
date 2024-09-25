#include "singlylinkedlist.h"
#include "stack.h"
#include <string>
using namespace std;

int main() {
	// 1. Create a stack object
	stack<int> myStack; 

	// 2. Check if stack is empty or not
	if (myStack.empty() == true) {
		cout << "The stack is empty " << endl << endl;
	}
	else {
		cout << "The stack is not empty " << endl << endl;
	}

	// 3. Insert some integer values onto the stack
	myStack.push(12);
	myStack.push(2);
	myStack.push(9);
	myStack.push(45);
	myStack.push(84);
	myStack.push(0);

	myStack.print();

	// 4. Remove an element from the stack
	myStack.pop();
	cout << endl << "myStack after pop(): " << endl;
	myStack.print();
	cout << endl;

	// 5. Find the Top of the Stack
	cout << "The item at the top of the stack is " << myStack.top() << endl << endl;

	// 6. Find average value of the stack elements
	cout << "The average value of the stack elements is " << myStack.average() << endl;

	return 0;
}