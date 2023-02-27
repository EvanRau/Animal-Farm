///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         Animal Farm - EE 205 - Spr 2023
//
/// @file    ArrayDB.cpp
/// @author  Evan Rau <evanrau@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////
#include "ArrayDB.h"
#include <cstring>

Cat catDB[MAX_CATS];

void initDB(){
    memset(catDB, 0, sizeof(catDB));
}

int findNextBlank(){  //Empty values in array have all properties of cat set to 0; function iterates through
    int arrayVal = 0;           //Array to find an unused value and returns value
    while(catDB[arrayVal].weightInPounds != (float) 0){
        arrayVal++;
    }

    return arrayVal;

}

bool addCat(Cat Cat){
    int next = findNextBlank();
    if (next > MAX_CATS){
        return false;
    }
    catDB[next] = Cat;
    return true;
}

bool validateCatDB(){
    int totalCats = findNextBlank();
    for(int i = 0; i<=totalCats; i++){
        const bool test = validateCat(catDB[i]);
        if(!test) {
            return false;
        }
    }
    return true;
}
