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

#include "../src/Animal/Animal.h"
#include "../src/Container/SingleLinkedList.h"


using namespace std;

BOOST_AUTO_TEST_SUITE( test_LinkedList )


    BOOST_AUTO_TEST_CASE( test_isEmpty ) {
        SingleLinkedList testList;
        BOOST_CHECK_EQUAL(testList.isEmpty(), true );
    }
    BOOST_AUTO_TEST_CASE( test_size ) {
        SingleLinkedList testList;
        Node* testNode = new Animal();
        testList.add(testNode); BOOST_CHECK_EQUAL(testList.size(), 1 );
    }
    BOOST_AUTO_TEST_CASE( test_removeAll ) {
        SingleLinkedList testList;
        Node* testNode = new Animal();
        testList.add(testNode);
        testList.removeAll(); BOOST_CHECK_EQUAL(testList.isEmpty(), true );
    }


BOOST_AUTO_TEST_SUITE_END()