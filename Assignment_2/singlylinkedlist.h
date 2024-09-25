#pragma once
#include <iostream>
#include <string>
using namespace std;


template <typename data_type>
struct Node {
	// Data Fields
	data_type data;
	Node* next; // The pointer to the next node.

	// Constructor
	// Creates a new Node that points to another node
	// Creates a Node containing user inputed data
	Node(const data_type& data_type, Node* next_ptr = NULL) : data(data_type), next(next_ptr) {}
};

template <typename data_type>
class SinglyLinkedList {
	private:
		Node<data_type> *head; 
		Node<data_type>* tail;
		int num_items;

	public:
		// Default constructor
		SinglyLinkedList() { 
			head = NULL;
			tail = NULL;
			num_items = 0;
		}

		int size() {
			return num_items;
		}

		bool empty() {
			if (head == NULL) {
				return true;
			}
			else {
				return false;
			}
		}

		Node<data_type>* front() {
			// Special case: The last is empty, so return error message
			if (head == NULL) {
				cout << "The list is empty" << endl;
			}
			
			return head;
		}

		Node<data_type>* back() {
		
			// Special case: The last is empty, so return error message
			if (head == NULL) {
				cout << "The list is empty" << endl;
				return head;
			}
			
			// General Case: The list is not empty, so transverse through singly linked list to find what is currently the last node
			Node<data_type>* current_node = head;

			while (current_node != NULL) {
				if (current_node->next == NULL) {
					return current_node;
					break;
				}

				current_node = current_node->next; // Advance the cursor
			}

		}

		void push_front(data_type data) {
			// Create a new node which will become the new head of the list
			Node<data_type>* temp_node = new Node<data_type>(data);

			// Special case: The last is empty, so create a new head node
			if (head == NULL) {
				head = temp_node;
				num_items += 1;
			}
			else { // General Case: The list is not empty
				temp_node->next = head;
				head = temp_node;
				num_items += 1;
			}
		}

		void push_back(data_type data) {
			// Create a new node which will become the new last node
			Node<data_type>* temp_node = new Node<data_type>(data);

			// Special case: The last is empty, so create a new head node
			if (head == NULL) {
				head = temp_node;
				num_items += 1;
				return;
			}

			// General Case: The list is not empty, so transverse through singly linked list to find what is currently the last node
			Node<data_type>* current_node = head;

			while (current_node != NULL) {
				if (current_node->next == NULL) {
					current_node->next = temp_node; // Place the new node at the end of the list
					num_items += 1;
					break;
				}

				current_node = current_node->next; // Advance the cursor
			}
		}


		void pop_front() {
			// Removes the current head of the list and makes the current 2nd element in the list the new head of the list

			// Special case: The last is empty, so create a new head node
			if (head == NULL) {
				cout << "Cannot use pop_front() on an empty list" << endl;
				return;
			}

			// Special case: The list only has one item
			if (num_items == 1) {
				head = NULL;
				return;
			}

			// General Case: The list has more than 1 item
			Node<data_type>* temp_node = head->next; // Get the 2nd element of the list

			delete head;

			head = temp_node;

			num_items -= 1;
		}

		void insert(int search_index, data_type data) {
			// insert a node before the element at a specific position

			Node<data_type>* temp_node = new Node<data_type>(data); // Create temp node which we will insert later

			// Special case: The last is empty, so create a new head node
			if (head == NULL) {
				head = temp_node;
				num_items += 1;
				return;
			}

			// Special case: Insert at the end if index is beyond the end of the list
			if (search_index > num_items) {
				push_back(data);
			}
			else { // General Case: List is not empty
				Node<data_type>* current_node = head;
			
				int listItem_number = 0;
				while (current_node != NULL) {
					// cout << listItem_number << ": " << current_node->data << endl;

					if (listItem_number == search_index - 1) {
						// Example: If we want to a node before index 3, it would look like this
							// Index 0 -> Index 1 -> Index 2(<- This is the node the if statement lands on) -> *Insert Node here* -> Index 3 -> Index 4
							// We need to modify the node at Index 2 and Index 3 so that's why I seted up the condition if (listItem_number == search_index - 1)

					
						Node<data_type>* node_to_insert_before = current_node->next;

						current_node->next = temp_node; // Placing the new node after the current_node the if statement 'if (listItem_number == search_index - 1)' landed on
						temp_node->next = node_to_insert_before; // Place the node before the node at the index the user specified
						num_items += 1;
						return;
					}

					current_node = current_node->next; // Advance the cursor
					listItem_number += 1;
				}	
			}

		}

		bool remove(int search_index) {
			// insert a node before the element at a specific position

			// Special case: List is empty
			if (head == NULL) {
				cout << "Cannot remove from empty list" << endl;
				return false;
			}

			// Special case: User wants to remove the first item of the list which is the current head
			if (search_index == 0) {
				pop_front();
				return true;
			}

			// Special case: Insert at the end if index is beyond the end of the list
			if (search_index > num_items) {
				return false;
			}
			else { // General Case: List is not empty and search_index is witin the list
				Node<data_type>* current_node = head;

				int listItem_number = 0;
				while (current_node != NULL) {
					if (listItem_number == search_index - 1) {
						// Example: If we remove the node at index 3, it would look like this
							// Index 0 -> Index 1 -> Index 2(<- This is the node the if statement lands on) -> *Remove node at Index 3* -> Index 4							

						Node<data_type>* node_to_delete = current_node->next;
						Node<data_type>* new_next_node = current_node->next->next;

						current_node->next = new_next_node;
						delete node_to_delete;
						
						num_items -= 1;
						return true;
					}

					current_node = current_node->next; // Advance the cursor
					listItem_number += 1;
				}
			}
		}

		int find(data_type search_item) {
			// Return the position of the first occurrence of item if it is found. Return the size of the list if it is not found.

			// Special case: The list is empty
			if (head == NULL) {
				return num_items;
			}

			// General Case: The list is not empty
			Node<data_type>* current_node = head;

			int listItem_number = 0;
			while (current_node != NULL) {

				if (current_node->data == search_item) {
					return listItem_number;
				}

				current_node = current_node->next; // Advance the cursor
				listItem_number += 1;
			}

			// Speical Case: The item is not found in the list.
			return num_items;
		}

		void print() {
			
			// Special case: List is empty
			if (head == NULL) {
				cout << "The singly linked list is empty" << endl;
				return;
			}

			// General Case: List is not empty
			Node<data_type>* current_node = head;

			int listItem_number = 0;
			while (current_node != NULL) {
				cout << listItem_number << ": " << current_node->data << endl;
				
				current_node = current_node->next; // Advance the cursor
				listItem_number += 1;
			}
		}
		
		
};