// Experiment with exploring off the end of an array.
// Note: Don't forget to compile with gcc, NOT dcc!
// Modified by
//  Kevin Luxa (z5074984)
//  Ahnaf Aaqif (z5125723)
//  Seokhyun Phil Jung (z3459079)
// Modified on 2017-09-08
// Tutor: Stephen Leung (fri09-kora)

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {

    int canaryA = 42;
    int testArray[10] = {0,1,2,3,4,5,6,7,8,9};
    int canaryB = 99;

    // Note: Modify the code below to include a while loop,
    // so you can repeatedly test values without having to
    // run the program multiple times.
    
    printf("canaryA is at %#x\n", &canaryA);
    printf("canaryB is at %#x\n", &canaryB);
    
    int index;
    while (1 == 1) {
        printf ("Enter an array index between 0 and 9\n");
        scanf ("%d", &index);
        printf ("testArray[%d] = %d.\n", index, testArray[index]);
        printf ("testArray[%d] is stored in %p.\n",index, &testArray[index]);
    }
    
    return EXIT_SUCCESS;
}
