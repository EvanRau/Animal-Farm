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
#include "Utility/Gender.h"


int main(){
    SingleLinkedList linkedList;
    for(int i=0; i<10; i++){
        Gender tempGender;
        if(i%2==0){
            tempGender = Gender::MALE;
        }
        else{
            tempGender = Gender::FEMALE;
        }
        Node* newNode = new Animal(tempGender);
        linkedList.add(newNode);
    }
    if(linkedList.validate()) {
        linkedList.dump();
    }
    else{
        std::cout<<"List Invalid."<<std::endl;
    }

}
