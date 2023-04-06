///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         Animal Farm - EE 205 - Spr 2023
//
///
/// @file    node.h
/// @author  Evan Rau <evanrau@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////

#ifndef EE205_ANIMAL_FARM_NODE_H
#define EE205_ANIMAL_FARM_NODE_H


#include "../config.h"
#include <boost/core/typeinfo.hpp> // For typeinfo()
#include <iostream>
#include <string>

using namespace std;

///Properties of a node
class Node{
    ///Linked lists need access to pointed nodes
    friend class SingleLinkedList;
private:
    ///Node that is pointed to by current node
    Node* next;

public:

    ///Constructs a node that points to nullptr
    Node() : next(nullptr){
    }
    ///Deconstructs a node
    virtual ~Node()= default;
    virtual void reset(){
        next = nullptr;
    }
    ///Dumps the contents of the node
    virtual void dump() const{
        FORMAT_LINE_FOR_DUMP( "Object", "class" ) << boost::core::demangled_name( BOOST_CORE_TYPEID( *this )) << std::endl ;
        FORMAT_LINE_FOR_DUMP( "Object", "this" ) << this << std::endl ;
        FORMAT_LINE_FOR_DUMP( "Node", "next" ) << this << std::endl;
    }
    ///Validates the node
    virtual bool validate() const{
        return true;
    }

};

#endif //EE205_ANIMAL_FARM_NODE_H
