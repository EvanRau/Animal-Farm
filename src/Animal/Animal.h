///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         Animal Farm - EE 205 - Spr 2023
//
/// A child class of nodes that references animals of all kinds
///
/// @file    Animal.h
/// @author  Evan Rau <evanrau@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////

#ifndef EE205_ANIMAL_FARM_ANIMAL_H
#define EE205_ANIMAL_FARM_ANIMAL_H



#include "../Container/Node.h"
#include "../Utility/Name.h"
#include <iomanip>
#include <string>


using namespace std;


///Properties of an animal. Includes its gender and its kingdom
class Animal : public Node {
    protected:
        ///The given weight of an animal
        float weight;
    public:
        Animal() : weight(2 + (((float) rand()) / (float) RAND_MAX) * (99 - 2)) {
        }
        ///Constructs an Animal with a given weight
        Animal(float weight) : weight(weight) {
        }

        [[nodiscard]] string_view getKingdom() const noexcept;

        [[nodiscard]] bool validate() const noexcept;

        void dump() const noexcept;

        ///Checks that the weight is not <= 0
        ///@returns false if the weight is <= 0
        static bool validateWeight(float weight){
            return weight > 0;
        }

        /// Ask the Animal to say something
        virtual std::string_view speak() const noexcept = 0;
        ///Gets the Animal's Name
        virtual string getName() const noexcept = 0;

        /// Print a unique one-line string representing this object
        ///
        /// #### Sample Output
        ///
        /// The Node at 0x7ffff375ba90
        ///
        virtual std::string info() const noexcept;

    static Animal* getRandomAnimal();
};




#endif //EE205_ANIMAL_FARM_ANIMAL_H
