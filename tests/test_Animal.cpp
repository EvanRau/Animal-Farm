///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         Animal Farm - EE 205 - Spr 2023
//
/// @file    test_Animal.cpp
/// @author  Evan Rau <evanrau@hawaii.edu>
//////////////////////////////////////////////////////////////////////////////

#define BOOST_TEST_DYN_LINK

#include <boost/test/tools/output_test_stream.hpp>
#include <boost/test/unit_test.hpp>

#include "../src/Animal/Animal.h"

using namespace std;

BOOST_AUTO_TEST_SUITE( test_Animal )


    BOOST_AUTO_TEST_CASE( test_validate ) {
        Animal test1(10);
        BOOST_CHECK_EQUAL(test1.validate(), true); //Constructor with no arguments
    }

    BOOST_AUTO_TEST_CASE( test_validateWeight ) {
        BOOST_CHECK_EQUAL( Animal::validateWeight( -0.1 ), false ) ;
        BOOST_CHECK_EQUAL( Animal::validateWeight( +0.1 ), true ) ;

}


BOOST_AUTO_TEST_SUITE_END()