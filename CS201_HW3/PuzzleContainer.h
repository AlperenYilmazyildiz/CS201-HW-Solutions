/*
    Ahmet Alperen Yılmazyıldız 
    22002712
*/
#ifndef __PUZZLECONTAINER_H
#define __PUZZLECONTAINER_H
#include "PuzzleRow.h"

void shapeConverter( unsigned char shape, int& down, int& up, int& right, int& left);

class PuzzleContainer{
    private:
        PuzzleRow* rowLists;
        int height;
        int width;
        int contsize;

        struct PuzzleRowNode{
            PuzzleRow pR;
            PuzzleRowNode *next;
        };
        PuzzleRowNode* head;
        
    public:
        PuzzleContainer( int h, int w);
        ~PuzzleContainer();
        
        PuzzleRow* getRow( int index );
        bool insertRow( int index );
        bool removeRow( int index );
        bool addPiece( int row, int col , char shape );
        bool removePiece(int row, int col);
        int getHeight();
        int getWidth();
        void showPiece(int row, int col);
        void displayContainer();
        void showColumn(int col);
        void showRow(int row);
        void findPiece(char shape);
        PuzzleRowNode* findNode( int index );
};
#endif

//g++ PuzzleRow.cpp main.cpp -o pr
//g++ PuzzleRow.cpp PuzzleContainer.cpp main.cpp -o pr
//dijkstra.ug.bcc.bilkent.edu.tr
//valgrind --tool=memcheck --leak-check=yes ./