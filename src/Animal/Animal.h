///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         Animal Farm - EE 205 - Spr 2023
//
///
/// @file    Animal.h
/// @author  Evan Rau <evanrau@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////

#ifndef EE205_ANIMAL_FARM_ANIMAL_H
#define EE205_ANIMAL_FARM_ANIMAL_H



#include "../Container/Node.h"
#include <iomanip>
#include <string>


using namespace std;


///Properties of an animal. Includes its gender and its kingdom
class Animal : public Node {
    protected:

        float weight;
    public:
        Animal() : weight(0.1) {
        }
        ///Constructs an Animal with a given weight
        Animal(float weight) : weight(weight) {
        }

        [[nodiscard]] string_view getKingdom() const noexcept;

        [[nodiscard]] bool validate() const noexcept;

        void dump() const noexcept;

        [[nodiscard]] string info() const noexcept;

        static bool validateWeight(float weight){
            return weight > 0;
        }


};




#endif //EE205_ANIMAL_FARM_ANIMAL_H
