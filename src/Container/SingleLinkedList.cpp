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
    return count;
}

bool isIn(const Node* aNode){
    Node* tracker = headNode;
    while(tracker != nullptr){
        if(tracker->next == aNode){
            return true;
        }
        tracker = tracker->next;
    }
    return false;
}

void add(Node* newNode){
    newNode->next = headNode;
    headNode = newNode;
}

void removeAll(){
    while(headNode != nullptr) {
        Node *tempNode = headNode;
        headNode = headNode->next;
        free(tempNode);
    }
}

void getRandomNode(){
    size_t const listSize = size();
    size_t const nodePlace = rand() % listSize;
    Node* randNode = headNode;
    for(size_t i = 0; i < nodePlace; i++){
        randNode = randNode->next;
    }
    randNode->dump();
}

void dump(){
    Node* curNode = headNode;
    while(curNode != nullptr){
        curNode->dump();
        curNode = curNode->next;
    }
}

bool validate(){
    size_t const nodeSize = size();
    size_t chainSize = 0;
    Node* tracker = headNode;
    while(tracker != nullptr){
        chainSize++;
        tracker = tracker->next;
    }
    return nodeSize==chainSize;
}