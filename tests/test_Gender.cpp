///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         Animal Farm - EE 205 - Spr 2023
//
/// Comprehensive test of gender functions
///
/// @file    test_Legacy_epicCats.cpp
/// @author  Evan Rau <evanrau@hawaii.edu>
//////////////////////////////////////////////////////////////////////////////

#define BOOST_TEST_DYN_LINK

#include <boost/test/tools/output_test_stream.hpp>
#include <boost/test/unit_test.hpp>

#include "../src/Utility/Gender.h"


using namespace std;

BOOST_AUTO_TEST_SUITE( test_Gender )

    BOOST_AUTO_TEST_CASE( test_validateGender ) {
        Gender testGender = newRandomGender();   BOOST_CHECK_EQUAL(validateGender(testGender), true);
        testGender = static_cast<Gender>(0);    BOOST_CHECK_EQUAL(validateGender(testGender), true);
        testGender = static_cast<Gender>(1);    BOOST_CHECK_EQUAL(validateGender(testGender), true);
        testGender = static_cast<Gender>(2);    BOOST_CHECK_EQUAL(validateGender(testGender), true);
        testGender = static_cast<Gender>(10);    BOOST_CHECK_EQUAL(validateGender(testGender), false);
    }
BOOST_AUTO_TEST_SUITE_END()