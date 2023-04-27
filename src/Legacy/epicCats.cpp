///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         Animal Farm - EE 205 - Spr 2023
//
/// Tests legacy functions by generating a database and adding cats to said database
///
/// @file    epicCats.cpp
/// @author  Evan Rau <evanrau@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////
#include "ArrayDB.h"
#include <cstdio>
#include <cstdlib>


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

    //Proof of update functions
    updateCatName(2, "Bingus");
    updateCatGender(2, UNKNOWN);
    updateCatWeight(2, 42.0);
    const uint32_t newID  = rand() % 4294967295;
    updateCatID(2, newID);
    updateCatFixed(2, true);

    printf("Updated Cat\n");
    printCat(catDB[2]); //Prints updated cat

    catDB[2] = deleteCat(); //Deletes Bingus

    const Cat newCat = generateCat(); //Creates new cat to replace Bingus
    addCat(newCat); // Adds new cat to fill the void left by bingus
    printf("Deleted and replaced Cat\n");
    printCat(catDB[2]); // Prints replacement cat
    return 0;
}