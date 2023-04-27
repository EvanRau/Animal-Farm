///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         Animal Farm - EE 205 - Spr 2023
//
/// Comprehensive test of general cat-generating functions
///
/// @file    test_Cat.cpp
/// @author  Evan Rau <evanrau@hawaii.edu>
//////////////////////////////////////////////////////////////////////////////

#define BOOST_TEST_DYN_LINK

#include <boost/test/tools/output_test_stream.hpp>
#include <boost/test/unit_test.hpp>

#include "../src/Animal/Animal.h"
#include "../src/Animal/Cat/Cat.h"

using namespace std;

BOOST_AUTO_TEST_SUITE( test_Cat )


    BOOST_AUTO_TEST_CASE( test_validateWeight ) {
        BOOST_CHECK_EQUAL( Animal::validateWeight( -0.1 ), false ) ;
        BOOST_CHECK_EQUAL( Animal::validateWeight( +0.1 ), true ) ;

    }
    BOOST_AUTO_TEST_CASE( test_validate ) {
        Name catColors( "./data/catColors.txt" );
        Cat testCat("Bingus");
        BOOST_CHECK_EQUAL( testCat.validate(), true ) ;
        for(int i=0; i<100; i++){
            Cat testCat(catColors.getNextName(), newRandomGender(), Cat::names.getNextName());
            BOOST_CHECK_EQUAL( testCat.validate(), true ) ;
        }

    }
    BOOST_AUTO_TEST_CASE( test_getName ) {
        Cat testCat("Bingus");
        BOOST_CHECK_EQUAL( testCat.validate(), true ) ;
        BOOST_CHECK_EQUAL( testCat.getName(), "Bingus" ) ;


    }


BOOST_AUTO_TEST_SUITE_END()