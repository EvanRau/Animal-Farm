///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         Animal Farm - EE 205 - Spr 2023
//
///
/// @file    Animal.cpp
/// @author  Evan Rau <evanrau@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////

#include "Animal.h"
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

///Gives kingdom of animal
///@returns Only possible kingdom (Animalia)
string_view Animal::getKingdom(){
    return "Animalia";
}

///Checks that given animal is valid
///@returns true if animal is valid, false if not
bool Animal::validate(){
    return !getKingdom().empty() && !info().empty() && validateGender(gender);
}

///Prints out data on given animal
void Animal::dump(){
    cout << "========================================" << endl
         << setw(10) << left << "Animal" << setw(15) << "kingdom" << setw(20) << Animal::getKingdom() << endl
         << setw(10) << left << "Animal" << setw(15) << "gender" << setw(20) << genderAsString(gender) << endl;
}

///Provides information on animal
///@returns "An animal" for now
string_view Animal::info(){
    return "An animal";
}