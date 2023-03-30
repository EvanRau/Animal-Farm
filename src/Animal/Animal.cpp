///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         Animal Farm - EE 205 - Spr 2023
//
///
/// @file    Animal.cpp
/// @author  Evan Rau <evanrau@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////

#include "Animal.h"
#include <iostream>
using namespace std;


///Gets the kingdom of a given animal
///@returns animal.kingdom (Is always Animalia)

string info(){
    return "An animal";
}





void dump(const Animal& animal){
    cout << "===================================================\n";
    cout << quote(animal)
}
