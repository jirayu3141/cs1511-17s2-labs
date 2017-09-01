// Displaying arrays as text
// Modified by
//  Seokhyun Phil Jung (z3459079)
//  Kevin Luxa (z5074984)
//  Ahnaf Aaqif (z5125723)
// Modified on 2017-08-25
// Tutor: Stephen Leung (fri09-kora)

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define ENOUGH_SPACE 100

void showTerminatedLetters(char *letters);

int main(int argc, char *argv[]) {

    char lettersA[14] = {0};
    lettersA[0] = 72;
    lettersA[1] = 101;
    lettersA[2] = 108;
    lettersA[3] = 108;
    lettersA[4] = 111;
    lettersA[5] = 44;
    lettersA[6] = 32;
    lettersA[7] = 119;
    lettersA[8] = 111;
    lettersA[9] = 114;
    lettersA[10] = 108;
    lettersA[11] = 100;
    lettersA[12] = 33;
    lettersA[13] = 0;
    showTerminatedLetters(lettersA);

    putchar('\n');

    char lettersB[14] = {
        84,  101, 115, 116, 32,
        109, 101, 115, 115, 97,
        103, 101, 46, 0
    };
    showTerminatedLetters(lettersB);

    putchar('\n');

    char lettersC[12] = {
        's', 'a', 'm', 'p', 'l', 'e',
        ' ', 't', 'e', 'x', 't', '\0'
    };
    showTerminatedLetters(lettersC);

    putchar('\n');

    char lettersD[ENOUGH_SPACE] = "a string";
    showTerminatedLetters(lettersD);

    putchar('\n');

    return EXIT_SUCCESS;
}

// Shows a null-terminated array of letters.
void showTerminatedLetters(char *letters) {
    int i = 0;
    while (letters[i] != '\0') {
        putchar (letters[i]);
        i++;
    }
}
