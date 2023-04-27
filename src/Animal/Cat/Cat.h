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

#include "../Mammal/Mammal.h"
using namespace std;

class Cat : public Mammal {
public:
    ///Default constructor for a Cat
    Cat() : Mammal( "Unknown Color", Gender::UNKNOWN_GENDER){
    }
    ///Cat constructor given a color and gender
    Cat(const string &newColor, const Gender newGender) : Mammal(newColor, newGender){
    }
    string_view speak() const noexcept{
        return "Meow";
    }
};


#endif //EE205_ANIMAL_FARM_CAT_H
