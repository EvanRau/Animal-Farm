///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         Animal Farm - EE 205 - Spr 2023
//
/// @file    ArrayDB.cpp
/// @author  Evan Rau <evanrau@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////
#include "ArrayDB.h"
#include <cstring>

/// Global array for cat database
Cat catDB[MAX_CATS];
/// Initializes catDB so that all members are set to 0
void initDB(){
    memset(catDB, 0, sizeof(catDB)); //Sets the memory for all values of Cat in catDB to 0
}
/// Finds next blank member in catDB
///
/// @returns the value i of the next blank cat for catDB[i]
int findNextBlank(){  //Empty values in array have all properties of cat set to 0; function iterates through
    int arrayVal = 0;           //Array to find an unused value and returns value
    while(catDB[arrayVal].weightInPounds != (float) 0){
        arrayVal++;
    }

    return arrayVal;

}

/// Adds a new cat to catDB
///
/// \param cat
/// @returns true if there is room in catDB for a new cat
bool addCat(Cat cat){
    int next = findNextBlank(); //Finds empty spot in array
    if (next > MAX_CATS){ //Checks if value is > size of array
        return false;
    }
    catDB[next] = cat; //Adds cat to array
    return true;
}

/// Validates all cats in catDB
///
/// @returns false if there are more cats in catDB than allowed or if a cat in catDB failed a test
bool validateCatDB(){
    int totalCats = findNextBlank();
    if (totalCats > MAX_CATS){ //Checks if value is > size of array
        return false;
    }
    for(int i = 0; i<totalCats; i++){ //Validates each cat in array
        const bool test = validateCat(catDB[i]);
        if(!test) {
            return false;
        }
    }
    return true;
}
