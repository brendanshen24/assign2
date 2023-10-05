/* 
 * Eval.cpp
 *
 * Description: Evaluation of infix expressions using two Stacks.
 *
 * Author:
 * Date:
 */

#include <iostream>
#include "Scanner.h"
#include "Stack.h"  // GENERIC STACK

using namespace std;



int main () {
    Scanner S(cin);
    Token t;

    Stack<Token> numstack, opstack;  // 2x Stacks of type Token
    

    t = S.getnext();
    while ((t.tt != eof) || (opstack.isEmpty() == false)) {//while T is not EOF or the operator stack is non empty
        if (t.tt == integer) {//if T is a number:
            numstack.push(t);//push T to the number stack; get the next token
        } 
        else if (t.tt == lptok) {//else if T is a left parenthesis:
            opstack.push(t);//push T to the operator stack; get the next token
        } 
        else if (t.tt == rptok) {//else if T is a right parenthesis:
            if(opstack.peek().tt == lptok){//if the top of the operator stack is a left parenthesis:
                opstack.pop();//pop it from the operator stack; get the next token:
            }
            else{//else:
                int a = numstack.pop().val;//pop the top two numbers and the top operator
                int b = numstack.pop().val;
                Token operation = opstack.pop();
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
        } 
        else if (t.tt == pltok || t.tt == mitok || t.tt == eof) {// else if T is +, - or EOF:
            if((opstack.isEmpty() == false) && (opstack.peek().tt == pltok || opstack.peek().tt == mitok || opstack.peek().tt == asttok || opstack.peek().tt == slashtok)){//if the operator stack is nonempty and the top is one of +, -, *, /:
                int a = numstack.pop().val;//pop the top two numbers and the top operator
                int b = numstack.pop().val;
                Token operation = opstack.pop();
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
            else{//else:
                opstack.push(t);//push T to the operator stack; get the next token

            }
        }
        else if (t.tt == asttok || t.tt == slashtok) {//else if T is * or /:
            if((opstack.isEmpty() == false) && (opstack.peek().tt == asttok || opstack.peek().tt == slashtok)){//if the operator stack is nonempty and the top is one of *, /:
                int a = numstack.pop().val;//pop the top two numbers and the top operator
                int b = numstack.pop().val;
                Token operation = opstack.pop();
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
            else{
                opstack.push(t);//push T to the operator stack; get the next token
            }
        }
        t = S.getnext();
    }

    //cout << endl;
    return 0;
}

