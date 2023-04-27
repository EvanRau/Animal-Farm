///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         Animal Farm - EE 205 - Spr 2023
//
///
/// @file    config.h
/// @author  Evan Rau <evanrau@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////

#ifndef EE205_ANIMAL_FARM_CONFIG_H
#define EE205_ANIMAL_FARM_CONFIG_H
#include <iomanip> // For setfill()
#include <random>  // For random_device & mt19937
using namespace std;

///A grammatically correct title for the program
#define PROGRAM_TITLE "Animal Farm"

///A short title for the program (for console messages)
#define PROGRAM_NAME "animalFarm"


/// Format a header for dump function
#define PRINT_HEADING_FOR_DUMP() \
cout << setfill('=') << setw(80) << "" <<endl;

/// Format a line for dumping the members of a class to the console.
/// Setup the fields for printing (space pad, left justify, etc.)
#define FORMAT_LINE_FOR_DUMP( className, member ) \
 std::cout << std::setfill( ' ' ) /* Space pad */ \
 << std::left /* Left justify */ \
 << std::boolalpha /* Print `true` or `false` for `bool`s */ \
 << std::setw(20) << (className) \
 << std::setw(20) << (member) \
 << std::setw(40) /* (data) */

/// Establish the RNG used by Animal Farm
///
/// The C++ standard library has some great built-in random number features.
/// @see https://en.cppreference.com/w/cpp/header/random
///
/// If you want the same pseudorandom sequence each time you run the program,
/// use `std::mt19937`.
///
/// If you want a truly unique random sequence each time you run the program,
/// use `std::random_device`.
 #define ANIMAL_FARM_RNG std::random_device
//#define ANIMAL_FARM_RNG std::mt19937

#endif //EE205_ANIMAL_FARM_CONFIG_H
