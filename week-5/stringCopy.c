// Copy a String
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

void stringCopy (char *destination, char *source, int destSize);

int main (int argc, char *argv[]) {
    // Declare a buffer.  In this case, we're declaring and using a
    // 64-byte buffer, but this could be any length you like, and in
    // our tests you will be required to handle arrays of any length.
    char buffer [BUFFER_LENGTH] = {0};
    char buffer2[BUFFER_LENGTH] = {0};
    char buffer3[BUFFER_LENGTH] = {0};
    
    // Copy a string into the buffer ...
    stringCopy (buffer, "Seventeen bytes.\n", BUFFER_LENGTH);
    
    // ... and print it out.  The `%s` format code prints a string.
    printf ("<%s>\n", buffer);
    
    
    stringCopy (buffer2, "Hello, World!", BUFFER_LENGTH);
    printf ("<%s>\n", buffer2);
    
    
    stringCopy (buffer3, "a\nb\nc\nd\ne\nf\ng", BUFFER_LENGTH);
    printf ("<%s>\n", buffer3);
    
    return EXIT_SUCCESS;
}

// Takes a string in `source`, and copies it to `destination`, which
// is `destSize` elements in size; only copies up to `destSize` bytes.
// Ensures the `destination` array is null-terminated.
void stringCopy (char *destination, char *source, int destSize) {
    int i = 0;
    while (i < destSize - 1 && source[i] != '\0') {
        destination[i] = source[i];
        i++;
    }
}
