///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         Animal Farm - EE 205 - Spr 2023
//
///
/// @file    Cat.h
/// @author  Evan Rau <evanrau@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////

#ifndef EE205_ANIMAL_FARM_CAT_H
#define EE205_ANIMAL_FARM_CAT_H

#include <cstdint>
#define MAX_CAT_NAME 40
const char* CatNames[35]
    = {"Kairi", "Oreo", "Cappuccino", "Wasabi", "Mango", "Mocha", "Kiwi", "Cookie",
       "Tito", "Mochi", "Clementine", "Ginger", "Maple", "Pepper", "Pickle",
       "Waffle", "Chip", "Miso", "Peanut", "Brownie", "Honey", "Jameson",
       "Butterscotch", "Cheerio", "Kit Kat", "Nilla", "Truffle", "Cheeto", "Java",
       "Olive", "Sushi", "Cheddar", "Meatball", "Whiskey", "Bingus"} ;


typedef enum Gender {MALE, FEMALE, UNKNOWN};

typedef struct Cat{
    char Name[MAX_CAT_NAME];
    Gender Gender;
    float weightInPounds;
    uint32_t chipID;
    bool isFixed;

};

bool validateCat(Cat Cat);

struct Cat generateCat();

#endif //EE205_ANIMAL_FARM_CAT_H
