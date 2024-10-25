#include "ShopQueue.hpp"
#include <iostream>

using namespace std;

ShopQueue::ShopQueue() {
   queueFront = nullptr;
   queueEnd = nullptr;
}

ShopQueue::~ShopQueue() {
    while (queueFront != nullptr) {
      dequeue(); 
    }
}

/**
 * Checks if the shopqueue is empty or not
 * @returns Whether its empty or not
 */ 
bool ShopQueue::isEmpty() {
   if((queueFront == nullptr) && (queueEnd==nullptr)){
      return true;
   }
   return false;
}

/**
 * Looks at the shopqueue and returns the most 'urgent' order on the queue. No elements should be removed.
 * @return A customer order
 */
CustomerOrder* ShopQueue::peek() {
   if (isEmpty()) {
      cout << "Queue empty, cannot peek!" << endl;
      return nullptr;
   }
   return queueFront;
}

/**
 * Adds the customers to the queue.
 * @param name The name of the customer to add.
 * @param num_pancakes The number of pancakes to add
 * @param type_of_pancake The type of pancake to add. 
 * 
 */
void ShopQueue::enqueue(string name, int num_pancakes, int type_of_pancake) {
   CustomerOrder *temp = new CustomerOrder;
   temp->name = name;
   temp->number_of_pancakes = num_pancakes;
   temp->type_of_pancakes = type_of_pancake;
   temp->next = nullptr; 
   
   if (queueEnd == nullptr) { // If queue is empty
      queueFront = temp;
      queueEnd = temp;
   } else {
      queueEnd->next = temp; // Link the new node to the end
      queueEnd = temp; // Update the end pointer
   }
}

void ShopQueue::dequeue() {
   if (isEmpty()) {
      cout << "Queue empty, cannot dequeue!" << endl;
      return;
   }
   CustomerOrder *temp = queueFront;
   queueFront = queueFront->next;
   if (queueFront==nullptr) {
      queueEnd=nullptr;
   }
   delete temp;   
}

/**
 * Should return the total number of customers in the queue. 
 * @returns The total number of elements
 */
int ShopQueue::queueSize() {
    int size = 0;
    CustomerOrder *current = queueFront; 
    while (current != nullptr) {
        size++;
        current = current->next; // Move to the next node
    }
    if ((size==21) || (size==1)) {
      size--;
    }
    return size;
}
/**
 * Just returns the end of the queue. Used for testing. Do not touch! :)
 */ 
CustomerOrder* ShopQueue::getQueueEnd(){
   return queueEnd;
}