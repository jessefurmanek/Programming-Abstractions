//
//  RPNCalc.cpp
//  Ch.9_Coursework
//
//  Created by Jesse Furmanek on 1/1/14.
//
//
#include <iostream>
#include <iomanip>
#include <fstream>
#include "console.h"
#include "simpio.h"
#include "grid.h"
#include "strlib.h"
#include "vector.h"
#include "random.h"
#include "stack.h"
#include "tokenscanner.h"
#include "rpncalc.h"
#include "rational.h"
#include "rationalstack.h"


using namespace std;

/* Main program */
/*
 * File: rpncalc.cpp
 * -----------------
 * This program simulates an electronic calculator that uses
 * reverse Polish notation, in which the operators come after
 * the operands to which they apply.
 */

/* Private function prototypes */

void ApplyOperator(char op, RatStackVec &operandStack);
void HelpCommand();
void ClearStack(RatStackVec &operandStack);
/* Main program */

void rpnCalc() {
    RatStackVec operandStack;
    
    cout << "RPN Calculator Simulation (type H for help)" << endl;
    
    while (true) {
        cout << "> ";
        
        string line = getLine();
        TokenScanner scanner;
        scanner.ignoreWhitespace();
        scanner.scanNumbers();
        scanner.setInput(line);
        
        char ch1 = toupper(line[0]);
        
        if(ch1 == 'Q') {
            break;
        }else if (ch1 == 'C'){
            ClearStack(operandStack);
        } else if (ch1 == 'H') {
            HelpCommand();
        }else{
            while(scanner.hasMoreTokens()){
                string charString = scanner.nextToken();
                char ch = toupper(charString[0]);
                
                if (isdigit(ch)) {
                    Rational ratInput(stringToReal(charString),1);  //covert input into rational number
                    operandStack.pushVec(ratInput);  //add number to stack
                } else {
                    ApplyOperator(ch, operandStack);
                }
                
            }
            
        }
        
    }
}

/*
 * Function: ApplyOperator
 * Usage: ApplyOperator(op, operandStack);
 * ---------------------------------------
 * This function applies the operator to the top two elements on
 * the operand stack.  Because the elements on the stack are
 * popped in reverse order, the right operand is popped before
 * the left operand.
 */
void ApplyOperator(char op, RatStackVec &operandStack) {

    Rational ratRHS(operandStack.peekVec().getN(), operandStack.peekVec().getD());  //transform the strings into rational numbers
    operandStack.popVec();
    
    Rational ratLHS(operandStack.peekVec().getN(), operandStack.peekVec().getD());
    
    operandStack.popVec();

    int num=0;
    int den=0;
    
    switch (op) {
        case '+': num = ratLHS.add(ratRHS).getN(); den = ratLHS.add(ratRHS).getD(); break;
        case '-': num = ratLHS.sub(ratRHS).getN(); den = ratLHS.sub(ratRHS).getD(); break;
        case '*': num = ratLHS.mul(ratRHS).getN(); den = ratLHS.mul(ratRHS).getD(); break;
        case '/': num = ratLHS.div(ratRHS).getN(); den = ratLHS.div(ratRHS).getD(); break;
        default:  error("Illegal operator");
    }
   
    
    Rational result(num,den); //recreate the rational number to push onto the stack
    operandStack.pushVec(result);
  
    cout << result.getN() <<" / "<<result.getD()<<endl;  //print derived rational number
  
    
    return;
}


/*
 * Function: HelpCommand
 * Usage: HelpCommand();
 * ---------------------
 * This function generates a help message for the user.
 */
void HelpCommand() {
    cout << "Enter expressions in Reverse Polish Notation," << endl;
    cout << "in which operators follow the operands to which" << endl;
    cout << "they apply.  Each line consists of a number, an" << endl;
    cout << "operator, or one of the following commands:" << endl;
    cout << "  Q -- Quit the program" << endl;
    cout << "  H -- Display this help message" << endl;
    cout << "  C -- Clear the calculator stack" << endl;
}


/*
 * Function: ClearStack
 * Usage: ClearStack(stack);
 * -------------------------
 * This function clears the stack by popping elements until empty.
 */
void ClearStack(RatStackVec &stack) {
    while (!stack.isEmptyVec()) {
        stack.popVec();
    }
}

