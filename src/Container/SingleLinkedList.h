///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         Animal Farm - EE 205 - Spr 2023
//
///
/// @file    SingleLinkedList.h
/// @author  Evan Rau <evanrau@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////

#ifndef EE205_ANIMAL_FARM_SINGLELINKEDLIST_H
#define EE205_ANIMAL_FARM_SINGLELINKEDLIST_H


#include "Container.h"

///Properties of a linked list; inherits functions from Container
class SingleLinkedList : public Container{
    ///The head node of a linked list; initialized as nullptr
    Node* headNode = nullptr;
public:
    virtual bool isEmpty();

    virtual size_t size();

    virtual bool isIn(const Node *aNode);

    virtual void add(Node *newNode);

    virtual void removeAll();

    virtual void getRandomNode();

    virtual void dump();

    virtual bool validate();
};


#endif //EE205_ANIMAL_FARM_SINGLELINKEDLIST_H
