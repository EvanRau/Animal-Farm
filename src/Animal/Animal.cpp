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
#include "Cat/Cat.h"
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
    return !getKingdom().empty() && !info().empty() && validateWeight(weight) && Node::validate();
}

///Prints out data on given animal
void Animal::dump() const noexcept{
    PRINT_HEADING_FOR_DUMP()
    Node::dump() ;
    FORMAT_LINE_FOR_DUMP( "Animal", "kingdom" ) << getKingdom() << endl ;
    FORMAT_LINE_FOR_DUMP( "Animal", "weight" ) << weight << endl ;
}


std::string Animal::info() const noexcept {
    // Put the address of this object into a string
    std::stringstream stringStream;
    stringStream << this;
    const std::string theAddressOfThis = stringStream.str();
    string infoString {};
    // Print the class
    infoString += "The ";
    infoString += boost::core::demangled_name( BOOST_CORE_TYPEID( *this ));
    infoString += " named ";
    infoString += getName();
    infoString += " at ";
    infoString += theAddressOfThis;
    infoString += " says ";
    infoString += speak();
    return infoString;
}

///Returns a random animal; currently returns only cats
Animal* Animal::getRandomAnimal() {
    Name catColors( "./data/catColors.txt" );
    return new Cat(catColors.getNextName(), newRandomGender(), Cat::names.getNextName());
}


