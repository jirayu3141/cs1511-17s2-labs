// Read a line of input.
// Modified by
//  Seokhyun Phil Jung (z3459079)
//  Kevin Luxa (z5074984)
//  Ahnaf Aaqif (z5125723)
// Modified on 2017-08-25
// Tutor: Stephen Leung (fri09-kora)

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_LENGTH 64

void readLine (int bufferLen, char *buffer);

int main (int argc, char *argv[]) {
    // Declare a buffer.  In this case, we're declaring and using a
    // 64-byte buffer, but this could be any length you like, and in
    // our tests you will be required to handle arrays of any length.
    char buffer[BUFFER_LENGTH] = {0};

    // Read in a line...
    readLine (BUFFER_LENGTH, buffer);

    // ... and print it out.  The `%s` format code prints a string.
    printf ("<%s>\n", buffer);

    return EXIT_SUCCESS;
}

// Reads a line of input into `buffer`, excluding the newline;
// ensures that `buffer` is a null-terminated string.
void readLine (int bufferLen, char *buffer) {
    int i = 0;
    char c = getchar();
    while (i < bufferLen - 1 && c != '\n') {
        buffer[i] = c;
        c = getchar();
        i++;
    }
}
