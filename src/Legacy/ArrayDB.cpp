///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         Animal Farm - EE 205 - Spr 2023
//
/// @file    ArrayDB.cpp
/// @author  Evan Rau <evanrau@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////
#include "ArrayDB.h"
#include <cstring>
#include <cstdio>

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

/// Updates the name of a cat in the DB
///
/// \param catNum
/// \param name
/// @returns false if there is no cat or if the name is invalid. else return true
bool updateCatName(int catNum, const char* name){
    if(strlen(catDB[catNum].name) == 0 ){ //Checks that the cat exists in the DB
        printf("ERROR:Cat does not exist\n");
        return false;
    }
    const char* nameOld = catDB[catNum].name; //Holds onto old name in case new one is invalid

    catDB[catNum].name = name;

    if(!validateCat(catDB[catNum])){ //Checks that new cat is valid. reverts change if not
        printf("ERROR: Invalid new name! Reverting change.\n");
        catDB[catNum].name = nameOld;
        return false;
    }

    return true;
}

/// Updates the gender of a cat in the DB
///
/// \param catNum
/// \param gender
/// @returns false if there is no cat or if the name is invalid. else return true
bool updateCatGender(int catNum, Gender gender){
    if(strlen(catDB[catNum].name) == 0 ){ //Checks that the cat exists in the DB
        printf("ERROR:Cat does not exist\n");
        return false;
    }
    Gender genderOld = catDB[catNum].gender; //Holds onto old gender in case new one is invalid

    catDB[catNum].gender = gender;

    if(!validateCat(catDB[catNum])){ //Checks that new cat is valid. reverts change if not
        printf("ERROR: Invalid new name! Reverting change.\n");
        catDB[catNum].gender = genderOld;
        return false;
    }

    return true;
}

/// Updates the weight of a cat in the DB
///
/// \param catNum
/// \param weight
/// @returns false if there is no cat or if the name is invalid. else return true
bool updateCatWeight(int catNum, float weight) {
    if (strlen(catDB[catNum].name) == 0) { //Checks that the cat exists in the DB
        printf("ERROR:Cat does not exist\n");
        return false;
    }
    float weightOld = catDB[catNum].weightInPounds; //Holds onto old weight in case new one is invalid

    catDB[catNum].weightInPounds = weight;

    if (!validateCat(catDB[catNum])) { //Checks that new cat is valid. reverts change if not
        printf("ERROR: Invalid new name! Reverting change.\n");
        catDB[catNum].weightInPounds = weightOld;
        return false;
    }

    return true;
}