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

typedef enum Gender {MALE, FEMALE, UNKNOWN};

typedef struct CAT{
    char Name[MAX_CAT_NAME];
    Gender;
    float weightInPounds;
    uint32_t chipID;
    bool isFixed;

};

#endif //EE205_ANIMAL_FARM_CAT_H
