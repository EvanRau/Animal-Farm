///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         Animal Farm - EE 205 - Spr 2023
//
/// Tests linked list functionality by creating linked list of cats
///
/// @file    main_catInfinitum.cpp
/// @author  Evan Rau <evanrau@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////

#include "Container/SingleLinkedList.h"
#include "Animal/Animal.h"


///Test function for implementation of spec
int main(){
    SingleLinkedList linkedList;
    for(int i=0; i<10; i++) {
        linkedList.add(Animal::getRandomAnimal()) ;
    }
    if(linkedList.validate()) {
        linkedList.dump();
    } else {
        std::cout<<"List Invalid."<<std::endl;
    }
}
