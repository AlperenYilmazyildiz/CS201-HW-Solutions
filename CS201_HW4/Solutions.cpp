/*
    Ahmet Alperen Yılmazyıldız
    22002712
*/
#include "Solutions.h"
#include "IntStack.h"
#include "CharStack.h"
#include "DoubleStack.h"
#include <iostream>
#include <cmath>
using namespace std;

void fantabulous( string list, int length ){
    int largest, secondLargest;
    int listInd = 0;
    int intList[length];
    int i = 0;
   
    while ( listInd < length )
    {
        int j = i;
        int numberLen = 0;
        int listNumber = 0;
        while ( list[i] != ',' && list[i] != '\0')
        {
            numberLen++;
            i++;
        }
        while( numberLen > 0 ){
            listNumber += ((int)list[j] - 48) * pow(10.0, numberLen - 1);
            numberLen--;
            j++;
        }
        intList[listInd] = listNumber;
        listInd++;
        i++;
    }

    IntStack intStack;
    IntStack intStack2;
    int cnt = 0;
    int subArraySize = 2;
    int subInd = -1, subIndEnd;
    while( subArraySize <= length ){
        int top;
        int grInd, secgrInd;
        subInd++;   
        subIndEnd = length - 1;
        
        for( subIndEnd; subInd < subIndEnd; subIndEnd-- ){
            intStack.push(-1);
            intStack2.push(-1);
            
            for( int ind = subInd; ind <= subIndEnd; ind++ ){
                intStack.getTop(top);
                if( intList[ind] >= top ){
                    intStack.pop();
                    intStack.push(intList[ind]);
                    grInd = ind;
                }
            }
            
            for( int ind = subInd; ind < grInd; ind++ ){
                intStack2.getTop(top);
                if( intList[ind] >= top ){
                    intStack2.pop();
                    intStack2.push(intList[ind]);
                    secgrInd = ind;
                }
            }
        
            for ( int ind = subIndEnd; ind > grInd; ind-- ){
                intStack2.getTop(top);
                if( intList[ind] >= top ){
                    intStack2.pop();
                    intStack2.push(intList[ind]);
                    secgrInd = ind;
                }
            }
            if( secgrInd < grInd )
                cnt++;
            intStack.pop();
            intStack2.pop();
        }
        subArraySize++;
    }
    
    cout<< "Number of fantabulous subsequences: " << cnt << endl;
}

void subset( string intervals, int length ){
    int listInd = 0;
    int intList[length];
    int i = 0;
    while ( listInd < length )
    {
        int j = i;
        int numberLen = 0;
        int listNumber = 0;
        while ( intervals[i] != ',' && intervals[i] != '\0')
        {
            numberLen++;
            i++;
        }
        while( numberLen > 0 ){
            listNumber += ((int)intervals[j] - 48) * pow(10.0, numberLen - 1);
            numberLen--;
            j++;
        }
        intList[listInd] = listNumber;
        listInd++;
        i++;
    }

    IntStack intStack;
    intStack.push( intList[0]);
    intStack.push( intList[1]);
    int top;
    int stackCount = 2;
    for( int ind = 2; ind < length; ind += 2 ){
        intStack.getTop(top);
        if( intList[ind] < top && intList[ind+1] > top ){
            intStack.pop();
            intStack.push(intList[ind+1]);
        }
        else if( intList[ind] < top && intList[ind+1] < top ){

        }
        else{
            intStack.push(intList[ind]);
            intStack.push(intList[ind+1]);
            stackCount += 2;
        }
    }   

    int arrayLen = stackCount;
    int printList[arrayLen];
    while (!intStack.isEmpty()){
        int t; 
        intStack.getTop(t);
        printList[stackCount-1] = t;
        intStack.pop();
        stackCount--;
    }

    cout<< "Joined subset: ";
    for (int k = 0; k < arrayLen; k++){
        if( k % 2 == 0  && k != arrayLen - 1)
            cout<< "(";
        cout<< printList[k];
        if( k % 2 == 0 )
            cout<< ":"; 
        if( k % 2 == 1 )
            cout<< "), ";  
        else if( k == arrayLen - 1 )
            cout<< ")";
    }
    cout<< endl;
}

string infix2prefix( string expression ){
    int length = 0;
    string prefixed = "";
    string reversedExp;
    // determine length of the infix expression
    while( expression[length] != '\0' ){
        length++;
    }

    // reverse the expression
    for (int i = 0; i < length; i++){
        reversedExp[i] = expression[length-1-i];
    }
    
    CharStack chStack;
    char top;
    for(int i = 0; i < length; i++){
        char ch = reversedExp[i];
        // if ch is equal to an operator
        if( ch == '+' || ch == '-' || ch == '*' || ch == '/'){
            //if stack is empty push ch into ch
            if( chStack.isEmpty() ){
                chStack.push( ch );
            }
            //if stack is not empty get the top element of the stack 
            //and compare ch with top element. If top element has higher precedence than ch
            //pop top element and add it to the prefixed string value 
            //until stack's top element has lower or equal precedence with ch.
            //If top element has lower precedence than ch, push ch into stack.
            else if( chStack.getTop(top) ){
                if( (ch == '+' || ch == '-') && (top == '*' || top == '/') ){
                    while( (top == '*' || top == '/') ){
                        prefixed += top;
                        chStack.pop();
                        chStack.getTop(top);
                    }
                    prefixed += top;
                    chStack.pop();
                    chStack.push(ch);
                }
                else{
                    chStack.push(ch);
                }
            }
        } 
        //If ch is equal to '(', add top element of stack to the prefixed string 
        //and then pop it until ')' is found in the stack.
        else if( ch == '(' ){
            //discard ch
            chStack.getTop(top);
            while( top != ')' ){
                prefixed += top;
                chStack.pop();
                chStack.getTop(top);
            }
            chStack.pop();
        }
        //If ch equal to ')', push it into stack
        else if( ch == ')' ){
            chStack.push(ch);
        }
        //If ch is equal to an operand, add ch into prefixed string value which will be returned.
        else{
            //append ch to the end of postfixExp 
            prefixed += ch;
        }
        
    }
    //After reversed expression is evaluated, insert leftover stack elements 
    //into end of prefixed one by one, except ')'.
    while( !chStack.isEmpty() ){
        chStack.getTop(top);
        if( top != ')')
            prefixed += top;
        chStack.pop();
    }
    //determine length of prefixed
    int prefixLen = 0;
    while (prefixed[prefixLen] != '\0'){
        prefixLen++;
    }
    //reverse prefixed string
    for (int i = 0; i < prefixLen/2; i++){
        char temp = prefixed[i];
        prefixed[i] = prefixed[prefixLen - 1 - i];
        prefixed[prefixLen - 1 - i] = temp;  
    }

    cout<< "Prefix form of " << expression << " is ";
    return prefixed;
}


void evaluatePrefix( string expression ){
    int length = 0;

    while( expression[length] != '\0' ){
        length++;
    }    

    DoubleStack doubStack;
    char top;
    double dTop;
    double num1, num2, res = 0;
    for(int i = 0; i < length; i++){ 
        char ch = expression[length-1-i];
        if( ch == '+' || ch == '-' || ch == '*' || ch == '/'){
            switch (ch){
            case '+':
                doubStack.getTop(dTop);
                num1 = dTop;
                doubStack.pop();
                
                doubStack.getTop(dTop);
                num2 = dTop;
                doubStack.pop();
                
                res = num1 + num2;
                doubStack.push(res);
                break;
            case '-':
                doubStack.getTop(dTop);
                num1 = dTop;
                doubStack.pop();
                
                doubStack.getTop(dTop);
                num2 = dTop;
                doubStack.pop();
                
                res = num1 - num2;
                doubStack.push(res);
                break;
            case '*':
                
                doubStack.getTop(dTop);
                num1 = dTop;
                doubStack.pop();
                
                doubStack.getTop(dTop);
                num2 = dTop;
                doubStack.pop();
                
                res = num1 * num2;
                doubStack.push(res);
                break;
            case '/':
                doubStack.getTop(dTop);
                num1 = dTop;
                doubStack.pop();
                
                doubStack.getTop(dTop);
                num2 = dTop;
                doubStack.pop();
                
                res = num1 / num2;
                doubStack.push(res);
                break;
            default:
                break;
            }    
        }
        else{
            double num;
            num = ((int)ch - 48) * 1.0;
            doubStack.push(num); 
        }
    }     
    double result;
    doubStack.getTop(result);
    cout<< "Result of " << expression << " is: " << result << endl;
}