/*
    Ahmet Alperen Yılmazyıldız 
    22002712
*/
#ifndef __PUZZLEROW_H
#define __PUZZLEROW_H

class PuzzleRow{
    private:
        struct PuzzlePiece{
            char shape;
            int rowindex;
            int colindex;
            PuzzlePiece* next;
        };
        PuzzlePiece* head;
        PuzzleRow* next;
        int rowindex;
        int size;
        int maxRowIndex;
        int maxSize; //equals to puzzleContainer width
        
    public:
        PuzzleRow();
        PuzzleRow( int size, int rowindex);
        ~PuzzleRow();

        int getRowIndex();
        void setNext( PuzzleRow* next );
        PuzzleRow* getNext();
        PuzzlePiece* find( int index );
        bool insert( int index, char shape );
        bool remove( int index );
        bool isEmpty();
        char getPiece( int index );
        int getSize();
        void printRow();
        void setMaxRowIndex( int s );

};
#endif