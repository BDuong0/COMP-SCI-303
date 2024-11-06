#pragma once

template<typename Item_Type>
class queue {
	private:
    // Initialize front and rear
    int rear_index = -1;
    int front_index = -1;

    // Circular Queue
    int num_items = 0;
    int capacity;
    Item_Type* queue_array;

    public:
        queue(int set_capacity) {
            capacity = set_capacity;
            queue_array = new Item_Type[capacity];
        }

     int size() { return num_items;  }

     bool empty() {
         if (num_items == 0) {
             return true;
         }
         else {
             return false;
         }
     }

     int get_capacity() { return capacity; }

     Item_Type front() {
         return queue_array[front_index];
     }

     Item_Type back() {
         return queue_array[rear_index];
     }

     void push(const Item_Type& item) {
         // Is queue full
         if (num_items == capacity) {
             cout << "Queue is full" << endl;
             return;
         }
         
         // Is queue empty
         if (num_items == 0) {
             front_index = 0;
         }

         num_items++;
         // In a queue, can only add elements to the rear/back end of the list
         // Debug output: cout << "Old rear_index = " << rear_index;
         rear_index = (rear_index + 1) % capacity;
         queue_array[rear_index] = item;

         // Debug output: cout << " -> New rear_index = " << rear_index << endl;
     }

     void pop() {
         // Special Case: If array is empty, then do nothing
         if (num_items == 0) {
             cout << "Cannot pop from empty queue" << endl;
         }
         // Special case: If array has one item, then revert values for front_index and rear_index that indicate empty queue
         else if (num_items == 1) {
             front_index = -1;
             rear_index = -1;                 

             num_items--;
         }
         else {
             // Debug output: cout << "front_index popped = " << front_index << " rear_index before = " << rear_index;
             front_index = (front_index + 1) % capacity;
             // Debug output: cout << " -> New front_index = " << front_index << " / New rear_index = " << rear_index << endl;
             num_items--;
         }   
     }

     void move_to_rear() {         
         if (num_items == this->capacity) {
             cout << "Queue has no more space to move front element to rear of the queue" << endl;
         }
         else {
            Item_Type front_element = queue_array[front_index];

            Item_Type store_front_element = front_element;

            this->pop();

            this->push(store_front_element);

            // Debug output: cout << "Moved " << store_front_element << " to rear" << endl;
         }
         

         ;
     }

     void print()
     {
         int element_num = 1;

         if (num_items == 0) {
             cout << "Queue is empty" << endl;
         }
         else {
             int index_to_stop_at = 0;

             // Determine at which index do we stop printing elements in the array 
             if (front_index < rear_index) {
                 index_to_stop_at = rear_index;
             } else if (front_index > rear_index) {
                 index_to_stop_at = capacity - 1;
             }
             else {
                 index_to_stop_at = front_index;
             }

             cout << "Circular Queue contents: " << endl;
             for (int i = (front_index) % capacity; i <= index_to_stop_at;
                 i++) {
                 // i represents the index of the element inside the array itself
                    // i.e The first element of a circular queue may have the index of 0 or 2
                 cout << element_num << ": " << queue_array[i] << endl;
                 element_num++;
             }
         
             // Are there any elements before rear_index that are located to the left side relative to the front_index
             if (rear_index < front_index) {
                 for (int i = 0; i <= rear_index; i++) {
                    cout << element_num << ": " << queue_array[i] << endl;
                    element_num++;
                }
             }
         }
     }

     void sort() {
         // Sorts the circular queue in ascending order 
         
         // Iterate through the 2nd element to the last element of the unsorted array
         // { 2 } -> { 8, 5, 3, 9, 4, 1 } <- iterate through these elements
         for (int i = 1; i < capacity; i++) {
             int current_pos = i; // The current index of the item we're trying to find its correct spot
             // On every iteration, this index is the first element of the unsorted array

             // Is the item_A's index greater than 0 AND the item_A's value is less than item_B, the element that's immediately to the left of item_A
             while (current_pos > 0 && queue_array[current_pos - 1] > queue_array[current_pos]) {
                 // Swapping items
                 Item_Type temp = queue_array[current_pos];
                 queue_array[current_pos] = queue_array[current_pos - 1];
                 queue_array[current_pos - 1] = temp;

                 current_pos -= 1; // We have to follow the item we're trying to swap, because on each swap the element's index changes
                 // In case we have to make more than 1 swap/exchanges to the left
             }

         }
         
         // Need to reset front_index and rear_index 
            // I don't want this [ 0(rear_index), 1, 2, 3(front_index), 4 ]
            // I want this: [ 0(front_index), 1, 2, 3, 4(rear_index) ]
         front_index = 0;
         rear_index = capacity - 1;
     }
};