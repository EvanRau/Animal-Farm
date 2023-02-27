///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         Animal Farm - EE 205 - Spr 2023
//
/// @file    ArrayDB.h
/// @author  Evan Rau <evanrau@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////
#include "cat.h"
/// Maximum number of cats allowed in catDB
#define MAX_CATS 100


#ifndef EE205_ANIMAL_FARM_ARRAYDB_H
#define EE205_ANIMAL_FARM_ARRAYDB_H

extern Cat catDB[MAX_CATS];

void initDB();

extern bool addCat(Cat Cat);

extern bool validateCatDB();

extern int findNextBlank();


#endif //EE205_ANIMAL_FARM_ARRAYDB_H
