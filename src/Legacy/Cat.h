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

/// Largest possible name of cat
#define MAX_CAT_NAME 40

/// Defined genders of cats
enum Gender {MALE, FEMALE, UNKNOWN};

/// All necessary values of a given cat to be documented
struct Cat{
    /// Name of given cat
    const char* name;
    /// Gender of given cat
    Gender      gender;
    /// Weight of given cat in pounds
    float       weightInPounds;
    /// chip ID of given cat
    uint32_t    chipID;
    /// Whether or not given cat is fixed
    bool        isFixed;
};

extern bool validateCat(Cat cat);

extern struct Cat generateCat();

extern int printCat(Cat cat);

#endif //EE205_ANIMAL_FARM_CAT_H
