/*
    Ahmet Alperen Yılmazyıldız
    22002712
*/
#include "ParkingSystem.h"
#include "ParkingLot.h"
#include "Car.h"
#include <string>
#include <iostream>
using namespace std;

ParkingSystem:: ParkingSystem(){
    lotSize = 0;   
    lots = NULL;
}

ParkingSystem:: ~ParkingSystem(){
    delete[] lots;
}

void ParkingSystem:: createLot( int id, int rows, int columns ){
    if( checkId(lots, id) ){
        if( rows < 13 && columns < 13 ){
            if( lotSize == 0 ){
                lotSize++;
                lots = new ParkingLot[lotSize];
                ParkingLot* lot = new ParkingLot( id, rows, columns );
                lots[0] = *lot;
                delete lot;
                cout<< "The lot " << id << " is created" << endl;
            }
            else{
                ParkingLot* temp = lots;
                lots = new ParkingLot[lotSize + 1];
                for( int i = 0; i < lotSize; i++){
                    lots[i] = temp[i];
                }
                ParkingLot* lot = new ParkingLot( id, rows, columns );
                lots[lotSize] = *lot;
                lotSize++;
                delete lot;
                delete [] temp;
                cout<< "The lot " << id << " is created" << endl;

            }
        }
        else{
            cout<< "Cannot create parking lot " << id << " rows and columns cannot be larger than 13" << endl;
        }
    }
    else{
        cout<< "Cannot create parking lot " << id << " a lot with this ID already exists" << endl;
    }
}

void ParkingSystem:: removeLot( int id ){
    if( checkId( lots, id ) ){
        cout<< "There is no parking lot with ID: " << id << endl;
    }
    else if( lotSize == 0){
        cout<< "There are no parking lots" << endl;
    }
    else{
        if( lotSize == 1 ){
            ParkingLot* temp = lots;
            lots = NULL;
            lotSize--;
            delete[] temp;
            cout<< "Lot " << id << " has been succesfully removed from the system" << endl;
        }  
        else{  
            ParkingLot* temp = lots;
            int index = 0;
            for( int i = 0; i < lotSize; i++ ){
                if( temp[i].getId() == id ){
                    index = i;
                }   
            }
            if( temp[index].getPlaces() == NULL ){
                lots = new ParkingLot[lotSize];
                for( int i = 0; i < index; i++ ){
                    lots[i] = temp[i];
                } 
                for( int i = index + 1; i < lotSize; i++ ){
                    lots[i-1] = temp[i];
                }
                cout<< "Lot " << id << " has been succesfully removed from the system" << endl;
                lotSize--;
            }
            else{
                cout<< "For this part of code, I cannot properly worked removeLot function for parking lot that contains car inside" << endl;  
            } 
            delete[] temp;
        }   
    }
}

void ParkingSystem:: listLots(){
    if( lotSize == 0 ){
        cout<< "there is no lot to list" << endl;
    }
    for( int i = 0; i < lotSize; i++ ){
        cout<< "ID: " << lots[i].getId() << ", Dim: " << lots[i].getRow() << "x" << lots[i].getColumn() << " number of empty spaces: " << lots[i].getEmptySize() << endl;
    }    
}

void ParkingSystem:: lotContents( int id ){
    string letters = "ABCDEFGHIJKL";
    int ind, check;
    for( int i = 0; i < lotSize; i++ ){
        if( lots[i].getId() == id ){
            ind = i;
            check = 1;
            break;
        }
        else{
            check = 0;
        }
    }

    if( check == 1 ){
        cout<< "ID: " << id << ", " << lots[ind].getRow() << "x" << lots[ind].getColumn() << ", empty slots: " << lots[ind].getEmptySize() << " parked cars ";
        if( lots[ind].places != NULL ){
            for( int i = 0; i < lots[ind].getPlaceSize(); i++ ){
                if( lots[ind].places[i].getPlate() > 0 ){
                    cout << lots[ind].places[i].getPlate() << ", ";
                }
            }
            cout<< "" << endl;
            for( int j = 0; j < lots[ind].getRow() + 1; j++){
                for( int k = 0; k < lots[ind].getColumn() + 1; k++ ){
                    if( j == 0 && k == 0 ){
                        cout<< " ";
                    }
                    else if( k == 0 ){
                        cout<< letters[j - 1];
                    }
                    else if( j == 0 ){
                        cout<< " " << k << " "; 
                    }
                    else{   
                        int loc = ((j - 1) * (lots[ind].getColumn()) + k) - 1;
                        if( lots[ind].places[loc].getType() == "a" ){
                            cout<< " a ";
                        }
                        else if( lots[ind].places[loc].getType() == "b" ){
                            cout<< " b ";
                        } 
                        else{
                            cout<< " + ";
                        } 
                    }  
                }
                cout<< "" << endl;
            }    
        }
        else{
            cout<< "no cars yet" << endl;
            for( int j = 0; j < lots[ind].getRow() + 1; j++){
                for( int k = 0; k < lots[ind].getColumn() + 1; k++ ){
                    if( j == 0 && k == 0 ){
                        cout<< " ";
                    }
                    else if( k == 0 ){
                        cout<< letters[j - 1];
                    }
                    else if( j == 0 ){
                        cout<< " " << k << " "; 
                    } 
                    else{
                        cout<< " + ";
                    }   
                }
                cout<< "" << endl;
            }
        }   
    }
    else{
        cout<< "There is no parking lot with ID " << id << endl;
    }    
    
}

void ParkingSystem:: parkCar( int lotId, string location, string carType, int plateNumber ){
    bool exists = false;
    for( int i = 0; i < lotSize; i++ ){
        if( lots[i].places != NULL ){
            for( int j = 0; j < lots[i].getPlaceSize(); j++ ){
                if( lots[i].places[j].getPlate() == plateNumber ){
                    exists = true;
                    break;
                }
            }
        }
    }

    if( exists ){
        cout<< "A car with plate number " << plateNumber << " already exists in the system" << endl; 
    }
    else{
        int indicator, check;
        for( int i = 0; i < lotSize; i++ ){
            if( lotId == lots[i].getId() ){
                indicator = i;  
                check = 1;
                break;
            }
            else if( i == lotSize - 1){
                check = 0;
            }
        }
        if( check == 0 ){
            cout << "the parking lot with indicated id is not found" << endl;
        }
        else{
            Car* car = new Car( plateNumber, carType );
            int rowLoc = location[0] - 64;
            int columnLoc = toInt( location.substr(1, 2) );
            int parkLoc = (rowLoc - 1) * (lots[indicator].getColumn()) + columnLoc - 1;
            if( parkLoc > lots[indicator].getColumn() * lots[indicator].getRow() ){
                cout << "location is outside of the parking lot" << endl;
            }
            else{
                if( lots[indicator].getPlaces() == NULL ){
                    lots[indicator].places = new Car[lots[indicator].getPlaceSize()];
                    for( int i = 0; i < lots[indicator].getPlaceSize(); i++ ){
                        Car* c = new Car();
                        lots[indicator].places[i] = *c;
                        delete c;
                    }
                    if( car->getType() == "a" ){
                        lots[indicator].places[parkLoc] = *car;
                        lots[indicator].emptySize--;
                        cout << "Light-duty car with plate number " << plateNumber << " parked at " << location << ", lot " << lotId << endl;
                    }
                    else if( car->getType() == "b" ){
                        if( rowLoc == 1 ){
                            cout<< "heavy cars cannot fit here" << endl;
                        }
                        else{
                            lots[indicator].places[parkLoc - lots[indicator].getColumn()] = *car; 
                            lots[indicator].places[parkLoc] = *car;
                            lots[indicator].emptySize--;
                            lots[indicator].emptySize--;
                            cout << "Heavy-duty car with plate number " << plateNumber << " parked at " << location << ", lot " << lotId << endl;                   
                        }
                    } 
                }
                else{
                    if( lots[indicator].places[parkLoc].getType() == "" ){
                        if( car->getType() == "a" ){
                            lots[indicator].places[parkLoc] = *car;
                            lots[indicator].emptySize--;
                            cout << "Light-duty car with plate number " << plateNumber << " parked at " << location << ", lot " << lotId << endl;
                        }
                        else if( car->getType() == "b" ){
                            if( rowLoc == 1 ){
                                cout<< "heavy cars cannot fit here" << endl;
                            }
                            else{
                                lots[indicator].places[parkLoc - lots[indicator].getColumn()] = *car; 
                                lots[indicator].places[parkLoc] = *car;
                                lots[indicator].emptySize--;
                                lots[indicator].emptySize--;
                                cout << "Heavy-duty car with plate number " << plateNumber << " parked at " << location << ", lot " << lotId << endl;
                            }
                        }  
                    }
                    else{
                        cout<< "the current spot is occupied" << endl;
                    }  
                }
                delete car;
            }
        }
    }
    
}

void ParkingSystem:: findCar( int plateNumber ){
    bool exist = false;
    for( int i = 0; i < lotSize; i++ ){
        if( lots[i].places != NULL ){
            for( int j = 0; j < lots[i].getPlaceSize(); j++ ){
                if( lots[i].places[j].getPlate() == plateNumber){
                    if( lots[i].places[j].getType() == "a" ){
                        cout<< "Light-duty car with number plate " << plateNumber << " is at lot " << lots[i].getId() << endl;
                        exist = true;
                        break;
                    }
                    else if( lots[i].places[j].getType() == "b" ){
                        cout<< "Heavy-duty car with number plate " << plateNumber << " is at lot " << lots[i].getId() << endl;
                        exist = true;
                        break;
                    }
                }
            }  
        }
    }

    if( !exist ){
        cout<< "There is no car with plate number " << plateNumber << endl;
    }
}

void ParkingSystem:: removeCar( int plateNumber ){
    bool exists = false;
    for( int i = 0; i < lotSize; i++ ){
        if( lots[i].places != NULL ){
            for( int j = 0; j < lots[i].getPlaceSize(); j++ ){
                if( lots[i].places[j].getPlate() == plateNumber ){
                    exists = true;
                    break;
                }
            }
        }
    }

    if( !exists ){
        cout<< "There is no car with plate number " << plateNumber << endl;
    }
    else{
        int indLot, indPlc;
        string typ;
        Car* c = new Car();
        for( int i = 0; i < lotSize; i++ ){
            if( lots[i].places != NULL ){
                for( int j = 0; j < lots[i].getPlaceSize(); j++ ){
                    if( lots[i].places[j].getPlate() == plateNumber ){
                        indLot = i;
                        indPlc = j; 
                        if( lots[i].places[j].getType() == "a" ){
                            typ = "a";
                        }
                        else{
                            typ = "b";
                        }
                        break;
                    }
                }
            }
        }
        int size = lots[indLot].getPlaceSize();
        int col = lots[indLot].getColumn();
        Car* temp = lots[indLot].places;
        lots[indLot].places = new Car[ size ];
        for( int i = 0; i < lots[indLot].getPlaceSize(); i++ ){
            if( typ == "a" ){
                for( int j = 0; j < indPlc; j++ ){
                    lots[indLot].places[j] = temp[j];
                }
                for( int j = indPlc + 1; j < lots[indLot].getPlaceSize(); j++ ){
                    lots[indLot].places[j] = temp[j];
                }
                lots[indLot].places[indPlc] = *c; 
            }
            else{
                for( int j = 0; j < indPlc; j++ ){
                    lots[indLot].places[j] = temp[j];
                }
                for( int j = indPlc + 1; j < indPlc + col; j++ ){
                    lots[indLot].places[j] = temp[j];
                }
                for( int j =  indPlc + col + 1; j < lots[indLot].getPlaceSize(); j++ ){
                    lots[indLot].places[j] = temp[j];
                }
                lots[indLot].places[indPlc] = *c; 
                lots[indLot].places[indPlc + col] = *c;
            }   
        }
        if( typ == "a" ){
            cout<< "Light-duty car with plate number " << plateNumber << " removed from lot " << lots[indLot].getId() << endl;
        }
        else{
            cout<< "Heavy-duty car with plate number " << plateNumber << " removed from lot " << lots[indLot].getId() << endl;
        }
        delete c;
        delete[] temp;
    } 
}

/*
    This function's purpose is to convert location string into integer that indicates 
    index of places array
*/
int ParkingSystem:: toInt( string s ){
    int out;
    if( s[1] != '\0' ){
          out = (s[0] - 48)*10 + (s[1] - 48 );
     }
     else{ 
          out = s[0] - 48;
     }     
     return out;  
}

/*
    This function checks for unique lot id returns true if the entered id is unique
*/
bool ParkingSystem:: checkId( ParkingLot* l, int id ){
    for( int i = 0; i < lotSize; i++ ){
        if( l[i].getId() == id ){
            return false;
        }
    }
    return true;
}


