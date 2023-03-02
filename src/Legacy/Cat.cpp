///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         Animal Farm - EE 205 - Spr 2023
//
/// @file    Cat.cpp
/// @author  Evan Rau <evanrau@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////

#include "Cat.h"
#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <time.h>

///Total number of names in CatNames
#define TOTAL_NAMES 35

///A list of all possible cats
const char* CatNames[TOTAL_NAMES]
        = {"Kairi", "Oreo", "Cappuccino", "Wasabi", "Mango", "Mocha", "Kiwi", "Cookie",
           "Tito", "Mochi", "Clementine", "Ginger", "Maple", "Pepper", "Pickle",
           "Waffle", "Chip", "Miso", "Peanut", "Brownie", "Honey", "Jameson",
           "Butterscotch", "Cheerio", "Kit Kat", "Nilla", "Truffle", "Cheeto", "Java",
           "Olive", "Sushi", "Cheddar", "Meatball", "Whiskey", "Bingus"} ;

/// Tests that the cat doesnt contain an illegal value for its name or weight
/// \param cat
/// @returns false if the Name or Weight is invalid
bool validateCat(Cat cat){
    size_t test = strlen(cat.name);
    if (test == 0 || test > MAX_CAT_NAME){ //Invalid name
        return false;
    }
    if (cat.weightInPounds <= 0 || cat.weightInPounds > 100){
        return false;
    }

    return true; //Valid cat
}

/// Generates a new cat randomly
/// @returns false if the generated cat is invalid
/// @see validateCat
struct Cat generateCat(){
    struct Cat cat = {}; //Initializes cat Struct to be filled in

    int srandSeeder = rand(); //function called multiple times per second, so time(nullptr) isn't sufficient for seeding
    srand(time(nullptr)-srandSeeder); //subtracting a random number from time(nullptr) resolves issue
    int randName = rand() % TOTAL_NAMES; //Generates cat.name
    const char* Name = CatNames[randName];
    cat.name = Name;


    int randGender = rand() % 3; //Generate cat.gender
    switch(randGender) {
        case 0:
            cat.gender = UNKNOWN;
            break;
        case 1:
            cat.gender = MALE;
            break;
        case 2:
            cat.gender = FEMALE;
            break;
    }


    const float random = ((float) rand()) / (float) RAND_MAX; //Generates random float for cat.Weight
    float min = 0.01;
    float max = 99.99;
    float randWeight = random * (max - min);
    cat.weightInPounds = randWeight;


    uint32_t randID = rand() % 4294967295; //Generate cat.chipID
    cat.chipID = randID;


    int randFixed = rand() % 2; //Generate cat.isFixed
    if(randFixed == 0){
        cat.isFixed = true;
    }



    bool Validation = validateCat(cat); //Runs validation test for cat
    if(Validation){
        return cat;
    }
    printf("Error: Invalid cat");
    return cat;
}

/// Prints the values of the generated cat
///
/// @returns the exit value
int printCat(Cat cat){
    printf("Name: %s\n", cat.name);
    switch(cat.gender) {
        case MALE:
            printf("Gender: Male\n");
            break;
        case FEMALE:
            printf("Gender: Female\n");
            break;
        case UNKNOWN:
            printf("Gender: Unknown\n");
            break;
    }
    printf("Weight: %.2f lb\n", cat.weightInPounds);
    printf("Chip ID: %x\n", cat.chipID);
    if (cat.isFixed){
        printf("Is Fixed?: Yes\n\n");
    }
    else{
        printf("Is Fixed?: No\n\n");
    }
    return 0;
}

bool updateCatName(int catNum, const char* name){}