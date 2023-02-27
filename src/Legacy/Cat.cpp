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

#define TOTAL_NAMES 35


const char* CatNames[TOTAL_NAMES]
        = {"Kairi", "Oreo", "Cappuccino", "Wasabi", "Mango", "Mocha", "Kiwi", "Cookie",
           "Tito", "Mochi", "Clementine", "Ginger", "Maple", "Pepper", "Pickle",
           "Waffle", "Chip", "Miso", "Peanut", "Brownie", "Honey", "Jameson",
           "Butterscotch", "Cheerio", "Kit Kat", "Nilla", "Truffle", "Cheeto", "Java",
           "Olive", "Sushi", "Cheddar", "Meatball", "Whiskey", "Bingus"} ;


bool validateCat(Cat cat){
    int nameSize = sizeof(cat.name);
    if (nameSize <= 0 || nameSize > MAX_CAT_NAME){ //Invalid name
        return false;
    }
    if (cat.gender != MALE && cat.gender != FEMALE && cat.gender != UNKNOWN){ //Invalid gender
        return false;
    }
    if (cat.weightInPounds <= 0 || cat.weightInPounds > 100){
        return false;
    }

    return true; //Valid cat
}

struct Cat generateCat(){
    struct Cat cat = {}; //Initializes cat Struct to be filled in

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
        cat.isFixed = false;
    }


    bool Validation = validateCat(cat); //Runs validation test for cat
    if(Validation){
        return cat;
    }
    printf("Error: Invalid cat");
    return cat;
}

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