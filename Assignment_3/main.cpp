#include "function.h";
#include "circular_queue.h";
using namespace std;

int main() {
	// Question 1

	queue<int> myQueue(10);
	myQueue.push(29);
	myQueue.push(30);
	myQueue.push(46);
	myQueue.push(24);
	myQueue.push(7);
	myQueue.push(6);
	myQueue.push(123);
	myQueue.push(81);
	myQueue.push(77);
	myQueue.push(388);

	myQueue.print();

	// Question 2

	vector<int> myVector = { 3, 9, 6, 3, 22 , 1 , 3};

	int index = linear_search(myVector, 3);

	cout << endl;
	if (index == -1) {
		cout << "Item not found" << endl;
	}
	else {
		cout << "Found " << myVector[index] << " at index " << index << endl;
	}
	cout << endl;

	// Question 3:
	cout << "Circular Queue BEFORE insertion sort: " << endl;
	myQueue.print();
	cout << endl;

	cout << "Circular Queue AFTER insertion sort: " << endl;
	myQueue.sort();
	myQueue.print();

	return 0;
}