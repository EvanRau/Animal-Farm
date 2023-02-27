///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         Animal Farm - EE 205 - Spr 2023
//
///
/// @file    ArrayDB.cpp
/// @author  Evan Rau <evanrau@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////
#include <cstring>
#include "ArrayDB.h"

Cat CatDB[MAX_CATS];

void initDB(){
    memset(CatDB, 0, sizeof( CatDB) );
    return;
}

int findNextBlank(Cat* catDB){  //Empty values in array have all properties of cat set to 0; function iterates through
    int arrayVal = 0;           //Array to find an unused value and returns value
    while(catDB[arrayVal].weightInPounds != 0){
        arrayVal++;
    }
    return arrayVal;
}

bool addCat(Cat Cat, struct Cat* catDB){
    int next = findNextBlank(catDB);
    catDB[next] = Cat;
    return true;
}

bool validateCatDB(Cat* catDB){
    int totalCats = findNextBlank(catDB);
    for(int i = 0; i<=totalCats; i++){
        const bool test = validateCat(catDB[i]);
        if(!test) {
            return false;
        }
    }
    return true;
}
