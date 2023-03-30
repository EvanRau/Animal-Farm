///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         Animal Farm - EE 205 - Spr 2023
//
///
/// @file    Animal.h
/// @author  Evan Rau <evanrau@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////

#ifndef EE205_ANIMAL_FARM_ANIMAL_H
#define EE205_ANIMAL_FARM_ANIMAL_H


#include "../Utility/Gender.h"
#include <string>

///Properties of an animal. Includes its gender and its kingdom
class Animal {
    public:
        ///Gender of animal; Unknown by default
        Gender gender = Gender::UNKNOWN_GENDER;
        ///Kingdom of animal (always Animalia)
        std::string_view Kingdom = "Animalia";
        ///Info of an animal; "An animal" by default
        std::string info = "An animal";
};

extern std::string_view getKingdom(Animal animal);

extern Gender getGender(Animal animal);

extern void setGender(Animal animal);

extern bool validate(Animal animal);

extern std::string info(Animal animal);

extern void dump(Animal animal);


#endif //EE205_ANIMAL_FARM_ANIMAL_H
