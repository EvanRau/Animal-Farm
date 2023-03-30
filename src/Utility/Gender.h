///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         Animal Farm - EE 205 - Spr 2023
//
///
/// @file    Gender.h
/// @author  Evan Rau <evanrau@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////

#ifndef EE205_ANIMAL_FARM_GENDER_H
#define EE205_ANIMAL_FARM_GENDER_H

///Total number of values in gender enum; change this value along with additions to Gender
#define TOTAL_GENDERS 3

/// #Gender that includes but a few of the known cat genders
enum class Gender {
    UNKNOWN_GENDER=0,
    MALE=1,
    FEMALE=2,
};

extern Gender newRandomGender();

extern bool validateGender(Gender gender);


#endif //EE205_ANIMAL_FARM_GENDER_H
