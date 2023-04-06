///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         Animal Farm - EE 205 - Spr 2023
//
///
/// @file    SingleLinkedList.cpp
/// @author  Evan Rau <evanrau@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////

#include "SingleLinkedList.h"

Node* headNode = nullptr;

bool isEmpty(){
    return headNode == nullptr;
}

size_t size(){
    Node* tracker = headNode;
    size_t count = 0;
    while (tracker != nullptr){
        count++;
        tracker = tracker->next;
    }
}