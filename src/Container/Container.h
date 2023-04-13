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
protected:
    ///stores number of items in given container
    size_t count = 0;
public:
    ///Generates a default container
    Container(){
    }
    ///Abstract function for container
    ///@see SingleLinkedList.cpp for documentation
    virtual bool isEmpty() const noexcept = 0;
    ///Abstract function for container
    ///@see SingleLinkedList.cpp for documentation
    virtual size_t size() const noexcept = 0;
    ///Abstract function for container
    ///@see SingleLinkedList.cpp for documentation
    virtual bool isIn(const Node *aNode) const = 0;
    ///Abstract function for container
    ///@see SingleLinkedList.cpp for documentation
    virtual void add(Node *newNode) = 0;
    ///Abstract function for container
    ///@see SingleLinkedList.cpp for documentation
    virtual void removeAll() = 0;
    ///Abstract function for container
    ///@see SingleLinkedList.cpp for documentation
    virtual Node* getRandomNode() const noexcept = 0;
    ///Dumps the information for the given Container
    virtual void dump() const noexcept{
        FORMAT_LINE_FOR_DUMP( "Object", "class" ) << boost::core::demangled_name( BOOST_CORE_TYPEID( *this )) << std::endl ;
        FORMAT_LINE_FOR_DUMP( "Object", "this" ) << this << std::endl ;
        FORMAT_LINE_FOR_DUMP( "container", "count" ) << size() << std::endl;
    }
    /// This will print something unique for each Container
    ///
    /// #### Sample Output
    /**@verbatim
    The Container at 0x7ffff375ba90
    @endverbatim */
    virtual std::string info() const noexcept{
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
    };
    ///Abstract function for container
    ///@see SingleLinkedList.cpp for documentation
    virtual bool validate() const noexcept = 0;
};


#endif //EE205_ANIMAL_FARM_CONTAINER_H
