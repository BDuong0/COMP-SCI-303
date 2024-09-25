#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

template <typename data_type>
class stack {
	private:
		vector<data_type> container;

public:
	data_type& top() {
		// find the top of the stack
		return container.back();
	}

	bool empty() const {
		return container.empty();
	}
	
	int size() {
		return container.size();
	}

	void push(const data_type& item) {
		// push item onto stack
		container.push_back(item);
	}

	void pop() {
		// Remove element from the stack
		// LIFO: Last In First Out
		container.pop_back();
	}

	void print() {
		// Special Case: the container vector is empty
		if (container.empty() == true) {
			cout << "Stack is empty" << endl;
			return;
		}
		
		// General Case: Container vector is not empty so iterate through container vector backwards and print each item
		for (int i = container.size() - 1; i >= 0; --i) {
			
			if (i == container.size() - 1) {
				cout << container[i] << " <--- Top" << endl;
			}
			else if (i == 0) {
				cout << container[i] << " <--- Bottom" << endl;
			}
			else {
				cout << container[i] << endl;
			}
		}
	}
	
	data_type average() {
		// find average value of the stack elements
		data_type total_sum = 0;

		int total_quantity = 0;
		for (int i = 0; i < container.size(); ++i) {
			total_sum += container[i];
			total_quantity += 1;
		}

		return total_sum / total_quantity;
	}
	
};