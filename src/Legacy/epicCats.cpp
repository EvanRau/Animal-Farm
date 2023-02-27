///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         Animal Farm - EE 205 - Spr 2023
//
///
/// @file    epicCats.cpp
/// @author  Evan Rau <evanrau@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////
#include "ArrayDB.h"

int main(){
    initDB();
    for(int i = 0; i < 10; i++){
        const Cat Cat = generateCat();
        addCat(Cat, CatDB);
    }
    validateCatDB(CatDB);
    for(int i =0; i < 10; i++){
        printCat(CatDB[i]);
    }

    return 0;
}