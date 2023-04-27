///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         Animal Farm - EE 205 - Spr 2023
//
///
/// @file    main_catEmpire.cpp
/// @author  Evan Rau <evanrau@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "Utility/Name.h"

using namespace std;

int main(){
    Name testName("./data/testNames1.txt");
    cout<<testName.getNextName()<<endl;
}