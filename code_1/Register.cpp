#include <iostream>
#include <cstdlib>
#include <iostream>
#include "Register.hpp"


using namespace std;

Register::Register(){
   for (int i=0; i<SIZE; i++) {
      a[i]=0;
   }
   top=-1;
}

/*
 * If the register is full or not
 * @returns 
 */
bool Register::isFull(){
   if (top==SIZE-1) {
      return true;
   }
   return false;
}

/*
 * Adds money to stack.
 * @param money: the type of pancake's price times the quantity
 */
void Register::push( int money ){
   if (isFull()) {
      cout << "Stack overflow: " << endl;
      return;
   }
   top++;
   a[top]=money;
   return;
}


/*
 * Checks if stack is full. 
 * @returns a bool
 */
bool Register::isEmpty(){
   if (top==-1) {
      return true;
   }
   return false;
}

/*
 * Looping through the stack array to display amounts
 */
void Register::disp(){
   cout << "top = " << a[top] << endl;
   for (int i=top+1; i>=0; i--) {
      cout << a[i] << endl;
   }
}

int Register::pop(){
   if (isEmpty()) {
      cout << "Stack empty, cannot pop an item!" << endl;
      return -1;
   }
   int temp=a[top];
   top--;
   return temp;
}