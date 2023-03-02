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

#include "../src/Legacy/ArrayDB.h"
#include "../src/Legacy/Cat.h"


using namespace std;
Cat cat = {"Bingus", MALE, 50.01, 0101010, true};



BOOST_AUTO_TEST_SUITE( test_Legacy_epicCats )

    BOOST_AUTO_TEST_CASE( test_validateCat ) {
    cat.name = "";    BOOST_CHECK_EQUAL(validateCat(cat), false);
    cat.name = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA";  BOOST_CHECK_EQUAL(validateCat(cat), false);
    cat.name = "Bingus"; // Reset Name Check
    cat.weightInPounds = 0; BOOST_CHECK_EQUAL(validateCat(cat), false);
    cat.weightInPounds = 200; BOOST_CHECK_EQUAL(validateCat(cat), false);
    cat.weightInPounds = 50.01; //Reset Weight
    }

    BOOST_AUTO_TEST_CASE( test_addCat ) {
    for(int i = 0; i <= MAX_CATS; i++){
        catDB[i] = cat;
    }
    BOOST_CHECK_EQUAL(addCat(cat), false);
    }

    BOOST_AUTO_TEST_CASE( test_validateCatDB ) {
        for(int i = 0; i <= MAX_CATS; i++){
            catDB[i] = cat;
        }
        BOOST_CHECK_EQUAL(validateCatDB(), false);
        initDB();
        catDB[0] = cat;
        catDB[0].name = ""; BOOST_CHECK_EQUAL(validateCatDB(), false);
        catDB[0].name = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA";  BOOST_CHECK_EQUAL(validateCatDB(), false);
        catDB[0].name = "Bingus"; // Reset Name Check
        catDB[0].weightInPounds = -1; BOOST_CHECK_EQUAL(validateCatDB(), false);
        catDB[0].weightInPounds = 200; BOOST_CHECK_EQUAL(validateCatDB(), false);
        catDB[0].weightInPounds = 50.01; //Reset Weight
    }
BOOST_AUTO_TEST_SUITE_END()
