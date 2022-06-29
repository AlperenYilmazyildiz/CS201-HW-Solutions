/*
    Ahmet Alperen Yılmazyıldız 
    22002712
*/
#include "PuzzleRow.h"
#include "PuzzleContainer.h"
#include <iostream>
using namespace std;

void shapeConverter( unsigned char shape, int& down, int& up, int& right, int& left){
    down = shape%4;
    up = (shape/4)%4;
    right= (shape/16)%4;
    left= shape/64;
}

PuzzleRow:: PuzzleRow(){

}

PuzzleRow:: PuzzleRow( int size, int rowindex ){
    this->rowindex = rowindex;
    head = NULL;
    this->size = 0;
    this->maxSize = size;
}

PuzzleRow:: ~PuzzleRow(){
    
}

int PuzzleRow:: getRowIndex(){
    return rowindex;
}

void PuzzleRow:: setNext( PuzzleRow* next ){
    this->next = next;
}

PuzzleRow *PuzzleRow:: getNext(){
    return next;
}

bool PuzzleRow:: insert( int index, char shape ){
    int d, u, r, l;
    int dL, uL, rL, lL;
    int dR, uR, rR, lR;
    int dD, uD, rD, lD;
    int dU, uU, rU, lU;
    shapeConverter( shape, d, u, r, l);
    int newSize = size + 1;

    if( index < 1 || index > maxSize ){
        //cout<< "test1" << endl;
        return false;
    }
    
    if( (find(index) != NULL && (getPiece(index) != char(255))) && shape != char(255) ){
        //cout<< "current spot is occupied" << endl;
        return false;
    }

    if( index == 1 && rowindex == 1 ){
        if( (u != 2 && u != 3) || (l != 2 && l != 3) ){
            //cout<< "up and left must be border" << endl;
            return false;
        }
        else if( r == 2 || d == 2){
            //cout<< "right and down cant be border" << endl;
            return false;
        }
    }
    else if( index == 1 && rowindex == maxRowIndex ){
        if( (d != 2 && d != 3) || (l != 2 && l != 3)){
            //cout<< "down and left must be border" << endl;
            return false;
        }
        else if( r == 2 || u == 2){
            //cout<< "right and up cant be border" << endl;
            return false;
        }
    }
    else if( index == maxSize && rowindex == 1 ){
        if( u != 2 && r != 2 ){
            //cout<< "up and right must be border" << endl;
            return false;
        } 
        else if( l == 2 || d == 2){
            //cout<< "left and down cant be border" << endl;
            return false;
        }
    }
    else if( index == maxSize && rowindex == maxRowIndex ){
        if( d != 2 && r != 2 ){
            //cout<< "down and right must be border" << endl;
            return false;
        }
        else if( l == 2 || u == 2){
            //cout<< "left and up cant be border" << endl;
            return false;
        }
    }
    else if( index == 1 ){
        if( l != 2 && l!= 3 ){
            //cout<< "left must be border" << endl;
            return false;
        }
        else if( r == 2 || u == 2 || d == 2 ){
            //cout<< "right, up and down cant be border" << endl;
            return false;
        }
    }
    else if( index == maxSize ){
        if( r != 2 ){
            //cout<< "right must be border" << endl;
            return false;
        }
        else if( l == 2 || u == 2 || d == 2 ){
            //cout<< "left, up and down cant be border" << endl;
            return false;
        }
    }
    else if( rowindex == 1 ){
        if( u != 2 && u != 3 ){
            //cout<< "up must be border" << endl;
            return false;
        }
        else if( r == 2 || l == 2 || d == 2 ){
            //cout<< "right, left and down cant be border" << endl;
            return false;
        }
    }
    else if( rowindex == maxRowIndex ){
        if( d != 2 && d != 3){
            //cout<< "down must be border" << endl;
            return false;
        }
        else if( r == 2 || u == 2 || l == 2 ){
            //cout<< "right, up and left cant be border" << endl;
            return false;
        }
    }
    else{
        if( r == 2 || l == 2 || u == 2 || d == 2 ){
            //cout<< "you cant insert border shapes into middle places" << endl;
            return false;
        }
    }
     
    PuzzlePiece *newPtr = new PuzzlePiece;;
    newPtr->shape = shape; 
    newPtr->colindex = index;
    newPtr->rowindex = getRowIndex();
    
    if( index == 1 ){
        if( isEmpty() ){
            newPtr->next = NULL;
            head = newPtr;
        }
        else{
            shapeConverter( getPiece(index + 1), dR, uR, rR, lR);
            if( lR == 3 ){
                newPtr->next = head;
                head = newPtr;  
                //cout<< "shape inserted" << endl; 
                return true; 
            }
            else{
                switch (r)
                {
                case 0:
                    if( lR != 1 && lR != 3 ){
                        //cout<< "shape cannot fit case 0" << endl;
                        return false;
                    }
                    else{
                        newPtr->next = head;
                        head = newPtr;
                        //cout<< "shape inserted case 0" << endl;
                        size = newSize;
                        return true;
                    }
                    break;
                case 1:
                    if( lR != 0 && lR != 3 ){
                        //cout<< "shape cannot fit case 1" << endl;
                        return false;
                    }
                    else{
                        newPtr->next = head;
                        head = newPtr;
                        //cout<< "shape inserted case 1" << endl;
                        size = newSize;
                        return true;
                    }
                    break;
                case 2:
                    //cout<< "shape cannot fit case 2" << endl;
                    return false;
                    break;
                case 3:
                    newPtr->next = head;
                    head = newPtr;
                    size = newSize;
                    return true;
                    break;
                default:
                    //cout<< "default" << endl;
                    return false;
                }
            }
        }
    }
    else if( index == maxSize ){
        PuzzlePiece *prev;
        if( find( index - 1 ) == NULL ){
            insert( index - 1, 255 );
        }
        prev = find( index - 1 );
        shapeConverter( getPiece(index - 1), dL, uL, rL, lL);
        //cout<< "left: " << rL << " right: " << lL << endl;
        //cout<< "second cond" << endl;
        switch (l)
        {
        case 0:
            if( rL != 1 && rL != 3 ){
                //cout<< "shape cannot fit case 0" << endl;
                return false;
            }
            else{
                newPtr->next = prev->next;
                prev->next = newPtr;
                //cout<< "shape inserted case 0" << endl;
                size = newSize;
                return true;
            }
            break;
        case 1:
            if( rL != 0 && rL != 3 ){
                //cout<< "shape cannot fit case 1" << endl;
                return false;
            }
            else{
                newPtr->next = prev->next;
                prev->next = newPtr;
                //cout<< "shape inserted case 1" << endl;
                size = newSize;
                return true;
            }
            break;
        case 2:
            //cout<< "shape cannot fit case 2" << endl;
            return false;
            break;
        case 3:
            newPtr->next = prev->next;
            prev->next = newPtr;
            //cout<< "dsas" << endl;
            return true;
            break;
        default:
            //cout<< "default" << endl;
            return false;
        }
    }
    else{
        PuzzlePiece *prev;
        if( find( index - 1 ) == NULL ){
            insert( index - 1, 255 );
        }
        prev = find( index - 1 );
        shapeConverter( getPiece(index - 1), dL, uL, rL, lL);
        shapeConverter( getPiece(index + 1), dR, uR, rR, lR);
        if( r == 1 && l == 1 ){
            if( (lR == 0 || lR == 3) && (rL == 0 || rL == 3) ){
                newPtr->next = prev->next;
                prev->next = newPtr;
                //cout<< "done" << endl;
                size = newSize;
                return true;
            }  
            else{
                //cout<< "shape cannot fit" << endl;
                return false;
            }
        }
        else if( r == 1 && l == 0 ){
            if( (lR == 0 || lR == 3) && (rL == 1 || rL == 3) ){
                if( (find(index) != NULL) ){
                    remove(index);
                }
                newPtr->next = prev->next;
                prev->next = newPtr;
                //cout<< "done" << endl;
                size = newSize;
                return true;
            }         
            else{
                //cout<< "shape cannot fit 1" << endl;
                return false;
            }
        }
        else if( r == 0 && l == 1 ){
            if( (lR == 1 || lR == 3) && (rL == 0 || rL == 3) ){
                newPtr->next = prev->next;
                prev->next = newPtr;
                //cout<< "done" << endl;
                size = newSize;
                return true;
            }        
            else{
                //cout<< "shape cannot fit" << endl;
                return false;
            }
        }
        else if( r == 0 && l == 0 ){
            if( (lR == 1 || lR == 3) && (rL == 1 || rL == 3) ){
                if( (find(index) != NULL) ){
                    remove(index);
                }
                newPtr->next = prev->next;
                prev->next = newPtr;
                //cout<< "done" << endl;
                size = newSize;
                return true;
            }        
            else{
                //cout<< "shape cannot fit" << endl;
                return false;
            }
        }
        else if( r == 3 || l == 3 ){
            newPtr->next = prev->next;
            prev->next = newPtr;
            //cout<< "done 3" << endl;
            size = newSize;
            return true;    
        }
    }
    size = newSize;
    return true;
}

bool PuzzleRow:: remove( int index ){
    //not working    
    return false;
}

bool PuzzleRow:: isEmpty(){
    return size == 0;      
}

char PuzzleRow:: getPiece( int index ){
    if( find(index) == NULL ){
        return 255;
    }
    else{
        return find(index)->shape;
    }
}

void PuzzleRow:: printRow(){
    PuzzlePiece *cur = head;
    for( int i = 1; i <= maxSize; i++ ){
        if( find(i) == NULL || getPiece(i) == char(255) ){
            cout<< "O ";
        }
        else{
            cout<< "X ";
        }
    }
}

PuzzleRow:: PuzzlePiece* PuzzleRow:: find( int index ){
    if ( (index < 1) || (index > maxSize) ){
        //cout<< "out of scope" << endl;
        return NULL;
    }
    else{ 
        if( head == NULL ){
            return NULL;
        }
        PuzzlePiece *cur = head;
        for (int skip = 1; skip < index; ++skip){
            cur = cur->next;
            if( cur == NULL ){
                return NULL;
            }
        }
        //cout<< "founded " << index << endl;
        return cur;
    }
}

int PuzzleRow:: getSize(){
    return size;
} 

void PuzzleRow:: setMaxRowIndex( int s ){
    this->maxRowIndex = s;
}