///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         Animal Farm - EE 205 - Spr 2023
//
///
/// @file    epicCats.cpp
/// @author  Evan Rau <evanrau@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////
#include "ArrayDB.h"
#include "Cat.h"

int main(){
    Cat Cat = generateCat();
    struct Cat* CatDB = initDB();
    addCat(Cat, CatDB);
    printCat(CatDB[0]);

    return 0;
}