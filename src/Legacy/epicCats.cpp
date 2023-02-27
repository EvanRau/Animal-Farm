///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         Animal Farm - EE 205 - Spr 2023
//
///
/// @file    epicCats.cpp
/// @author  Evan Rau <evanrau@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////
#include "ArrayDB.h"

#define CATS_TO_GENERATE 10

int main(){
    initDB();
    for(int i = 0; i < CATS_TO_GENERATE; i++){
        const Cat Cat = generateCat();
        addCat(Cat);
    }
    validateCatDB();
    for(int i =0; i < CATS_TO_GENERATE; i++){
        printCat(catDB[i]);
    }

    return 0;
}