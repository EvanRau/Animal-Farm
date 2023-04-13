///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         Animal Farm - EE 205 - Spr 2023
//
///
/// @file    catWrangler.cpp
/// @author  Evan Rau <evanrau@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////

#include "Animal/Mammal/Mammal.h"
#include "Container/SingleLinkedList.h"

int main(){
    SingleLinkedList linkedList;
    string catColors[10]= ['Brown', "Black", "Ginger", ]

    linkedList.dump();
    linkedList.sort();
    if(linkedList.validate() && linkedList.isSorted()) {
        linkedList.dump();
    } else {
        std::cout<<"List Invalid."<<std::endl;
    }
}