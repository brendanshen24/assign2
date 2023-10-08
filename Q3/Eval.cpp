/* 
 * Eval.cpp
 *
 * Description: Evaluation of infix expressions using two Stacks.
 *
 * Author: Brendan Shen & Erin DeMarco
 * Date: October 8th 2023
 */

#include <iostream>
#include "Scanner.h"
#include "Stack.h"  // GENERIC STACK

using namespace std;

void evaluateExpression(int a, int b, Token operation, Stack<Token>& numstack){
    Token newResult;
    newResult.tt == integer;
    if(operation.tt == pltok){
        newResult.val = a+b;//perform the operation
    }
    else if(operation.tt == mitok){
        newResult.val = a-b;//perform the operation
    }
    else if(operation.tt == asttok){
        newResult.val = a*b;//perform the operation
    }
    else if(operation.tt == slashtok){
        newResult.val = a/b;//perform the operation 
    }
    numstack.push(newResult);//push the result to the number stack
}

int main () {
    Scanner S(cin);
    Token t;

    Stack<Token> numstack, opstack;  // 2x Stacks of type Token
    

    t = S.getnext();
    while ((t.tt != eof) || (opstack.isEmpty() == false)) {//while T is not EOF or the operator stack is non empty
        if (t.tt == integer) {//if T is a number:
            numstack.push(t);//push T to the number stack;
            t = S.getnext();//get the next token
        } 
        else if (t.tt == lptok) {//else if T is a left parenthesis:
            opstack.push(t);//push T to the operator stack;
            t = S.getnext();//get the next token
        } 
        else if (t.tt == rptok) {//else if T is a right parenthesis:
            if(opstack.peek().tt == lptok){//if the top of the operator stack is a left parenthesis:
                opstack.pop();//pop it from the operator stack;
                t = S.getnext();//get the next token
            }
            else{//else:
                int b = numstack.pop().val;
                int a = numstack.pop().val;//pop the top two numbers and the top operator
                Token operation = opstack.pop();
                evaluateExpression(a, b, operation, numstack); //evaluate expression
            }
        } 
        else if (t.tt == pltok || t.tt == mitok || t.tt == eof) {// else if T is +, - or EOF:
            if((!opstack.isEmpty()) && (opstack.peek().tt == pltok || opstack.peek().tt == mitok || opstack.peek().tt == asttok || opstack.peek().tt == slashtok)){//if the operator stack is nonempty and the top is one of +, -, *, /:
                int b = numstack.pop().val;
                int a = numstack.pop().val;//pop the top two numbers and the top operator
                Token operation = opstack.pop();
                evaluateExpression(a, b, operation, numstack); //evaluate expression
            }
            else{//else:
                opstack.push(t);//push T to the operator stack;
                t = S.getnext();//get the next token
            }
        }
        else if (t.tt == asttok || t.tt == slashtok) {//else if T is * or /:
            if((opstack.isEmpty() == false) && (opstack.peek().tt == asttok || opstack.peek().tt == slashtok)){//if the operator stack is nonempty and the top is one of *, /:
                int b = numstack.pop().val;
                int a = numstack.pop().val;//pop the top two numbers and the top operator
                Token operation = opstack.pop();
                evaluateExpression(a, b, operation, numstack); //evaluate expression
            }
            else{
                opstack.push(t);//push T to the operator stack;
                t = S.getnext();//get the next token
            }
        }
    }

    int finalVal = 0;
    while (numstack.isEmpty() == false){
        finalVal += numstack.pop().val;
    }
    
    cout<<finalVal<<endl; //output the answer to the console

    return 0;
}