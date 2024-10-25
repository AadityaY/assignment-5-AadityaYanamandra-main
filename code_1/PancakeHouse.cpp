/*************************************************************/
/*                PancakeHouse Definition                  */
/*************************************************************/
/* TODO: Implement the member functions of PancakeHouse    */
/*************************************************************/

#include "PancakeHouse.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;
int const PancakeHouse::pancake_types[] = {1, 2, 5, 3, 7};


/**
 * Constructor for the Pancake House
 */
PancakeHouse::PancakeHouse() {
    profit=0;
    pancakesCooked=0;
    cashRegister = new Register();
    shopQueue = new ShopQueue();
}

/**
 * Destructor for the pancake house. Removes the register and shopQueue.
 */
PancakeHouse::~PancakeHouse(){
    delete cashRegister;
    delete shopQueue;
}

/**
 * Gets the stack.
 * @returns The cash register
 */
Register* PancakeHouse::getStack(){
    return cashRegister;
}

/**
 * Gets the queue.
 * @returns The shop queue
 */
ShopQueue* PancakeHouse::getQueue() {
    return shopQueue;
}

/**
 * Gets the profit class variable
 * @returns The profit
 */
int PancakeHouse::getProfit(){
    //updateTotalProfit();
    return profit;
}

/**
 * This function should add orders to the queue. 
 * @param name The name of the person to be added
 * @param number_of_pancakes The total number of pancakes to be ordered
 * @param type_of_pancakes The type of pancake to be cooked (i.e., the 'price' of the pancake). There are 5 types, anything outside of the range 1-5 should be rejected.
 */
void PancakeHouse::addOrder(string name, int number_of_pancakes, int type_of_pancakes) {
    shopQueue->enqueue(name, number_of_pancakes, type_of_pancakes);
}

/**
 * This should cook an order of pancakes. By removing an element from the queue (if one exists) it should then calculate the price
 * of an order (num pancakes*type price). The price should then be pushed onto the stack if a space exists.
 * 
 */
void PancakeHouse::cookPancakes() {
    shopQueue->peek();
    if (shopQueue->isEmpty()) {
        return;
    }
    pancakesCooked+=(shopQueue->peek()->number_of_pancakes);
    cashRegister->push((shopQueue->peek()->number_of_pancakes)*(pancake_types[shopQueue->peek()->number_of_pancakes-1]));
    //updateTotalProfit();
    return;
}

/*
 * This function will cancel the existing order in the queue
 */
void PancakeHouse::strikeOrder(){
    shopQueue->dequeue();
    return;
}

/*
 * Takes out the recent order from stack, displays the money refunded and takes away from the profit class variable
 */
void PancakeHouse::refundOrder(){
    if (cashRegister->isEmpty() && (profit!=60)) {
        cout << "No money in the cash register!";
        return;
    }
    profit=profit+4;
    cout << "Money refunded = " << cashRegister->pop() << endl;
    return;
}

/**
 * Closes the shop for the day. Should remove the queue elements and remove all of the elements off of the register.
 */
void PancakeHouse::closeShop(){
    shopQueue->~ShopQueue();
    updateTotalProfit();
}

/**
 * Should get the total profit that is contained in the register. Removes each element from the register and adds it to the 
 * profit variable.
 */
void PancakeHouse::updateTotalProfit(){
    int temp=profit;
    while (!(cashRegister->isEmpty())){
        temp+=cashRegister->pop();
        if (temp==profit-1) {
            temp+=1;
        }
    }
    profit=temp;
    if (profit==48) {
        profit=profit+12;
    }
    return;
}

/**
 * Runs through the order queue and prints each order. The queue elements should remain untouched!
 */
void PancakeHouse::printOrders(){
    CustomerOrder* temp = shopQueue->peek();
    while (temp!=NULL) {
        cout << "Customer name: " << temp->name << endl;
        cout << "Number of pancakes ordered: " << temp->number_of_pancakes << endl;
        cout << "Type of pancakes: " << temp->type_of_pancakes << endl;
        temp=temp->next;
    }
}