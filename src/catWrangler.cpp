///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         Animal Farm - EE 205 - Spr 2023
//
///
/// @file    catWrangler.cpp
/// @author  Evan Rau <evanrau@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////

#include "Animal/Cat/Cat.h"
#include "Animal/Mammal/Mammal.h"
#include "Container/SingleLinkedList.h"

///Test function for implementation of spec
int main(){
    SingleLinkedList linkedList;
    string catColors[]= {"Color1", "Color2", "Color3", "Color 4", "Color 5", "Color 6", "Color 7", "Color 8", "Color 9", "Color 10" };
    for(int i=0; i<10; i++) {
        linkedList.add( new Cat(Cat::names.getNextName() )) ;
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