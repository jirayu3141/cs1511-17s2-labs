// Functions and types used to extract x, y, z values from a string
// containing a URL of the form:
// "http://almondbread.cse.unsw.edu.au/mandelbrot/2/z/x/y/tile.bmp"
// Modified by
//  Kevin Luxa (z5074984)
//  Ahnaf Aaqif (z5125723)
//  Seokhyun Phil Jung (z3459079)
// Modified on 2017-09-08
// Tutor: Stephen Leung (fri09-kora)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "extract.h"

#define SLASHES_BEFORE_TRI 5    // No. of slashes before the triordinate
#define MAX_LENGTH 18  // Max allowed length of a numString (incl. '\0')
#define TRUE (1 == 1)
#define FALSE !(TRUE)
#define POSITIVE  1
#define NEGATIVE -1

// Function Prototypes
int locateTriordinate (char *url);
int getString (char *string, char *numString, char sentinel, int i);
void stringReverse (char *string);
int getLength (char *string);
void swap (char *string, int i, int j);
double sumSciNotation (char *numString, int exponentSign);
int charToInt (char c);
double powerOfTen (int exponent);
int hasDecPoint (char *string);

int main (int argc, char *argv[]) {

    char *url = "http://almondbread.cse.unsw.edu.au/mandelbrot/2/5/3.14/-0.141/tile.bmp";
    
    triordinate dat = extract (url);
    
    printf ("dat is (%f, %f, %d)\n", dat.x, dat.y, dat.z);
    
    return EXIT_SUCCESS;
}

// Extracts x, y, z values from a string containing a URL of the form
// "http://almondbread.cse.unsw.edu.au/mandelbrot/2/z/x/y/tile.bmp"
triordinate extract (char *url) {
    char zString[MAX_LENGTH] = {0};
    char xString[MAX_LENGTH] = {0};
    char yString[MAX_LENGTH] = {0};
    int i = locateTriordinate (url);
    i = getString (url, zString, '/', i);
    i = getString (url, xString, '/', i);
    i = getString (url, yString, '/', i);
    long   zDec = myAtoL (zString);
    double xDec = myAtoD (xString);
    double yDec = myAtoD (yString);
    triordinate zxyTriordinate = {
        .z = zDec,
        .x = xDec,
        .y = yDec
    };
    return zxyTriordinate;
}

// This function takes a numeric string and returns it as a long
long myAtoL (char *numString) {
    stringReverse (numString); // Reverses the numeric string
    long result = sumSciNotation (numString, POSITIVE);
    return result;
}

// This function takes a numeric string and returns it as a double
double myAtoD (char *numString) {
    char  integerPart[MAX_LENGTH] = {0};
    char fractionPart[MAX_LENGTH] = {0};
    double result = 0;
    int i = 0;
    
    // Deals with negative numbers
    int sign = POSITIVE;
    if (numString[i] == '-') {
        sign = NEGATIVE;
        i++;
    }
    
    // Deals with the presence/absence of decimal points
    if (hasDecPoint (numString)) {
        i = getString (numString,  integerPart,  '.', i);
        i = getString (numString, fractionPart, '\0', i);
        // If there is no decimal point, then it is just
        // an integer
    } else {
        i = getString (numString,  integerPart, '\0', i);
    }
    
    stringReverse (integerPart); // Reverses integerPart
    result += sumSciNotation (integerPart,  POSITIVE);
    result += sumSciNotation (fractionPart, NEGATIVE);
    result *= sign; // Corrects the sign
    return result;
}

// This function locates the beginning of the triordinate by counting
// the number of slashes and returns the index of the first ordinate
int locateTriordinate (char *url) {
    int i = 0;
    int numSlashes = 0;
    while (numSlashes < SLASHES_BEFORE_TRI) {
        if (url[i] == '/') {
            numSlashes++;
        }
        i++;
    }
    return i;
}

// Reads characters from a string (starting at string[i]) into numString
// until a sentinel and returns the index of the character coming after
// the sentinel.
int getString (char *string, char *numString, char sentinel, int i) {
    int j = 0;
    while (string[i] != sentinel) {
        numString[j] = string[i];
        j++;
        i++;
    }
    i++;
    return i;
}

// Reverses the integer part of a string so that its length does
// not have to be determined when passing it into sumSciNotation
void stringReverse (char *string) {
    int length = getLength (string);
    int iMax = length - 1;
    int i = 0;
    while (i <= iMax / 2 && length != 0) {
        swap (string, i, iMax - i);
        i++;
    }
}

// Finds the length of a string - called by stringReverse
int getLength (char *string) {
    int i = 0;
    while (string[i] != '\0') {
        i++;
    }
    return i;
}

// Swaps two elements of a string - called by stringReverse
void swap (char *string, int i, int j) {
    char temp = string[i];
    string[i] = string[j];
    string[j] = temp;
}

// Takes the string of digits and converts it to a number
// by multiplying each digit by successive powers of ten.
// exponentSign is POSITIVE when converting the integer
// part, and NEGATIVE when converting the fraction part
// E.g., "456" becomes 4 * 10^0 + 5 * 10^1 + 6 * 10^2
// or it becomes 4 * 10^-1 + 5 * 10^-2 + 6 * 10^-3
double sumSciNotation (char *numString, int exponentSign) {
    double sum = 0;
    int i = 0, exponent = 0;
    if (exponentSign == NEGATIVE) {
        exponent = -1;
    }
    while (numString[i] != '\0') {
        int digit = charToInt (numString[i]);
        sum += digit * powerOfTen (exponent);
        exponent += exponentSign;
        i++;
    }
    return sum;
}

// Takes in a digit character and returns it as an integer
int charToInt (char c) {
    return c - '0';
}

// This function takes an exponent and returns 10^exponent
double powerOfTen (int exponent) {
    double result = 1;  // Default is 1 (if exponent is 0)
    int i = 0;
    // If exponent > 0, repeatedly multiplies result by 10
    if (exponent > 0) {
        while (i < exponent) {
            result *= 10;
            i++;
        }
    }
    // If exponent > 0, repeatedly divides result by 10
    if (exponent < 0) {
        exponent = -exponent;
        while (i < exponent) {
            result /= 10;
            i++;
        }
    }
    return result;
}

// Determines if a string contains a decimal point
int hasDecPoint (char *string) {
    int result = FALSE,  i = 0;
    while (string[i] != '\0') {
        if (string[i] == '.') {
            result = TRUE;
        }
        i++;
    }
    return result;
}
