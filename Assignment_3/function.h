#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;


template<typename Item_Type>
int linear_search(vector<Item_Type>& items, Item_Type target, int search_index = 0, int lastoccurance_index = -1) {
	// Searches through a vector for the index that represnets the last occurance of the target element you want to search for
	
	if (search_index == items.size() && lastoccurance_index != -1) { // We iterated through the entire vector from left to right, and we have found the last occurance of our target
		return lastoccurance_index;
	} else if (search_index == items.size() && lastoccurance_index == -1) { // Return -1, if target is nowhere to be found ni the vector
		return -1;
	} else if (target == items[search_index]) { // On 1st iteration: Compare target with items[0]
		
		// Output to see the indexes of all occurances of target: cout << search_index << endl;
		lastoccurance_index = search_index;
		
		return linear_search(items, target, search_index + 1, lastoccurance_index); // Repeat comparison for items[0 -> items.size() - 1]
	} else { // target didn't match current search_index so advance the search_index +1 to the right
		return linear_search(items, target, search_index + 1, lastoccurance_index); 
	}
}

