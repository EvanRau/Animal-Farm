///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         Animal Farm - EE 205 - Spr 2023
//
/// Tests sorting function by creating linked list of cats and sorting the nodes
///
/// @file    main_catWrangler.cpp
/// @author  Evan Rau <evanrau@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////

#include "Animal/Cat/Cat.h"
#include "Container/SingleLinkedList.h"


///Test function for implementation of spec
int main(){
    SingleLinkedList linkedList;
    for(int i=0; i<10; i++) {
        linkedList.add(Animal::getRandomAnimal()) ;
    }
    linkedList.dump();
    cout<<endl<<endl<<endl;
    linkedList.sort();
    if(linkedList.validate() && linkedList.isSorted()) {
        linkedList.dump();
    } else {
        std::cout<<"List Invalid."<<std::endl;
    }
}