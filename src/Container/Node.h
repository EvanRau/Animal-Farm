///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         Animal Farm - EE 205 - Spr 2023
//
///
/// @file    Node.h
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
    ///resets what the current node is pointing to
    virtual void reset(){
        next = nullptr;
    }
    ///Dumps the contents of the node
    virtual void dump() const{
        FORMAT_LINE_FOR_DUMP( "Object", "class" ) << boost::core::demangled_name( BOOST_CORE_TYPEID( *this )) << std::endl ;
        FORMAT_LINE_FOR_DUMP( "Object", "this" ) << this << std::endl ;
        FORMAT_LINE_FOR_DUMP( "Node", "next" ) << this->next << std::endl;
    }
    ///Validates the node
    virtual bool validate() const{
        return true;
    }

    /// This will print something unique for each Node
    ///
    /// #### Sample Output
    /**@verbatim
    The Node at 0x7ffff375ba90
    @endverbatim */
    virtual string info() const{
        // Put the address of this object into a string
        std::stringstream stringStream;
        stringStream << this;
        std::string theAddressOfThis = stringStream.str();
        std::string infoString {};
        // Print the class
        infoString += "The ";
        infoString += boost::core::demangled_name( BOOST_CORE_TYPEID( *this ));
        infoString += " at ";
        infoString += theAddressOfThis;
        return infoString;
    }

};

#endif //EE205_ANIMAL_FARM_NODE_H
