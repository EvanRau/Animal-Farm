///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         Animal Farm - EE 205 - Spr 2023
//
///
/// @file    Cat.cpp
/// @author  Evan Rau <evanrau@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////
#include "Cat.h"


bool validateCat(Cat Cat){
    if (sizeof(Cat.Name) <= 0 || sizeof(Cat.Name) > MAX_CAT_NAME){ //Invalid Name
        return false;
    }
    if (Cat.Gender != MALE && Cat.Gender != FEMALE && Cat.Gender != UNKNOWN){ //Invalid Gender
        return false;
    }

    if (Cat.weightInPounds <= 0 || Cat.weightInPounds >= 100){ //Invalid weightInPounds
        return false;
    }
    if (sizeof(Cat.chipID) == 0){ //Invalid chipID
        return false;
    }
    if (Cat.isFixed != false && Cat.isFixed != true){ //Invalid isFixed
        return false;
    }
    return true; //Valid Cat
}

struct Cat generateCat(){

}