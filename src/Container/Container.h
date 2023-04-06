///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         Animal Farm - EE 205 - Spr 2023
//
///
/// @file    Container.h
/// @author  Evan Rau <evanrau@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////

#ifndef EE205_ANIMAL_FARM_CONTAINER_H
#define EE205_ANIMAL_FARM_CONTAINER_H

#include "Node.h"

class Container {
private:
    size_t count;
public:
    virtual bool isEmpty() = 0;

    virtual size_t size() = 0;

    virtual bool isIn(const Node *aNode) = 0;

    virtual void add(Node *newNode) = 0;

    virtual void removeAll() = 0;

    virtual void getRandomNode() = 0;

    virtual void dump() = 0;

    virtual void validate() = 0;
};

#endif //EE205_ANIMAL_FARM_CONTAINER_H
