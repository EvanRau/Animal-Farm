///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         Animal Farm - EE 205 - Spr 2023
//
///
/// @file    Cat.h
/// @author  Evan Rau <evanrau@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////

#ifndef EE205_ANIMAL_FARM_CAT_H
#define EE205_ANIMAL_FARM_CAT_H


#include "../../Utility/Name.h"
#include "../Animal.h"
#include "../Mammal/Mammal.h"

using namespace std;

class Cat : public Mammal {
protected:
    ///Name of a given cat
    string name;
public:
    ///List of potential cat names
    static Name names;
    ///Default constructor for a Cat
    explicit Cat( string newName ) ;
    ///Cat constructor given a color and gender
    Cat(const string &newColor, const Gender newGender, string newName) : Mammal(newColor, newGender), name(std::move(newName)){
    }
    string_view speak() const noexcept{
        return "Meow";
    }
    ///Gets the name of a given cat
    ///@returns the name of a given cat
    string getName() const noexcept{
        return name;
    }
    void setName(string newName);

    virtual bool validate() const noexcept;

    virtual void dump() const noexcept{
        Mammal::dump();
        FORMAT_LINE_FOR_DUMP( "Cat", "name" ) << name << endl ;
    }

    static Cat* getRandomAnimal();
};


#endif //EE205_ANIMAL_FARM_CAT_H
