/*
    Ahmet Alperen Yılmazyıldız
    22002712
*/
#ifndef __CAR_H
#define __CAR_H
#include <string>
using namespace std;
class Car{
    public:    
        Car();
        Car( int pltNo, string typ );
        ~Car();

        void setPlate( int no );
        void setType( string t );
        int getPlate();
        string getType();

    private:
        int plateNo;
        string type;
};
#endif