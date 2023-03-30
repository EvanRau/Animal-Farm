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

#include <iostream>
#include <string>
#include <iomanip>

#define quote(x) #x
using namespace std;


///Properties of an animal. Includes its gender and its kingdom
class Animal {
    private:
        ///Gender of animal; Unknown by default
        Gender gender = Gender::UNKNOWN_GENDER;
        ///kingdom of animal (always Animalia)
        string_view kingdom = "Animalia";
    public:
        Animal() : gender(Gender::UNKNOWN_GENDER) {
        }
        explicit Animal(Gender gender) : gender(gender) {
        }
        static string_view getKingdom(const Animal& animal){
            return animal.kingdom;
        }
        static Gender getGender(const Animal& animal){
        return animal.gender;
        }
        static void setGender(Animal animal, Gender setGender){
        if(animal.gender == Gender::UNKNOWN_GENDER){
            animal.gender = setGender;
            }
        }
        static bool validate(const Animal& animal){
            return !Animal::getKingdom(animal).empty() && validateGender(Animal::getGender(animal));
        }
        static void dump(const Animal& animal){
            cout << "=============================================" << endl
                 << setw(10) << left << quote(animal) << setw(15) << "kingdom" << setw(20) << Animal::getKingdom(animal) << endl
                 << setw(10) << left << quote(animal) << setw(15) << "gender" << setw(20) << genderAsString(Animal::getGender(animal)) << endl;
        }
};

extern string info(const Animal& animal);


#endif //EE205_ANIMAL_FARM_ANIMAL_H
