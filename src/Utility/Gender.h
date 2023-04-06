///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         Animal Farm - EE 205 - Spr 2023
//
///
/// @file    Gender.h
/// @author  Evan Rau <evanrau@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////

#ifndef EE205_ANIMAL_FARM_GENDER_H
#define EE205_ANIMAL_FARM_GENDER_H

///Total number of values in gender enum; change this value along with additions to Gender
#include "../config.h"
#include <stdexcept>
#include <string>



#define TOTAL_GENDERS 3



/// #Gender that includes but a few of the known cat genders
enum class Gender {
    UNKNOWN_GENDER=0,
    MALE=1,
    FEMALE=2,
};

extern Gender newRandomGender();

extern bool validateGender(Gender gender);

extern std::string genderAsString(Gender gender);

/// Output Gender as a formatted string
///
/// @param lhs_stream The output stream to write to (usually `cout`).
/// `lhs` stands for Left Hand Side and means the left side
/// of the `<<` operator.
/// @param rhs_Gender The Gender to output.
/// `rhs` stands for Right Hand Side and means the right
/// side of the `<<` operator.
/// @return `Unknown gender`, `Female` or `Male`.
inline std::ostream& operator<<( std::ostream& lhs_stream, const Gender& rhs_Gender )
{
    switch( rhs_Gender ) {
        case Gender::UNKNOWN_GENDER:
            lhs_stream << "Unknown gender";
            break;
        case Gender::MALE:
            lhs_stream << "Male";
            break;
        case Gender::FEMALE:
            lhs_stream << "Female";
            break;
        default:
            /// @throw out_of_range If the enum is not mapped to a string.
            throw std::out_of_range( PROGRAM_NAME ": Gender not mapped to a string" );
    }
    return lhs_stream;
}

#endif //EE205_ANIMAL_FARM_GENDER_H
