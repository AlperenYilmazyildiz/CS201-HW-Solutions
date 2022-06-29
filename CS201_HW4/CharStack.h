/*
    Ahmet Alperen Yılmazyıldız
    22002712
*/
#ifndef __CHARSTACK_H
#define __CHARSTACK_H

class CharStack{
    private:
        struct StackNode {            // a node on the stack
            char item;                // a data item on the stack
            StackNode *next;        // pointer to next node
        };
        StackNode *topPtr;     

    public: 
        CharStack();
        CharStack(const CharStack& aStack);
        ~CharStack();

        bool isEmpty() const;
        bool push(char newItem);
        bool pop();
        bool pop(char& stackTop);
        bool getTop(char& stackTop) const;

};
#endif

