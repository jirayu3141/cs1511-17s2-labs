// Perform the ROT13 algorithm on a string
// See: https://en.wikipedia.org/wiki/ROT13
// Modified by
//  Seokhyun Phil Jung (z3459079)
//  Kevin Luxa (z5074984)
//  Ahnaf Aaqif (z5125723)
// Modified on 2017-09-01
// Tutor: Stephen Leung (fri09-kora)

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE (!FALSE)
#define MAX_LENGTH 256

// Add your own #defines here
#define ROT13 13

void rotateThirteen (char *string);
char rotateOne (char c);
int stringLength (char *string);
int stringsEqual (char *stringA, char *stringB);

// Add your own function prototypes here

int main (int argc, char *argv[]) {
    // Example tests
    char testA[MAX_LENGTH] = "Hello, world!";
    rotateThirteen (testA);
    assert (stringsEqual ("Uryyb, jbeyq!", testA));

    char testB[MAX_LENGTH] = "abcdefghijklmnopqrstuvwxyz";
    rotateThirteen (testB);
    assert (stringsEqual ("nopqrstuvwxyzabcdefghijklm", testB));

    char testC[MAX_LENGTH] = "The quick brown fox jumped over the lazy dog.";
    rotateThirteen (testC);
    assert (stringsEqual ("Gur dhvpx oebja sbk whzcrq bire gur ynml qbt.", testC));

    // Add your own tests here

    char testD[MAX_LENGTH] = "It's treason, then.";
    rotateThirteen (testD);
    assert (stringsEqual ("Vg'f gernfba, gura.", testD));

    char testE[MAX_LENGTH] = "I don't like sand. It's coarse, and rough, and irritating, and it gets everywhere.";
    rotateThirteen (testE);
    assert (stringsEqual ("V qba'g yvxr fnaq. Vg'f pbnefr, naq ebhtu, naq veevgngvat, naq vg trgf rireljurer.", testE));

    char testF[MAX_LENGTH] = "A, B, C, D, E, F, G. H, I, J, K, L M N O P. Q, R, S, T, U, V. W, X, Y and Z. Now I know my ABCs, next time won't you sing with me?";
    rotateThirteen (testF);
    assert (stringsEqual ("N, O, P, Q, R, S, T. U, V, W, X, Y Z A B C. D, E, F, G, H, I. J, K, L naq M. Abj V xabj zl NOPf, arkg gvzr jba'g lbh fvat jvgu zr?", testF));

    printf ("All tests passed. You are awesome!\n");

    return EXIT_SUCCESS;
}

// This function "rotates" all letters in a string
// by 13 by changing a to n, b to o...and z to m
void rotateThirteen (char *string) {
    int length = stringLength (string);
    int i = 0;
    while (i < length) {
        int j = 0;
        while (j < ROT13) {
            string[i] = rotateOne (string[i]);
            j++;
        }
        i++;
    }
}

// This function "rotates" a letter by one
// by changing a to b, b to c...and z to a
char rotateOne (char c) {
    if (c >= 'a' && c <= 'z') {
        c += 1;
        if (c > 'z') {
            c -= 26;
        }
    }
    if (c >= 'A' && c <= 'Z') {
        c += 1;
        if (c > 'Z') {
            c -= 26;
        }
    }
    return c;
}

// This function finds the length of a string
int stringLength (char *string) {
    int i = 0;
    while (string[i] != '\0') {
        i++;
    }
    return i;
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
