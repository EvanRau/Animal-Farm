///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         Animal Farm - EE 205 - Spr 2023
//
///
/// @file    ArrayDB.h
/// @author  Evan Rau <evanrau@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////
#include "cat.h"
#define MAX_CATS 100

#ifndef EE205_ANIMAL_FARM_ARRAYDB_H
#define EE205_ANIMAL_FARM_ARRAYDB_H

extern void initDB();

extern bool addCat(Cat Cat, struct Cat* catDb);

extern bool validateCatDB(Cat* catDb);

extern int findNextBlank(Cat* catDb);


#endif //EE205_ANIMAL_FARM_ARRAYDB_H
