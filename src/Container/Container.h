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

///Properties of a container
class Container {
private:
    ///stores number of items in given container
    size_t count;
public:
    ///Generates a default container
    Container(){
    }
    ///Abstract function for container
    ///@see SingleLinkedList.cpp for documentation
    virtual bool isEmpty() = 0;
    ///Abstract function for container
    ///@see SingleLinkedList.cpp for documentation
    virtual size_t size() = 0;
    ///Abstract function for container
    ///@see SingleLinkedList.cpp for documentation
    virtual bool isIn(const Node *aNode) = 0;
    ///Abstract function for container
    ///@see SingleLinkedList.cpp for documentation
    virtual void add(Node *newNode) = 0;
    ///Abstract function for container
    ///@see SingleLinkedList.cpp for documentation
    virtual void removeAll() = 0;
    ///Abstract function for container
    ///@see SingleLinkedList.cpp for documentation
    virtual void getRandomNode() = 0;
    ///Abstract function for container
    ///@see SingleLinkedList.cpp for documentation
    virtual void dump() = 0;
    ///Abstract function for container
    ///@see SingleLinkedList.cpp for documentation
    virtual bool validate() = 0;
};




#endif //EE205_ANIMAL_FARM_CONTAINER_H
