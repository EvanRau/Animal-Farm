///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         Animal Farm - EE 205 - Spr 2023
//
///
/// @file    Cat.cpp
/// @author  Evan Rau <evanrau@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////
#include "Cat.h"
#include <cstdio>
#include <cstdlib>



const char* CatNames[35]
        = {"Kairi", "Oreo", "Cappuccino", "Wasabi", "Mango", "Mocha", "Kiwi", "Cookie",
           "Tito", "Mochi", "Clementine", "Ginger", "Maple", "Pepper", "Pickle",
           "Waffle", "Chip", "Miso", "Peanut", "Brownie", "Honey", "Jameson",
           "Butterscotch", "Cheerio", "Kit Kat", "Nilla", "Truffle", "Cheeto", "Java",
           "Olive", "Sushi", "Cheddar", "Meatball", "Whiskey", "Bingus"} ;


bool validateCat(Cat Cat){
    int nameSize = sizeof(Cat.name);
    if (nameSize <= 0 || nameSize > MAX_CAT_NAME){ //Invalid name
        return false;
    }
    if (Cat.gender != MALE && Cat.gender != FEMALE && Cat.gender != UNKNOWN){ //Invalid gender
        return false;
    }

    return true; //Valid Cat
}

struct Cat generateCat(){
    struct Cat Cat; //Initializes Cat Struct to be filled in


    uint32_t temp = rand() % 35; //Generates Cat.name
    const char* Name = CatNames[temp];
    Cat.name = Name;


    temp = rand() % 3; //Generate Cat.gender
    switch(temp) {
        case 0:
            Cat.gender = UNKNOWN;
            break;
        case 1:
            Cat.gender = MALE;
            break;
        case 2:
            Cat.gender = FEMALE;
            break;
    }


    float random = ((float) rand()) / (float) RAND_MAX; //Generates random float for Cat.Weight
    float min = 0.01;
    float max = 99.99;
    float temp2 = random * (max - min);
    Cat.weightInPounds = temp2;


    temp = rand() % 4294967295; //Generate Cat.chipID
    Cat.chipID = temp;


    temp = rand() % 2; //Generate Cat.isFixed
    if(temp == 0){
        Cat.isFixed = false;
    }


    bool Validation = validateCat(Cat); //Runs validation test for
    if(Validation){
        return Cat;
    }
    printf("Error: Invalid Cat");
    return Cat;
}

int printCat(Cat Cat){
    printf("Name: %s\n", Cat.name);
    switch(Cat.gender) {
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
    printf("Weight: %.2f lb\n", Cat.weightInPounds);
    printf("Chip ID: %x\n", Cat.chipID);
    if (Cat.isFixed){
        printf("Is Fixed?: Yes\n");
    }
    else{
        printf("Is Fixed?: No\n");
    }
    return 0;
}