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
#include "../Utility/Gender.h"
#include <iomanip>
#include <string>


using namespace std;


///Properties of an animal. Includes its gender and its kingdom
class Animal : public Node {
    protected:
        ///Gender of animal; Unknown by default
        Gender gender;
        float weight;
    public:
        Animal() : gender(Gender::UNKNOWN_GENDER) , weight(0.1) {
        }
        ///Constructs an Animal with unknown gender
        Animal(float weight) : gender(Gender::UNKNOWN_GENDER) , weight(weight) {
        }
        ///Constructs an Animal with a known gender
        explicit Animal(Gender gender, float weight) : gender(gender) , weight(weight) {
        }
        [[nodiscard]] string_view getKingdom() const noexcept;

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

        [[nodiscard]] bool validate() const noexcept;

        void dump() const noexcept;

        [[nodiscard]] string info() const noexcept;

        static bool validateWeight(float weight){
            return weight > 0;
        }


};




#endif //EE205_ANIMAL_FARM_ANIMAL_H
