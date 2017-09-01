// convert a string to lowercase
// modified by
//  seokhyun phil jung (z3459079)
//  kevin luxa (z5074984)
//  ahnaf aaqif (z5125723)
// modified on 2017-08-25
// tutor: stephen leung (fri09-kora)

#include <stdio.h>
#include <stdlib.h>

void stringToLower (char *buffer);

int main (int argc, char *argv[]) {
    /// THIS WON'T WORK!
    ///
    /// `str` only points to a string literal, which is stored in a
    /// read only section of the program.  If you attempt to modify
    /// it, your program will crash with a memory error (usually,
    /// SIGSEGV, the infamous "segmentation fault").
    //
    // char *str = "Hello!"
    // stringToLower (str)

    char str[] = "Seventeen...  SEVENTEEN, I SAY!";
    stringToLower (str);
    printf ("%s\n", str);

    return EXIT_SUCCESS;
}

// takes a string in `buffer`, and lowercases it.
void stringToLower (char *buffer) {
    int i = 0;
    while (buffer[i] != '\0') {
        if (buffer[i] >= 'A' && buffer[i] <= 'Z') {
            buffer[i] += 32;
        }
        i++;
    }
}
