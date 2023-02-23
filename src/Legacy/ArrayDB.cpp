///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         Animal Farm - EE 205 - Spr 2023
//
///
/// @file    ArrayDB.cpp
/// @author  Evan Rau <evanrau@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////
#include "ArrayDB.h"


Cat* initDB(){
    const int temp = MAX_CATS;
    static Cat CatDB[temp] ;
    return CatDB;
}

bool addCat(Cat Cat, struct Cat* CatDB){
    int temp = 0;
    while(CatDB[temp].weightInPounds != 0){
        temp++;
    }
    CatDB[temp] = Cat;
    return true;
}

bool validateCatDB(Cat* CatDB){
    int totalCats = 0;
    while(CatDB[totalCats].weightInPounds != 0){
        totalCats++;
    }
    for(int i = 0; i<=totalCats; i++){
        const bool test = validateCat(CatDB[i]);
        if(!test) {
            return false;
        }
    }
    return true;
}