/* 
 * Stack.cpp
 *
 * Description: Implementation of a linked list-based Stack ADT class - SHSL list
 * Class Invariant: LIFO order
 *                  Top of Stack located at the back of SHSL list.
 *
 * Author: Brendan Shen & Erin DeMarco
 * Date: October 8th 2023
 */
 
class Stack {

    private:
        
        // Description:  Nodes for a singly-linked list - Do not modify!
        class StackNode {
            public:
                int data;
                StackNode * next;
        };
        StackNode* head;//only added one private member, the head pointer

    public:
        Stack();//default constructor
        ~Stack();//destructor

        //public methods:
        bool push(int num);//pushes integer into the stack
        int peek();//returns integer at the top of the stack (in this case, the end of the linked list)
        bool pop();//removes integer at the top of the stack (in this case, the end of the linked list) and returns true if successful
        bool isEmpty();//returns true if the stack is empty, returns false if stack has elements in it
};
