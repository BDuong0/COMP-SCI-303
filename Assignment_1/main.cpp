#include "function.h"

int main() {
    ifstream inputFileStream;
    ifstream copyOf_inputFileStream;

    cout << "Opening file A1input.txt." << endl;
    inputFileStream.open("A1input.txt");
    copyOf_inputFileStream.open("A1input.txt");

    // Check to see if the fule was successfuly opened
    if (!inputFileStream.is_open()) {
        cout << "Could not open file A1input.txt.\n" << endl;
        return false;
    }
    else {
        cout << "Successfully opened A1input.txt file\n" << endl;
        cout << "---------------" << endl;

        // Read A1input.txt into an array
        int array_size = count_number_of_items_in_textFile(inputFileStream);
        int* returnedArray = add_items_to_array(copyOf_inputFileStream, array_size);

        cout << "Q1:1 Check if a integer exist in the array:" << endl;
        find_integer_in_array(returnedArray, array_size, 1);
        cout << endl << endl;

        cout << "Q1:2 Modify integer in the array:" << endl;
        modify_integer_in_array(returnedArray, 3, 12);
        cout << endl << endl;

        cout << "Q1:3 Add a new integer to the end of the array:" << endl;
        pushback_integer_to_array(returnedArray, array_size, 21);
        cout << endl << endl;

        cout << "Q1:4 Take a index of an array and replace the value with 0:" << endl;
        remove_integer_from_array(returnedArray, 80);
        cout << endl;

        delete[] returnedArray;
    }

}