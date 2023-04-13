///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         Animal Farm - EE 205 - Spr 2023
//
///
/// @file    catWrangler.cpp
/// @author  Evan Rau <evanrau@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////

#include "Animal/Mammal/Mammal.h"

int main(){
    Mammal bingus("Rainbow");
    bingus.setGender(Gender::MALE);
    bingus.dump();
}