#include <iostream>
using namespace std;
#include "PuzzleContainer.h"

int main(){
    /*PuzzleRow p( 4, 5);
    p.setMaxRowIndex(5);
    cout<< p.getRowIndex() << endl;
    cout<< p.isEmpty() << endl;
    cout<< "insert 0x95 " << endl;
    p.insert(1, 0x96);
    p.printRow();
    cout<< "completed" << endl;
    cout<< "insertion 0x14" << endl;
    p.insert(2, 0x54);
    p.printRow();
    cout<< "completed" << endl;
    cout<< "insertion index 3" << endl;
    p.insert(3, 0x01);
    p.printRow();
    cout<< "insertion index 4" << endl;
    p.insert(4 ,0x66);
    p.printRow();
    cout<< "program ended" << endl;*/

    /*PuzzleContainer P(6,5);
    P.displayContainer();
    cout<< "add piece" << endl;
    cout<< (P.findNode(1) == NULL) << endl;
    P.addPiece(1,1,0x98);
    cout<< "second add piece" << endl;
    P.addPiece( 1,2, 0x18);
    cout<< "third add piece" << endl;
    //P.addPiece( 2, 4, 0x54);
    //P.addPiece( 3, 2, 0x14);
    //P.addPiece(4, 4, 0x64);
    cout<< "--------------"<< endl;
    //fix the problem that when there is empty index it gives segmentation fault
    
    
    P.displayContainer();
    cout<< endl;
    P.addPiece( 3, 2, 0x14);
    P.addPiece(3, 4, 0x14);
    P.displayContainer();
    P.addPiece(5,3, 0x14);
    P.addPiece(6,2, 0x42);
    P.displayContainer();
    P.addPiece(6,5, 0x66);
    P.displayContainer();
    cout<< "show piece" << endl;
    P.showPiece(6,2);
    P.showPiece(1,1);
    P.showPiece(8,3);
    P.showPiece(4,2);
    cout<< "show row"<< endl;
    P.showRow(1);
    P.showRow(3);
    P.showRow(5);
    P.showRow(2);
    P.showRow(7);
    cout<< "show column" << endl;
    P.showColumn(2);
    P.showColumn(3);
    P.showColumn(0);
    cout<< "find piece" << endl;
    P.findPiece(0x66);
    cout<< "program ended" << endl;*/

    PuzzleContainer P(8,4);
    P.displayContainer();
    // Testing add piece
    cout << endl;
    cout << "Testing Add Piece" << endl;
    cout << endl;
    P.addPiece( 1,2, 0x58);
    P.addPiece( 2,4, 0x20);
    P.addPiece( 5,2, 0x05);
    P.addPiece( 5,3, 0x54);
    P.addPiece( 6,3, 0x55);
    P.addPiece( 7,2, 0x00);
    P.addPiece( 7,4, 0x65);
    P.addPiece( 8,3, 0x42);
    cout << endl;
    P.displayContainer();
    cout << endl;
    P.addPiece( 0,0, 0x58);
    P.addPiece( 1,2, 0x58);
    P.addPiece( 2,2, 0x58);
    P.addPiece( 7,3, 0x55);
    P.addPiece( 4,4, 0x55);
    P.addPiece( 5,5, 0x55);
    cout << endl;
    P.displayContainer();
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "Testing Remove Piece" << endl;
    cout << endl;
    P.removePiece(5,9);
    P.removePiece(5,3);
    P.removePiece(4,4);
    P.removePiece(1,2);
    cout << endl;
    P.displayContainer();
    cout << endl;
    cout << "Testing Show Piece" << endl;
    cout << endl;
    P.showPiece(5,9);
    P.showPiece(4,4);
    P.showPiece(1,2);
    // Testing show column
    cout << endl;
    cout << "Testing Show Column" << endl;
    cout << endl;
    P.showColumn(0);
    P.showColumn(1);
    // Testing show row
    cout << endl;
    cout << "Testing Show Row" << endl;
    cout << endl;
    P.showRow(9);
    P.showRow(8);
    // Testing find piece
    cout << endl;
    cout << "Testing Find Piece" << endl;
    cout << endl;
    P.findPiece(0x21);
    cout << endl;
    P.addPiece( 3,2, 0x05);
    P.findPiece(0x05);
    cout<< "end of program" << endl;



    return 0;
}