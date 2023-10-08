/* 
 * Queue.cpp - Does not work well!
 *
 * Description: Array-based implementation of Queue as an ADT class
 * Class Invariant: Queue maintained in FIFO order
 *
 * Author: Brendan Shen & Erin DeMarco
 * Date: October 8th 2023
 */
 

#include <iostream>
#include "Queue.h"

using std::cout;
using std::endl;

// Description: Constructor
Queue::Queue() {
    int* elementsPointer = new int[INITIAL_CAPACITY];
    elements = elementsPointer;
}

Queue::~Queue() {
    delete[] elements;
    elements = nullptr;
}

// Description: Inserts newElement at the back of Queue
// Time Efficiency: O(1)
void Queue::enqueue(int newElement) {
    //check if the queue is full
    if(elementCount == capacity){
        //double the capacity
        int newCapacity = capacity*2;
        int* newElements = new int[newCapacity];
        //copy the elements to the new array
        for(int i = 0; i<elementCount; ++i){
            newElements[i] = elements[(frontindex + i) % capacity];//most important
        }
        frontindex = 0;
        backindex = elementCount;
        capacity = newCapacity;

        //delete heap memory where the old elements array is
        delete[] elements;
        elements = newElements;
    }
    //the existing code
    elements[backindex] = newElement;
    backindex = (backindex + 1) % capacity;    
    elementCount++;
    return;
} 

// Description: Removes the frontmost element
// Precondition: Queue not empty
// Time Efficiency: O(1)
void Queue::dequeue() {
    if(isEmpty() == false){
        elementCount--;
        frontindex = (frontindex + 1) % capacity;

        //check if the capacity should be halved
        if((elementCount < (capacity/4))  && (capacity > INITIAL_CAPACITY)){
            int newCapacity = capacity/2;
            //take this next bit from enqueue
            int* newElements = new int[newCapacity];
            for(int i = 0; i<elementCount; ++i){
                newElements[i] = elements[(frontindex + i) % capacity];//most important
            }
            frontindex = 0;
            backindex = elementCount;
            capacity = newCapacity;

            //delete heap memory where the old elements array is
            delete[] elements;
            elements = newElements;
        }
    }
    return;
} 

// Description: Returns a copy of the frontmost element
// Precondition: Queue not empty
// Time Efficiency: O(1)
int Queue::peek() const {
    return elements[frontindex];    
} 

// Description: Returns true if and only if Queue empty
// Time Efficiency: O(1)
bool Queue::isEmpty() const {
    return elementCount == 0;
}
