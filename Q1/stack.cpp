/* 
 * Stack.cpp
 *
 * Description: Implementation of a linked list-based Stack ADT class - SHSL list
 * Class Invariant: LIFO order
 *                  Top of Stack located at the back of SHSL list.
 *
 * Author:
 * Date:
 */


#include <iostream>
#include <cctype>
#include "Stack.h"  // Header file

using std::cout;
using std::endl;

// Default constructor.
Stack::Stack() {
    head = nullptr;
}  // end default constructor

/* // Destructor
// Description: Destruct this object, releasing heap-allocated memory.
MyADT::~MyADT() {

} // end destructor */

Stack::~Stack() {
    bool headNotEmpty = true;
    while (headNotEmpty == true){
        headNotEmpty = pop();
    }
    delete head;
}

// Description: pushes num into the stack.
bool Stack::push(int num) {
    if(head == nullptr){
        StackNode* newHead = new StackNode();
        newHead->data = num;
        newHead->next = nullptr;
        head = newHead;
        if(head->data == num){
            return true;
        }
        else{
            return false;
        }
    }

    else{
        StackNode* current = head;
        while (current->next != nullptr){
            current = current->next;
        }
        StackNode* newElem = new StackNode();
        newElem->data = num;
        newElem->next = nullptr;
        current->next = newElem;
        if(current->data == num){
            return true;
        }
        else{
            return false;
        }
    }
}  // end push

// Description: peeks the last value in the stack and returns that value.
int Stack::peek() {
    if(head == nullptr){
        return 0;
    }
    
    else{
        StackNode* current = head;
        while (current->next != nullptr){
            current = current->next;
        }
        return current->data;
    }
}  // end peek

// Description: pops the last element and returns true if successful
bool Stack::pop() {
    if(head == nullptr){
        return false;
    }
    else if(head->next == nullptr){
        delete head;
        head = nullptr;
        return true;
    }
    else {
        StackNode* current = head;
        while (current->next->next != nullptr) {
            current = current->next;
        }
        StackNode* last = current->next;
        current->next = nullptr;
        delete last;
        return true;
    }
}  // end pop

// Description: checks if the stack is empty, if it is then it returns true
bool Stack::isEmpty() {
    if(head == nullptr){
        return true;
    }
    else{
        return false;
    }
}  // end isEmpty

//  End of implementation file
