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

const char* genders[] = {"UNKNOWN_GENDER", "MALE", "FEMALE"};

///Generates a random gender
///@returns one of the applicable genders
Gender newRandomGender(){
    const int srandSeeder = rand();  //Seeds rand in even function is rapidly called
    srand(time(nullptr)-srandSeeder);
    const int randGender = rand() % TOTAL_GENDERS; //Generates random number among those assigned to genders
    return static_cast<Gender>(randGender); //Returns random number as enum
}

///Tests that given gender is valid
///@returns false if gender is invalid
bool validateGender(Gender gender){
    const int genderNum = static_cast<int>(gender); //Takes numeric value for enum and applies to int
    return genderNum >= 0 && genderNum < TOTAL_GENDERS; //Returns true if numeric value is within range of known genders
}

///Converts enum gender to its string name
///@returns gender as string
std::string genderAsString(Gender gender){
    const int genderNum = static_cast<int>(gender);
    return genders[genderNum];
}