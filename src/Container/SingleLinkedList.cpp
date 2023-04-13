///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         Animal Farm - EE 205 - Spr 2023
//
///
/// @file    SingleLinkedList.cpp
/// @author  Evan Rau <evanrau@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////

#include "SingleLinkedList.h"


///Checks if a given list contains any nodes
///@returns true if no nodes are linked
bool SingleLinkedList::isEmpty() const noexcept{
    return headNode == nullptr;
}

///Gets the total size of a linked list
///@returns the number of nodes in the list
size_t SingleLinkedList::size() const noexcept{
    Node* tracker = headNode;
    size_t nodeCount = 0;
    while (tracker != nullptr){
        nodeCount++;
        tracker = tracker->next;
    }
    return nodeCount;
}

///Checks if a given node is in a linked list
///@returns true if the list contains the given node
bool SingleLinkedList::isIn(const Node* aNode) const{
    Node* tracker = headNode;
    while(tracker != nullptr){
        if(tracker->next == aNode){
            return true;
        }
        tracker = tracker->next;
    }
    return false;
}

///Adds a new node to the linked list
void SingleLinkedList::add(Node* newNode){
    if(newNode == nullptr){
        throw invalid_argument("Node to be added is NULL");
    }
    if(!newNode->validate()){
        throw domain_error("Invalid Node");
    }
    if(isIn(newNode)){
        throw logic_error("Node already in list");
    }
    if(validate()) {
        newNode->next = headNode;
        headNode = newNode;
    }
    else{
        throw runtime_error("Linked list Invalid");
    }
    if(!validate()){
        throw runtime_error("Linked list Damaged after node inclusion");
    }
}

///Empties all nodes from the list
void SingleLinkedList::removeAll(){
    while(headNode != nullptr) {
        Node *tempNode = headNode;
        headNode = headNode->next;
        free(tempNode);
    }
}

///Unlinks a node from a linked list; node is preserved for future use elsewhere
void SingleLinkedList::unlinkNode(Node* deadNode) {
    if(headNode == deadNode){
        headNode = deadNode->next;
        return;
    }
    Node* tempNode = headNode;
    while(tempNode->next != deadNode){
        tempNode = tempNode->next;
    }
    tempNode->next = deadNode->next;
}

///Gets a random node from within the list
Node* SingleLinkedList::getRandomNode() const noexcept{
    size_t const listSize = size();
    if(listSize==0){
        return nullptr;
    }
    size_t const nodePlace = rand() % listSize;
    Node* randNode = headNode;
    for(size_t i = 0; i < nodePlace; i++){
        randNode = randNode->next;
    }
    return randNode;
}

///Dumps all data from nodes within the list
void SingleLinkedList::dump() const noexcept{
    Node* curNode = headNode;
    PRINT_HEADING_FOR_DUMP()
    Container::dump();
    FORMAT_LINE_FOR_DUMP("SingleLinkedList", "headNode") << headNode << std::endl;
    PRINT_HEADING_FOR_DUMP()
    while(curNode != nullptr){
        curNode->dump();
        curNode = curNode->next;
    }
}

///Validates the linked list and the nodes within it
///@returns true if the list is valid
bool SingleLinkedList::validate() const noexcept{
    size_t const nodeSize = size();
    Node* tracker = headNode;
    if((nodeSize==0&&isEmpty()&&headNode==nullptr) || (nodeSize>0&&!isEmpty()&&headNode!=nullptr)){
        while(tracker != nullptr) {
            if(!tracker->validate()){
                return false;
            }
            tracker = tracker->next;
        }
    }
    else{
        return false;
    }
    return true;
}

///Sorts linked list from smallest address to largest
void SingleLinkedList::sort(){
    SingleLinkedList newList;
    while(headNode!=nullptr){
        Node* temp = headNode;
        Node* minNode = temp;
        Node* nodeA = temp;
        Node* nodeB = temp->next;
        for(size_t i = 0; i<(size()-1); i++) {
           if (Node::compareByAddress(nodeA, nodeB)) {
               minNode = nodeA;
           }
           nodeA = nodeA->next;
           nodeB = nodeB->next;
        }
        unlinkNode(minNode);
        newList.add(minNode);

    }
    headNode = newList.headNode;
}

///Checks whether a given linked list is sorted by its addresses from smallest to largest
///@returns true of the list is properly sorted
bool SingleLinkedList::isSorted(){
    Node* tracker = headNode;
    while(tracker->next != nullptr){
        if(!Node::compareByAddress(tracker, tracker->next)){
            return false;
        }
        tracker = tracker->next;
    }
    return true;
}


