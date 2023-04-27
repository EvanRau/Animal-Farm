///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         Animal Farm - EE 205 - Spr 2023
//
/// A child class of animal that refers to mammals
///
/// @file    Mammal.h
/// @author  Evan Rau <evanrau@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////

#ifndef EE205_ANIMAL_FARM_MAMMAL_H
#define EE205_ANIMAL_FARM_MAMMAL_H

#include "../../Utility/Gender.h"
#include "../../config.h"
#include "../Animal.h"
#include <string>


using namespace std;

///Properties of a Mammal
class Mammal : public Animal{
private:
    ///The color of a mammal. Unknown by default
    string color = "Unknown Color";
    ///Gender of animal; Unknown by default
    Gender gender = Gender::UNKNOWN_GENDER;
public:
    ///Constructs a mammal with a known color
    Mammal(const string &newColor, const Gender newGender) :color(newColor), gender(newGender){
    }
    ///Deconstricts a mammal
    virtual ~Mammal(){
    }

    ///Returns a mammal's color
    ///@returns the mammal's color
    string getColor() const noexcept{
        return color;
    };
    ///Sets the color of a mammal
    void setColor(const string_view newColor){
        if(empty(newColor)){
            throw invalid_argument(PROGRAM_NAME ": newColor can't be empty...");
        }
        color = newColor;
    }
    ///Pulls gender of given animal
    ///@returns gender of animal
    [[nodiscard]] Gender getGender() const noexcept{
        return gender;
    }
    ///Sets gender of animal with unknown gender
    ///Throws exception if gender is not unknown
    void setGender(const Gender setGender){
        if(this->gender != Gender::UNKNOWN_GENDER) {
            throw runtime_error("Gender already set");
        }
        this->gender = setGender;
    }
    ///Gets the classification of a mammal
    static string getClassification() noexcept{
        return "Mammalia";
    }
    ///Dumps all the data of a mammal
    virtual void dump() const noexcept{
        Animal::dump();
        FORMAT_LINE_FOR_DUMP( "Mammal", "classification" ) << getClassification() << endl ;
        FORMAT_LINE_FOR_DUMP( "Mammal", "color" ) << getColor() << endl ;
        FORMAT_LINE_FOR_DUMP( "Mammal", "gender" ) << getGender() << endl ;
    }
    ///Checks that given mammal is valid
    ///@returns true if mammal is valid, false if not
    virtual bool validate() const noexcept{
        if(empty(getClassification()) || empty(getColor())){
            return false;
        }
        return Animal::validate();
    }

};

#endif //EE205_ANIMAL_FARM_MAMMAL_H
