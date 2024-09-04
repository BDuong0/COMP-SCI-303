#include "function.h"
using namespace std;

int count_number_of_items_in_textFile(ifstream &inputFile) {
    /* Go through a text file that looks like this and count the total amount of items
        Showing contents of A1input.txt below:
        1 2 3 4 5 6 7 8 9 10
        11 12 13 14 15 16 17 18 19 20
        21 22 23 24 25 26 27 28 29 30
        31 32 33 34 35 36 37 38 39 40
        41 42 43 44 45 46 47 48 49 50
        51 52 53 54 55 56 57 58 59 60
        61 62 63 64 65 66 67 68 69 70
        71 72 73 74 75 76 77 78 79 80
        81 82 83 84 85 86 87 88 89 90
        91 92 93 94 95 96 97 98 99 100
    */
    
    string line_of_text;
    int total_array_items = 0;

    while (getline(inputFile, line_of_text)) {
        // Go through each character in a each line of text
        string temp_number = "";
        for (int i = 0; i < line_of_text.size(); i++) {
            // For loop gets all numbers except the last number: 
            // ([] = which numbers get added to the array): 
            // Example line: [1] [2] [3] [4] [5] [6] [7] [8] [9] 10

            if (isdigit(line_of_text.at(i))) {
                temp_number += line_of_text.at(i);
            }
            else if (line_of_text.at(i) == ' ') {
                // Reset temp_number and +1 iterate total_array_items so next number can be added
                total_array_items += 1;
                temp_number = "";
            }
        }

        // Get last number in the line of text:  
        // ([] = which numbers get added to the array)
        // Example line: 1 2 3 4 5 6 7 8 9 [10]
        total_array_items += 1;
    }

    return total_array_items;
};


int* add_items_to_array(ifstream& inputFile, int array_size) {
    int* myArray = new int[array_size]; 

    // Used a pointer that points to an array because I want to be able to dynamically set the array size
    // If I do this (below) Visual Studio says this is an error
        // int array[some_variable] = ... 

    // Process A1input.txt line by line
    string line_of_text;
    int current_item_count = 0;

    cout << "Reading A1input into an array..." << endl;
    cout << "A1input.txt: " << endl;

    while (getline(inputFile, line_of_text)) {

        // Go through each character in a each line of text
        string temp_number = "";
        for (int i = 0; i < line_of_text.size(); i++) {
            // For loop gets all numbers except the last number: 
            // ([] = which numbers get added to the array): 
            // Example line: [1] [2] [3] [4\ [5] [6] [7] [8] [9] 10

            if (isdigit(line_of_text.at(i))) {
                // cout << line_of_text.at(i);
                temp_number += line_of_text.at(i);
            }
            else if (line_of_text.at(i) == ' ') {
                // Add temp_number to array, reset temp_number and +1 iterate total_array_items so next number can be added
                cout << temp_number << " "; // Add number to array
                myArray[current_item_count] = stoi(temp_number);
                current_item_count += 1;
                temp_number = "";
            }
        }

        // Get last number in the line of text:  
        // ([] = which numbers get added to the array)
        // Example line: 1 2 3 4 5 6 7 8 9 [10]
        cout << temp_number << " ";
        myArray[current_item_count] = stoi(temp_number);
        current_item_count += 1;
        cout << endl;
    }
    
    cout << "DONE: Array from A1input.txt created" << endl << endl;
    return myArray;
}


int find_integer_in_array(int* int_array, int array_size, int integer_to_find) {
    // Input an array of integers into this function
    // If integer_to_find found in array, return index that integer was found

    int index_found;
    try {
        for (int i = 0; i < array_size; i++) {
            if (int_array[i] == integer_to_find) {
                cout << "Integer " << integer_to_find << " was found at index " << i;
                index_found = i;
                break;
            }
        }
    } 
    catch (...) {
        cout << "Could not find integer " << integer_to_find << " in arary";
    }

    return index_found;
}

int modify_integer_in_array(int* int_array, int index_to_modify, int new_value) {
    // Modify the value of an index in an array and return the old and new value of that index

    try {
        cout << "The old value at index " << index_to_modify << " is " << int_array[index_to_modify] << endl;
        int_array[index_to_modify] = new_value;
        cout << "The new value at index " << index_to_modify << " is " << int_array[index_to_modify];
    }
    catch (out_of_range& error) {
        cout << "Could not find index " << index_to_modify << " in array";
        cout << error.what();
    }
    
    return 0;
}

void pushback_integer_to_array(int* int_array, int array_size, int integer_to_add) {
    // You can't change the array with like the size of 100 to 101 to add an element
    // so I just made this function change the last element of the array

    try {
        cout << "The last integer in the array was " << int_array[array_size - 1] << endl;
        int_array[array_size - 1] = integer_to_add;
        cout << "Integer " << integer_to_add << " was added to the 'back' of the array" << endl;;
        cout << "The last integer in the array is now " << int_array[array_size - 1];
    }
    catch (...) {
        cout << "Could not add " << integer_to_add << " to the end of the array";
    }
}

void remove_integer_from_array(int* int_array, int index_to_remove) {
    // Replaces the value of the index to 0

    cout << "The value at index " << index_to_remove << " was " << int_array[index_to_remove] << endl;
    int_array[index_to_remove] = 0;
    cout << "The value at index " << index_to_remove << " is now " << int_array[index_to_remove] << endl;
}