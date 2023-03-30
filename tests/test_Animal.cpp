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
        Animal test1;
        BOOST_CHECK_EQUAL(test1.validate(), true); //Constructor with no arguments
        Animal test2(Gender::MALE);
        BOOST_CHECK_EQUAL(test2.validate(), true); //Constructor with argument
    }
    BOOST_AUTO_TEST_CASE( test_dump ) { //@todo research method to test dump; checking visually for now
        Animal test1;
        test1.dump();
        Animal test2(Gender::MALE);
        test2.dump();
}


BOOST_AUTO_TEST_SUITE_END()