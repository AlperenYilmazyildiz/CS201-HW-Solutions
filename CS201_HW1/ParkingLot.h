/*
    Ahmet Alperen Yılmazyıldız
    22002712
*/
#ifndef __PARKINGLOT_H
#define __PARKINGLOT_H
#include "Car.h"
class ParkingLot{
    public:
        ParkingLot();
        ParkingLot( int id, int ro, int col );
        ParkingLot( ParkingLot& lot);
        ~ParkingLot();

        void setId( int );
        void setRow( int );
        void setColumn( int );
        void setPlaceSize( int );
        int getId();
        int getRow();
        int getColumn();
        int getPlaceSize();
        int getEmptySize();
        Car* getPlaces();
        Car* places;
        int emptySize;
        
    private:
        int lotId, row, column, placeSize;
        
};
#endif
