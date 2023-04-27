///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         Animal Farm - EE 205 - Spr 2023
//
///
/// @file    main_catInfinitum.cpp
/// @author  Evan Rau <evanrau@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////

#include "Container/SingleLinkedList.h"
#include "Animal/Animal.h"
#include "Animal/Cat/Cat.h"
#include "Utility/Gender.h"


///Test function for implementation of spec
int main(){
    SingleLinkedList linkedList;
    for(int i=0; i<10; i++) {
        linkedList.add( new Cat( Cat::names.getNextName())) ;
    }
    if(linkedList.validate()) {
        linkedList.dump();
    } else {
        std::cout<<"List Invalid."<<std::endl;
    }
}
