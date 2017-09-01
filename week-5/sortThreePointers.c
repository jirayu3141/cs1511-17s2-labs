// Sort three numbers using pointers to the variables
// Modified by
//  Seokhyun Phil Jung (z3459079)
//  Kevin Luxa (z5074984)
//  Ahnaf Aaqif (z5125723)
// Modified on 2017-08-25
// Tutor: Stephen Leung (fri09-kora)

#include <stdio.h>
#include <stdlib.h>

void swap (int *a, int *b);
void sortThree (int *a, int *b, int *c);

int  main (int argc, char *argv[]) {
    printf ("Enter three numbers: ");
    int a, b, c;
    scanf ("%d %d %d", &a, &b, &c);

    sortThree (&a, &b, &c);

    printf ("The numbers, in order, are: %d %d %d\n", a, b, c);

    return EXIT_SUCCESS;
}

// Swap the values in two variables given their pointers
void swap (int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Sort the values in three variables, given their pointers
void sortThree (int *a, int *b, int *c) {
    if (*a >= *b) {
        swap (a, b);
    }
    if (*b >= *c) {
        swap (b, c);
    }
    if (*a >= *b) {
        swap (a, b);
    }
}
