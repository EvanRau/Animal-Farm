///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         Animal Farm - EE 205 - Spr 2023
//
///
/// @file    Cat.cpp
/// @author  Evan Rau <evanrau@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////

#include "Cat.h"

/// Data file that holds a list of cat names
#define CAT_NAMES_FILE "./data/catNames.txt"
/// This is static, so the list will be available for any and all Cat instances
/// to use.
///
/// #### Internal
/// The scope of this **member** variable is `public:`. This is to facilitate
/// testing. It's difficult to friend some of the Boost test fixtures.
Name Cat::names( CAT_NAMES_FILE );

/// This constructor is declared to be `explicit`, so you can't do silly
/// things like `Cat newCat = "Bella";` ... instead, you need to construct
/// a Cat properly like `Cat newCat( "Bella" );`
///
/// @param newName Must be a valid name per Name::validateName
Cat::Cat( const std::string newName )
        : Mammal( "Unknown color", Gender::UNKNOWN_GENDER ) { // Delegating constructor
            Cat::setName( newName ) ;
    Cat::validate();
}

/// @param newName The Cat's new name. It must be valid per Name::validateName.
void Cat::setName( const string newName ) {
    if( !Name::validateName((newName) )) {
        /// @throws invalid_argument If the Cat's name is invalid
        throw invalid_argument( "The cat's name [" + string(newName) + "] is invalid" );
    }
    name = newName;
}

bool Cat::validate() const noexcept {
    return Mammal::validate() && Name::validateName(name);
}

