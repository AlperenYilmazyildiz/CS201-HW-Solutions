/*
    Ahmet Alperen Yılmazyıldız 
    22002712
*/
#include "PuzzleContainer.h"
#include <iostream>
#include <string>
using namespace std;

PuzzleContainer:: PuzzleContainer( int h, int w ){
    height = h;
    width = w;
    rowLists = NULL;
    head = NULL;
    contsize = 0;
}

PuzzleContainer:: ~PuzzleContainer(){

}

PuzzleRow* PuzzleContainer:: getRow( int index ){
    return rowLists;
}

PuzzleContainer:: PuzzleRowNode* PuzzleContainer:: findNode( int index ){
    if ( (index < 1) || (index > height) ){
        //cout<< "out of scope" << endl;
        return NULL;
    }
    else{
        PuzzleRowNode *cur = head;
        for( int skip = 1; skip < index; ++skip ){
            if( cur == NULL ){
                break;
            }
            cur = cur->next;
        }
        return cur;
    }
}

bool PuzzleContainer:: insertRow( int index ){
    int c = index;
    if( (index < 1) || (index > height) ){
        //cout<< "cant insert the row" << endl;
        return false;
    } 

    int newContSize = contsize + 1;

    PuzzleRowNode *newPtr = new PuzzleRowNode;
    newPtr->pR = PuzzleRow( width, index);
    newPtr->pR.setMaxRowIndex(getHeight());
    if( index == 1 ){
        newPtr->next = head;
        head = newPtr;
        //cout<< "first row inserted" << endl;
    }
    else{
        PuzzleRowNode *prev;
        do
        {
            index--;
            prev = findNode(index);
            if( findNode(index) != NULL && findNode(index)->pR.getRowIndex() == c ){
                //cout<< "no need for insertion for " << index << endl;
                return false;
            } 
            if( findNode(index) != NULL && findNode(index)->pR.getRowIndex() > c ){
                index--;
                prev = findNode(index);
            }
        } while (prev == NULL);
        newPtr->next = prev->next;
        prev->next = newPtr;
        //cout<< c << "th row inserted at " << index + 1 << endl;
    }
    contsize = newContSize;
    return true;

}

bool PuzzleContainer:: removeRow( int index ){
    cout<< "remove row doesnt work" << endl;
    return false;
}

bool PuzzleContainer:: addPiece( int row, int col , char shape ){
    int r = row;
    if( (row > height) || (row < 1) || (col > width) || (col < 1)) {
        cout<< row << "," << col << " is out of bounds, it cannot be added" << endl; 
        return false;
    }
    if( contsize == 0 || findNode(row) == NULL ){
        insertRow(row);
    }
    else if( findNode(row) != NULL && findNode(row)->pR.getRowIndex() != r ){
        insertRow(row);
    }
    //change row to the founded index
    while( findNode(row) == NULL ){
        row--;
    }
    if(findNode(row)->pR.insert(col, shape)){
        cout<< "A piece is added to " << r << "," << col << endl;
        return true;
    }
    else{
        cout<< "Shape doesnt fit into " << r << "," << col << " , it cannot be added" << endl;
        return false;
    }
}

bool PuzzleContainer:: removePiece(int row, int col){
    /*
    The puzzle container system will allow the user to
    remove a certain piece from the collection using its coordinates. If a piece with the
    specified coordinate does not exist, you should display a warning message. If it exists, you
    should remove it. You should also display a message indicating that the piece has been
    removed
    */
    cout<< "remove piece doesnt work" << endl;
    return false;
}

int PuzzleContainer:: getHeight(){
    return height;
}

int PuzzleContainer:: getWidth(){
    return width;
}

void PuzzleContainer:: showPiece(int row, int col){
    if( (row > height) || (row < 1) || (col > width) || (col < 1)) {
        cout<< row << "," << col << " is out of bounds, it cannot be shown" << endl; 
    }
    else{
        int R = row;
        int key;
        int diff;
        int r, l, u, d;
        string rT, lT, uT, dT;
        for( int i = 1; i <= row; i++ ){
            if( findNode(i) == NULL ){
                key = 0;
                break;
            }
            if( findNode(i)->pR.getRowIndex() == R ){
                key = 1;
                row = i;
                break;
            }
            else{
                key = 0;
                diff = R - findNode(i)->pR.getRowIndex();
            }
        }
        if( key == 1 ){
            shapeConverter( findNode(row)->pR.getPiece(col), d, u, r, l);
            if( d == 3 || u == 3 || r == 3 || l == 3 ){
                cout<< "There is no piece, it cannot be shown" << endl;
            }
            else{    
                if( d == 0 ){
                    dT = "Hole";
                }
                else if( d == 1 ){
                    dT = "Knob";
                }
                else{
                    dT = "Border";
                }
                //////////////
                if( u == 0 ){
                    uT = "Hole";
                }
                else if( u == 1 ){
                    uT = "Knob";
                }
                else{
                    uT = "Border";
                }
                //////////////
                if( r == 0 ){
                    rT = "Hole";
                }
                else if( r == 1 ){
                    rT = "Knob";
                }
                else{
                    rT = "Border";
                }
                //////////////
                if( l == 0 ){
                    lT = "Hole";
                }
                else if( l == 1 ){
                    lT = "Knob";
                }
                else{
                    lT = "Border";
                }
                cout<< "Piece on " << row << "," << col << " as following: " << endl;
                cout<< "Down: " << dT << endl;
                cout<< "Up: " << uT << endl;
                cout<< "Right: " << rT << endl;
                cout<< "Left: " << lT << endl;
            }   
        }
    }
}

void PuzzleContainer:: displayContainer(){
    cout<< "Container: " << getHeight() << "x" << getWidth() << endl;
    if( contsize == 0 ){
        for( int i = 0; i <= height; i++ ){
            for( int j = 0; j <= width; j++ ){
                if( i == 0 && j == 0 ){
                    cout<< "  ";
                }
                else if( i == 0 ){
                    cout<< j << " ";
                }
                else if( j == 0 ){
                    cout<< i << " ";
                }
                else{
                    cout<< "O ";
                }
            }
            cout<< endl;
        }
    }
    else{
        for( int i = 0; i <= height; i++ ){
            if( i == 0 ){
                for( int j = 0; j <= width; j++ ){
                    if( j == 0 ){
                        cout<< "  ";
                    }
                    else{
                        cout<< j << " ";
                    }
                }
                cout<<endl;
            }   
            else{
                cout<< i << " ";
                showRow(i);
            }
        }
    }
}

void PuzzleContainer:: showColumn(int col){
    if( col > width || col <= 0 ){
        cout<< "column " << col << " is out of border" << endl;
    }
    else{
        cout<< "Column: " << col << endl;
        int ind = 1;
        int key;
        int diff;
        do
        {
            int r = findNode(ind)->pR.getRowIndex();
            diff = r - ind;
            int wR;
            for( int i = 1; i <= r; i++ ){
                if( findNode(i) == NULL ){
                    key = 0;
                    break;
                }
                if( findNode(i)->pR.getRowIndex() == r ){
                    key = 1;
                    wR = i;
                    break;
                }
                else{
                    key = 0;
                    diff = r - findNode(i)->pR.getRowIndex();
                }
            } 
            for( int j = 1; j < diff; j++ ){
                cout<< "O " << endl;
            }
            if( key == 1 ){
                if(findNode(wR)->pR.getPiece(col) != char(255)){
                    cout<< "X "<<endl;   
                }
                else{
                    cout<< "O " << endl;
                }
            }   
            else{
                cout<< "O " << endl;
            }
            ind++;
            if( findNode(ind) == NULL ){
                break;
            }
        } while (ind != height + 1);
    }
    
}

void PuzzleContainer:: showRow(int row){
    if( row <= 0 || row > height){
        cout<< "row " << row << " is out of border" << endl;
    }
    else{
        int r = row;
        int key;
        int diff;
        for( int i = 1; i <= row; i++ ){
            if( findNode(i) == NULL ){
                key = 0;
                break;
            }
            if( findNode(i)->pR.getRowIndex() == r ){
                key = 1;
                row = i;
                break;
            }
            else{
                key = 0;
                diff = r - findNode(i)->pR.getRowIndex();
            }
        }
        
        if( key == 1 ){
            findNode(row)->pR.printRow();
            cout<< endl;   
        }
        else{
            for( int j = 1; j <= width; j++ ){
                cout<< "O ";
            }
            cout<<endl;
        }
    }
}

void PuzzleContainer:: findPiece(char shape){
    int r, l, u, d;
    string rT, lT, uT, dT;
    shapeConverter( shape, d, u, r, l);
    if( d == 0 ){
        dT = "Hole";
    }
    else if( d == 1 ){
        dT = "Knob";
    }
    else{
        dT = "Border";
    }
    //////////////
    if( u == 0 ){
        uT = "Hole";
    }
    else if( u == 1 ){
        uT = "Knob";
    }
    else{
        uT = "Border";
    }
    //////////////
    if( r == 0 ){
        rT = "Hole";
    }
    else if( r == 1 ){
        rT = "Knob";
    }
    else{
        rT = "Border";
    }
    //////////////
    if( l == 0 ){
        lT = "Hole";
    }
    else if( l == 1 ){
        lT = "Knob";
    }
    else{
        lT = "Border";
    }
    
    int rowcount = 0, colcount = 0;
    for( int i = 1; i <= height; i++ ){
        if( findNode(i) != NULL ){
            for( int j = 1; j <= width; j++ ){
                if( findNode(i)->pR.getPiece(j) == shape ){
                    colcount++;
                    rowcount++;
                }
            }
        }       
    }
    if( rowcount == 0 ){
        cout<< "There is no piece that has shape" << endl;
        cout<< "Down: " << dT << endl;
        cout<< "Up: " << uT << endl;
        cout<< "Right: " << rT << endl;
        cout<< "Left: " << lT << endl;    
    }
    else{
        int locRow[rowcount];
        int locCol[colcount];
        int ind = 1;
        int key;
        int diff;
        int placement = 0;
        int rowPlacement = 0;
        do
        {
            int r = findNode(ind)->pR.getRowIndex();
            int wR;
            for( int i = 1; i <= r; i++ ){
                if( findNode(i) == NULL ){
                    key = 0;
                    break;
                }
                if( findNode(i)->pR.getRowIndex() == r ){
                    key = 1;
                    wR = i;
                    break;
                }
                else{
                    key = 0;
                }
            } 
            if( key == 1 ){
                for( int j = 1; j <= width; j++ ){
                    if( findNode(wR)->pR.getPiece(j) == shape ){
                        locCol[placement++] = j;   
                        locRow[rowPlacement++] = r; 
                    }
                } 
            }
            ind++;
            if( findNode(ind) == NULL ){
                break;
            }
        } while (ind != height + 1);

        for(int i = 0; i < rowcount; i++ ){
            cout<< " (" << locRow[i] << "," << locCol[i] << ")";
        }
        cout<< " contain the piece that has shape " << endl;
        cout<< "Down: " << dT << endl;
        cout<< "Up: " << uT << endl;
        cout<< "Right: " << rT << endl;
        cout<< "Left: " << lT << endl;  
    }
    

}
