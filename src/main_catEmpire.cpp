///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         Animal Farm - EE 205 - Spr 2023
//
///
/// @file    main_catEmpire.cpp
/// @author  Evan Rau <evanrau@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "Animal/Cat/Cat.h"
#include "Utility/Name.h"
#include "Container/SingleLinkedList.h"


#define ALL_MY_ANIMALS 100 ///< Number of animals
#define ANIMAL_SAMPLE_SIZE 10 ///< Number of animals to sample

using namespace std;

///Main function that proves code is up to specification
int main() {
    cout << "catEmpire" << endl ;
    SingleLinkedList myAnimals ;
    for( int i = 0 ; i < ALL_MY_ANIMALS ; i++ ) {
        myAnimals.add( Cat::getRandomAnimal() );
    }
    for( int i = 0 ; i < ANIMAL_SAMPLE_SIZE ; i++ ) {
        Node* aRandomNode = myAnimals.getRandomNode();
        Cat* aRandomAnimal = dynamic_cast<Cat*>( aRandomNode );
        cout << aRandomAnimal->info() << endl;
    }
}