///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         Animal Farm - EE 205 - Spr 2023
//
///
/// @file    Gender.cpp
/// @author  Evan Rau <evanrau@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////

#include "Gender.h"
#include <cstdlib>
#include <ctime>

///Generates a random gender
///@returns one of the applicable genders
Gender newRandomGender(){
    const int srandSeeder = rand();  //Seeds rand in even function is rapidly called
    srand(time(nullptr)-srandSeeder);
    const int randGender = rand() % TOTAL_GENDERS; //Generates random number among those assigned to genders
    return static_cast<Gender>(randGender); //Returns random number as enum
}