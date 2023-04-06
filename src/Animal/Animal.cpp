///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         Animal Farm - EE 205 - Spr 2023
//
///
/// @file    Animal.cpp
/// @author  Evan Rau <evanrau@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////

#include "Animal.h"
#include "../config.h"
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

///Gives kingdom of animal
///@returns Only possible kingdom (Animalia)
string_view Animal::getKingdom() const noexcept{
    return "Animalia";
}

///Checks that given animal is valid
///@returns true if animal is valid, false if not
bool Animal::validate() const noexcept{

    return !getKingdom().empty() && !info().empty() && validateGender(gender) && Node::validate();
}

///Prints out data on given animal
void Animal::dump() const noexcept{
    PRINT_HEADING_FOR_DUMP()
    Node::dump() ;
    FORMAT_LINE_FOR_DUMP( "Animal", "kingdom" ) << getKingdom() << endl ;
    FORMAT_LINE_FOR_DUMP( "Animal", "gender" ) << getGender() << endl ;
}

///Provides information on animal
///@returns "An animal" for now
string Animal::info() const noexcept{
    return "An animal";
}