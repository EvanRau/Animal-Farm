///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         Animal Farm - EE 205 - Spr 2023
//
/// @file    test_Legacy_epicCats.cpp
/// @author  Evan Rau <evanrau@hawaii.edu>
//////////////////////////////////////////////////////////////////////////////

#define BOOST_TEST_DYN_LINK

#include <boost/test/tools/output_test_stream.hpp>
#include <boost/test/unit_test.hpp>

#include "../src/Utility/Gender.h"
#include "../src/Animal/Animal.h"

using namespace std;

BOOST_AUTO_TEST_SUITE( test_Animal )
        Animal testAnimal;
    BOOST_AUTO_TEST_CASE( test_validate ) {
        BOOST_CHECK_EQUAL(validate(testAnimal), true); //Declared animal with no modifications must be true by default
        testAnimal.gender = static_cast<Gender>(10);    BOOST_CHECK_EQUAL(validate(testAnimal), false); //Invalid gender
        testAnimal.gender = Gender::FEMALE;
        testAnimal.Kingdom = "";  BOOST_CHECK_EQUAL(validate(testAnimal), false); //Invalid Kingdom
        testAnimal.Kingdom = "Animalia";
        testAnimal.info = "";   BOOST_CHECK_EQUAL(validate(testAnimal), false); //Invalid Info
        testAnimal.info = "An animal";

    }
}