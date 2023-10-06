/* 
 * Queue.cpp - Does not work well!
 *
 * Description: Array-based implementation of Queue as an ADT class
 * Class Invariant: Queue maintained in FIFO order
 *
 * Author: Brendan Shen
 * Date:
 * 
 * Resizing the array is a relatively expensive operation. You need to find a larger space, 
 * copy the elements from the old array into the new array, and recycle the old array. 
 * Overall, this is an O(n) operation, and should occur sparingly.
 *  
 * One effective strategy is to double the capacity of the Queue whenever you enqueue into a full array. 
 * The expensive resizing operations are amortized across enough operations that they don’t become an issue. 
 * Implement this strategy by re-writing enqueue(newElement). Feel free to add a private helper method to the Queue class, if you need one.
 * 
 * To have an array that has too large a capacity compared to the number of elements is also bad. 
 * It is a waste of space. One good strategy is to halve the capacity of the Queue whenever the array is less than 1/4 full. 
 * However, the minimum capacity cannot drop below the value of INITIAL_CAPACITY. Implement this strategy by re-writing dequeue().
 * 
 * You may also notice that there are a few other problems with the provided implementation of the methods of this Queue. 
 * For example, elementCount may be incorrectly set. As you are making the above changes, ensure that you fix this problem. 
 * There are other problems that we shall not yet be able to fix as they will require the use of exception handling. 
 * For example, we will not be able to notify the client code when the preconditions of dequeue() and of peek() have not been satisfied. 
 * To do so, we will need to make use of exception handling which we will cover soon in one of our labs. 
 * Therefore, we shall have to wait for our next assignments in order to fix such problems.
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
    elements[backindex] = newElement;
    backindex = (backindex + 1) % capacity;    
    elementCount++;
    return;
} 

// Description: Removes the frontmost element
// Precondition: Queue not empty
// Time Efficiency: O(1)
void Queue::dequeue() {
    elementCount--;
    frontindex = (frontindex + 1) % capacity;
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
