///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         Animal Farm - EE 205 - Spr 2023
//
///
/// @file    Mammal.h
/// @author  Evan Rau <evanrau@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////

#ifndef EE205_ANIMAL_FARM_MAMMAL_H
#define EE205_ANIMAL_FARM_MAMMAL_H

#include <string>
#include "../../config.h"
#include "../Animal.h"


using namespace std;

class Mammal : public Animal{
private:
    string color;
public:
    Mammal() : color("Unknown Color"){
    }
    Mammal(const string newColor) : color(newColor){
    }
    string getColor() const noexcept{
        return color;
    };
    void setColor(const string_view newColor){
        if(empty(newColor)){
            throw invalid_argument(PROGRAM_NAME ": newColor can't be empty...");
        }
        color = newColor;
    }
    static string getClassification() noexcept{
        return "Mammalia";
    }
    virtual void dump() const noexcept{
        Animal::dump();
        FORMAT_LINE_FOR_DUMP( "Mammal", "classification" ) << getClassification() << endl ;
        FORMAT_LINE_FOR_DUMP( "Mammal", "color" ) << getColor() << endl ;
    }
    virtual bool validate() const noexcept{
        if(empty(getClassification()) || empty(getColor())){
            return false;
        }
        return Animal::validate();
    }
};

#endif //EE205_ANIMAL_FARM_MAMMAL_H
