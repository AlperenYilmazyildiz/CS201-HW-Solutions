/*
    Ahmet Alperen Yılmazyıldız
    22002712
*/
#ifndef __INTSTACK_H
#define __INTSTACK_H

class IntStack{
    private:
        struct StackNode {            // a node on the stack
            int item;                // a data item on the stack
            StackNode *next;        // pointer to next node
        };
        StackNode *topPtr;     

    public: 
        IntStack();
        IntStack(const IntStack& aStack);
        ~IntStack();

        bool isEmpty() const;
        bool push(int newItem);
        bool pop();
        bool pop(int& stackTop);
        bool getTop(int& stackTop) const;

};
#endif