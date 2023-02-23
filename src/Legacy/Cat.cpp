///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         Animal Farm - EE 205 - Spr 2023
//
///
/// @file    Cat.cpp
/// @author  Evan Rau <evanrau@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include "Cat.h"
const char* CatNames[35]
        = {"Kairi", "Oreo", "Cappuccino", "Wasabi", "Mango", "Mocha", "Kiwi", "Cookie",
           "Tito", "Mochi", "Clementine", "Ginger", "Maple", "Pepper", "Pickle",
           "Waffle", "Chip", "Miso", "Peanut", "Brownie", "Honey", "Jameson",
           "Butterscotch", "Cheerio", "Kit Kat", "Nilla", "Truffle", "Cheeto", "Java",
           "Olive", "Sushi", "Cheddar", "Meatball", "Whiskey", "Bingus"} ;


bool validateCat(Cat Cat){
    if (sizeof(Cat.Name) <= 0 || sizeof(Cat.Name) > MAX_CAT_NAME){ //Invalid Name
        return false;
    }
    if (Cat.Gender != MALE && Cat.Gender != FEMALE && Cat.Gender != UNKNOWN){ //Invalid Gender
        return false;
    }

    return true; //Valid Cat
}

struct Cat generateCat(){
    srand (static_cast <unsigned> (time(0))); //Seed random number generator
    struct Cat Cat; //Initializes Cat Struct to be filled in


    uint32_t temp = rand() % 35; //Generates Cat.Name
    const char* Name = CatNames[temp];
    Cat.Name = Name;


    temp = rand() % 3; //Generate Cat.Gender
    switch(temp) {
        case 0:
            Cat.Gender = UNKNOWN;
            break;
        case 1:
            Cat.Gender = MALE;
            break;
        case 2:
            Cat.Gender = FEMALE;
            break;
    }


    float random = ((float) rand()) / (float) RAND_MAX; //Generates random float for Cat.Weight
    float temp2 = random * (99.99 - 0.01);
    Cat.weightInPounds = temp2;


    temp = rand() % 4294967295; //Generate Cat.chipID
    Cat.chipID = temp;


    temp = rand() % 2; //Generate Cat.isFixed
    if(temp == 0){
        Cat.isFixed = true;
    }
    else{
        Cat.isFixed = false;
    }

    bool Validation = validateCat(Cat); //Runs validation test for
    if(Validation == true){
        return Cat;
    }
    else{
        printf("Error: Invalid Cat");
        return Cat;
    }
}

int printCat(Cat Cat){
    printf("Name: %s\n", Cat.Name);
    switch(Cat.Gender) {
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