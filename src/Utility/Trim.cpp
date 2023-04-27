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
#include <string.h>


/// @see https://en.cppreference.com/w/c/string/byte/isspace
extern char* trim_left( char* inString ) {
    int i = 0;
    while (isspace(inString[i])) {
        i++;
    }
    for (int j = 0; j < (int)strlen(inString); j++) {
        inString[j] = inString[j+i];
    }
    return inString;
}


/// @see https://en.cppreference.com/w/c/string/byte/isspace
extern char* trim_right( char* inString ) {
    int string_length = (int)strlen(inString);
    int i = string_length - 1;
    while (i >= 0 && isspace(inString[i])) {
        i--;
    }
    inString[i + 1] = '\0';
    return inString;

}


/// This trim function does not modify the interior of the string
///
/// @see https://en.cppreference.com/w/c/string/byte/isspace
extern char* trim_edges( char* inString ) {
    inString = trim_right(trim_left(inString));
    return inString;
}


/// This function does the following:
///
///    - Trim the leading whitespace
///    - Trim trailing whitespace
///    - Replace consecutive whitespace characters inside the string with
///      a single `" "`

extern char* trim( char* inString ) {

    inString = trim_edges(inString);
    int length = (int)strlen(inString);
    char strCopy[length];
    int i = 0;
    bool whitespace_state = false;

    for (int k = 0; k < length; k++) { ///NOLINT
        if (isspace(inString[k]) && !whitespace_state) { ///NOLINT
            strCopy[i] = ' ';
            i++;
            whitespace_state = true;
        } else if (!isspace(inString[k])){
            strCopy[i] = inString[k];
            i++;
            whitespace_state = false;
        }
    }
    for (int k = 0; k < (int)strlen(strCopy); k++) { ///NOLINT
        inString[k] = strCopy[k]; ///NOLINT
    }
    inString[i] = '\0';
    return inString;
}