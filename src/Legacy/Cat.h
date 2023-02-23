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



typedef enum Gender {MALE, FEMALE, UNKNOWN} Gender;

typedef struct Cat{
    const char* Name;
    Gender Gender;
    float weightInPounds;
    uint32_t chipID;
    bool isFixed;
} Cat;

bool validateCat(Cat Cat);

struct Cat generateCat();

int printCat(Cat Cat);

#endif //EE205_ANIMAL_FARM_CAT_H
