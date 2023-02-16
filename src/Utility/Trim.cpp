///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         ee205_animal_farm - EE 205 - Spr 2023
//
/// General string-trimming functions
///
/// There are *so many ways* to implement string trimming...
///
///   - Maximize clarity and understandability
///   - Maximize efficiency
///
/// This implementation is designed to try to balance both requirements.
///
/// @file    Trim.cpp
/// @author  Evan Rau <evanrau@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////


#include "Trim.h"
#include <ctype.h>

/// @see https://en.cppreference.com/w/c/string/byte/isspace
char* trim_left( char inString[] ) {

    while(isspace((unsigned char)*inString)) {
        inString++;
    }

   return inString;
}


/// @see https://en.cppreference.com/w/c/string/byte/isspace
char* trim_right( char inString[] ) {
   return inString;
}


/// This trim function does not modify the interior of the string
///
/// @see https://en.cppreference.com/w/c/string/byte/isspace
char* trim_edges( char inString[] ) {
   return inString;
}


/// This function does the following:
///
///    - Trim the leading whitespace
///    - Trim trailing whitespace
///    - Replace consecutive whitespace characters inside the string with
///      a single `" "`
char* trim( char inString[] ) {
   return inString;
}
