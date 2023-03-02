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

#include <cstdint> // For uint32_t

#define MAX_CAT_NAME 40


enum Gender {MALE, FEMALE, UNKNOWN};


struct Cat{
    const char* name;
    Gender      gender;
    float       weightInPounds;
    uint32_t    chipID;
    bool        isFixed;
};

extern bool validateCat(Cat Cat);

extern struct Cat generateCat();

extern int printCat(Cat Cat);

extern bool updateCatName(int catNum, const char* name);

extern bool updateCatGender(int catNum, Gender gender);

extern bool updateCatWeight(int catNum, float weight);

extern bool updateCatID(int catNum, uint32_t chipID);

extern bool updateCatFixed(int catNum, bool Fixed);

#endif //EE205_ANIMAL_FARM_CAT_H
