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

void SingleLinkedList::deleteNode(int nodePos) {
    if((size_t) nodePos > size()){
        throw domain_error("Node to delete does not exist");
    }
    //Deleting headNode
    if(nodePos == 0){
        Node* tempNode = headNode;
        headNode = headNode->next;
        free(tempNode);
    }
    //Deleting node pointed to by head node
    else if(nodePos == 1){
        Node* prevNode = headNode;
        Node* tempNode = headNode->next;
        prevNode->next = tempNode->next;
        free(tempNode);

    }
    //Deleting node pointed to later in sequence
    else{
        Node* prevNode = headNode;
        Node* tempNode = headNode->next;
        for(int i = 1; i < nodePos; i++){
            prevNode = prevNode->next;
            tempNode = tempNode->next;
        }
        prevNode->next = tempNode->next;
        free(tempNode);
    }
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

void SingleLinkedList::sort(){
    SingleLinkedList sortedList;
    Node* trackerNode = headNode;
    Node* minNode;
    while(trackerNode != nullptr){
        trackerNode = headNode;
        int nodePos = 0;
        int minNodePos = 0;
        while(trackerNode->next != nullptr){
            minNode = headNode;
            if(Node::compareByAddress(minNode, trackerNode->next)){
                minNode = trackerNode->next;
                nodePos = minNodePos;
            }
            trackerNode=trackerNode->next;
            minNodePos++;
        }
        sortedList.add((minNode));
        deleteNode(nodePos);
    }

}

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


