// String Equality
// Created by
//  Seokhyun Phil Jung (z3459079)
//  Kevin Luxa (z5074984)
//  Ahnaf Aaqif (z5125723)
// Created on 2017-08-25
// Stephen Leung (fri09-kora)

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define TRUE (1 == 1)
#define FALSE (! TRUE)

int stringsEqual (char *stringA, char *stringB);

int main (int argc, char *argv[]) {
    // Some simple assert-based tests.
    // You probably want to write some more.
    assert (stringsEqual ("", "") == TRUE);
    assert (stringsEqual (" ", "") == FALSE);
    assert (stringsEqual ("", " ") == FALSE);
    assert (stringsEqual (" ", " ") == TRUE);
    assert (stringsEqual ("\n", "\n") == TRUE);
    assert (stringsEqual ("This is 17 bytes.", "") == FALSE);
    assert (stringsEqual ("", "This is 17 bytes.") == FALSE);
    assert (stringsEqual ("This is 17 bytes.", "This is 17 bytes.") == TRUE);
    assert (stringsEqual ("Here are 18 bytes!", "This is 17 bytes.") == FALSE);
    assert (stringsEqual ("This is 17 bytes.", "This is 99 bytes.") == FALSE);
    assert (stringsEqual ("abracadabra", "abracadabra alakazam ") == FALSE);
    assert (stringsEqual ("abcdefg\0hijklmnop", "abcdefg\0xyz") == TRUE);
    printf ("All tests passed.  You are awesome!\n");

    return EXIT_SUCCESS;
}

// Takes two strings, and if they are the same,
// returns TRUE, or FALSE otherwise.
int stringsEqual (char *stringA, char *stringB) {
    int i = 0;
    int equal = FALSE;
    while (equal == FALSE && stringA[i] == stringB[i]) {
        if (stringA[i] == '\0') {
            equal = TRUE;
        } else {
            i++;
        }
    }
    return equal;
}
