///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         Animal Farm - EE 205 - Spr 2023
//
/// @file    test_LinkedList.cpp
/// @author  Evan Rau <evanrau@hawaii.edu>
//////////////////////////////////////////////////////////////////////////////

#define BOOST_TEST_DYN_LINK

//#include <boost/test/tools/output_test_stream.hpp>
#include <boost/test/unit_test.hpp>

#include "../src/Animal/Animal.h"
#include "../src/Animal/Mammal/Mammal.h"
#include "../src/Container/SingleLinkedList.h"

using namespace std;

BOOST_AUTO_TEST_SUITE( test_LinkedList )


    BOOST_AUTO_TEST_CASE( test_isEmpty ) {
        SingleLinkedList testList;
        BOOST_CHECK_EQUAL(testList.isEmpty(), true );
        testList.add(new Mammal("A color"));
        BOOST_CHECK_EQUAL(testList.isEmpty(), false );
    }
    BOOST_AUTO_TEST_CASE( test_size ) {
        SingleLinkedList testList;
        for(int i=1; i < 100;i++) {
            for (int j = 1; j <= i; j++) {
                testList.add(new Animal(newRandomGender()));
            }
            BOOST_CHECK_EQUAL(testList.validate(), true);
            BOOST_CHECK_EQUAL(testList.size(), i);
            testList.removeAll();
        }
    }
    BOOST_AUTO_TEST_CASE( test_removeAll ) {
        SingleLinkedList testList;
        for(int i=1; i < 100;i++) {
            for (int j = 1; j <= i; j++) {
                testList.add(new Animal(newRandomGender()));
            }
            testList.removeAll();
            BOOST_CHECK_EQUAL(testList.isEmpty(), true);
        }
    }
    BOOST_AUTO_TEST_CASE( test_randomNode ) {
        SingleLinkedList testList;  BOOST_CHECK_EQUAL(testList.getRandomNode(), nullptr);
    }
    BOOST_AUTO_TEST_CASE( test_isIn ) {
        SingleLinkedList testList;
        Node* bingus = new Animal();
        testList.add(bingus);
        Node* testNode = new Animal();
        testList.add(testNode); BOOST_CHECK_EQUAL(testList.isIn(bingus), true);
        Node* fakeNode = new Animal();  BOOST_CHECK_EQUAL(testList.isIn(fakeNode), false);
    }
    BOOST_AUTO_TEST_CASE( test_unlinkNode ) {
        SingleLinkedList testList;
        for(int i=1; i < 100;i++) {
            for (int j = 1; j <= i; j++) {
                testList.add(new Animal(newRandomGender()));
            }
            BOOST_CHECK_EQUAL(testList.validate(), true);
            BOOST_CHECK_EQUAL(testList.size(), i);
            for (int j = 1; j <= i; j++) {
                testList.unlinkNode(testList.getRandomNode());
            }
            BOOST_CHECK_EQUAL(testList.validate(), true);
            BOOST_CHECK_EQUAL(testList.isEmpty(), true);
        }
}
    BOOST_AUTO_TEST_CASE( test_isSorted ) {
        SingleLinkedList testList;
        for(int i=1; i < 100;i++) {
            for (int j = 1; j <=i; j++) {
                testList.add(new Mammal("A color"));
            }
            testList.sort();
            if( !testList.isSorted() ) {
                testList.dump() ;
            }
            BOOST_REQUIRE_EQUAL(testList.isSorted(), true);
            testList.removeAll();
            BOOST_CHECK_EQUAL(testList.isEmpty(), true);
        }
}



BOOST_AUTO_TEST_SUITE_END()