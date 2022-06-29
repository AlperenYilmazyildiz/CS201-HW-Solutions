/*
    Ahmet Alperen Yılmazyıldız
    22002712
*/
#include "ParkingLot.h"
#include "Car.h"
#include <iostream>
using namespace std;

ParkingLot:: ParkingLot(){
    lotId = 0;
    row = 0;
    column = 0;
    placeSize = 0;
    emptySize = 0;
    places = NULL;
}

ParkingLot:: ParkingLot( int id, int ro, int col ){
    lotId = id;
    row = ro;
    column = col;
    placeSize = row * column;
    emptySize = row * column;
    places = NULL;
}

ParkingLot:: ~ParkingLot(){
    if( placeSize > 0 ){
        delete[] places;
    }
}

ParkingLot:: ParkingLot( ParkingLot& lot ){
    if( row == 0 || column == 0 ){
        lotId = 0;
        row = 0;
        column = 0;
        placeSize = 0;
        emptySize = 0;
        places = NULL;
    }
    else{
        lotId = lot.lotId;
        row = lot.row;
        column = lot.column;   
        placeSize = lot.placeSize;
        emptySize = lot.emptySize;
        if( lot.places != NULL ){
            for( int i = 0; i < placeSize; i++ ){
                places[i] = lot.places[i];
            }  
        }
        else{
            places = NULL; 
        }
    }
    
}

void ParkingLot:: setId( int id ){
    lotId = id;
}

void ParkingLot:: setRow( int noOfRow ){
    row = noOfRow;
}

void ParkingLot:: setColumn( int noOfCol ){
    column = noOfCol;
}

void ParkingLot:: setPlaceSize( int pSize ){
    placeSize = pSize;
}

int ParkingLot:: getId(){
    return lotId;
}

int ParkingLot:: getRow(){
    return row;
}

int ParkingLot:: getColumn(){
    return column;
}

int ParkingLot:: getPlaceSize(){
    return placeSize;
}

Car* ParkingLot:: getPlaces(){
    return places;
}

int ParkingLot:: getEmptySize(){
    return emptySize;
}



