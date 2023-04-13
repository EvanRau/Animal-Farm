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
protected:
    ///The head node of a linked list; initialized as nullptr
    Node* headNode = nullptr;
public:
    virtual bool isEmpty() const noexcept;

    virtual size_t size() const noexcept;

    virtual bool isIn(const Node *aNode) const;

    virtual void add(Node *newNode);

    virtual void removeAll();

    virtual void deleteNode(int nodePos);

    virtual Node* getRandomNode() const noexcept;

    virtual void dump() const noexcept;

    virtual bool validate() const noexcept;

    virtual void sort();

    virtual bool isSorted();
};


#endif //EE205_ANIMAL_FARM_SINGLELINKEDLIST_H
