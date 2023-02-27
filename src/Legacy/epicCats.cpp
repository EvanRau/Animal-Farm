///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         Animal Farm - EE 205 - Spr 2023
//
///
/// @file    epicCats.cpp
/// @author  Evan Rau <evanrau@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////
#include "ArrayDB.h"

/// Sets the total number of cats to be created & added to the Database
#define CATS_TO_GENERATE 10

/// Program to create cats, add cats to catDB, and print out every cat in the database
///
/// @returns the exit value
int main(){
    initDB(); //Initialized Global Array
    for(int i = 0; i < CATS_TO_GENERATE; i++){ //Creates cats to be added to array for defined number of times
        const Cat Cat = generateCat();
        addCat(Cat);
    }
    validateCatDB(); //Validates Array to ensure all cats are viable
    for(int i =0; i < CATS_TO_GENERATE; i++){
        printCat(catDB[i]);
    }

    return 0;
}