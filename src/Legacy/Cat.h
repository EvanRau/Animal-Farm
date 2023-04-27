///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         Animal Farm - EE 205 - Spr 2023
//
/// Holds info on creating and validating cats
///
/// @file    Cat.h
/// @author  Evan Rau <evanrau@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////

#ifndef EE205_ANIMAL_FARM_CAT_H
#define EE205_ANIMAL_FARM_CAT_H

#include <cstdint> // For uint32_t

///Largest allowed cat name
#define MAX_CAT_NAME 40

///All known cat genders
enum Gender {MALE, FEMALE, UNKNOWN};

///All necessary properties of a given cat
struct Cat{
    ///Name of cat
    const char* name;
    ///Gender of cat
    Gender      gender;
    ///Weight of cat in lb
    float       weightInPounds;
    ///ID of cat
    uint32_t    chipID;
    ///Whether or not cat is fixed
    bool        isFixed;
};

extern bool validateCat(Cat Cat);

extern struct Cat generateCat();

extern int printCat(Cat Cat);

#endif //EE205_ANIMAL_FARM_CAT_H
