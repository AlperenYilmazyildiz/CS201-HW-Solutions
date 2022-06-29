/*
    Ahmet Alperen Yılmazyıldız
    22002712
*/
#ifndef __DOUBLESTACK_H
#define __DOUBLESTACK_H

class DoubleStack{
    private:
        struct StackNode {            // a node on the stack
            double item;                // a data item on the stack
            StackNode *next;        // pointer to next node
        };
        StackNode *topPtr;     

    public: 
        DoubleStack();
        DoubleStack(const DoubleStack& aStack);
        ~DoubleStack();

        bool isEmpty() const;
        bool push(double newItem);
        bool pop();
        bool pop(double& stackTop);
        bool getTop(double& stackTop) const;

};
#endif