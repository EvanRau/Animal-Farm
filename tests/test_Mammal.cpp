///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         Animal Farm - EE 205 - Spr 2023
//
/// @file    test_LinkedList.cpp
/// @author  Evan Rau <evanrau@hawaii.edu>
//////////////////////////////////////////////////////////////////////////////

#define BOOST_TEST_DYN_LINK

#include <boost/test/tools/output_test_stream.hpp>
#include <boost/test/unit_test.hpp>

#include "../src/Animal/Mammal/Mammal.h"


using namespace std;

BOOST_AUTO_TEST_SUITE( test_Mammal )


BOOST_AUTO_TEST_CASE( test_getColor ) {
        Mammal bingus("Rainbow");
        BOOST_CHECK_EQUAL(bingus.getColor(), "Rainbow" );
}
BOOST_AUTO_TEST_CASE( test_setColor ) {
        Mammal bingus("Rainbow");
        bingus.setColor("Colorless"); BOOST_CHECK_EQUAL(bingus.getColor(), "Colorless" );
        BOOST_CHECK_THROW(bingus.setColor(""), invalid_argument);
}
BOOST_AUTO_TEST_CASE( test_getClassification ) {
        Mammal bingus("Rainbow");
        BOOST_CHECK_EQUAL(bingus.getClassification(), "Mammalia" );
}



BOOST_AUTO_TEST_SUITE_END()