/*
    Ahmet Alperen Yılmazyıldız
    22002712
*/
#include "Car.h"
#include <iostream>
using namespace std;

Car:: Car(){
    plateNo = -1;
    type = "";
}

Car:: Car( int pltNo, string typ ){
    plateNo = pltNo;
    type = typ;    
}

Car:: ~Car(){
    
}

void Car:: setPlate( int no ){
    plateNo = no;
}

void Car:: setType( string t ){
    type = t;
}

int Car:: getPlate(){
    return plateNo;
}

string Car:: getType(){
    return type;
}


