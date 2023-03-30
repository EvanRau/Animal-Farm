///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         Animal Farm - EE 205 - Spr 2023
//
///
/// @file    Animal.cpp
/// @author  Evan Rau <evanrau@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////

#include "Animal.h"

///Gets the kingdom of a given animal
///@returns animal.kingdom (Is always Animalia)
std::string_view getKingdom(const Animal& animal){
    return animal.kingdom;
}

std::string info(const Animal& animal){
    return animal.info;
}

///Gets the gender of a given animal
///@returns animal.gender
Gender getGender(const Animal& animal){
    return animal.gender;
}

///Changes the gender of a given animal if it is currently UNKNOWN_GENDER
void setGender(Animal animal, Gender setGender){
    if(animal.gender == Gender::UNKNOWN_GENDER){
        animal.gender = setGender;
    }
}

bool validate(const Animal& animal){
    return !getKingdom(animal).empty() && !info(animal).empty() && validateGender(getGender(animal));
}

