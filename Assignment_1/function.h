#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int count_number_of_items_in_textFile(ifstream &inputFile);

int* add_items_to_array(ifstream& inputFile, int array_size);

int find_integer_in_array(int* int_array, int array_size, int integer_to_find);

int modify_integer_in_array(int* int_array, int index_to_modify, int new_value);

void pushback_integer_to_array(int* int_array, int array_size, int integer_to_add);

void remove_integer_from_array(int* int_array, int index_to_remove);