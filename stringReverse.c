//               gnirtS a esreveR    Reverse a String
//                     yb detaerC    Created by
// )9709543z( gnuJ lihP nuyhkoeS      Seokhyun Phil Jung (z3459079)
//         )4894705z( axul niveK      Kevin Luxa (z5074984)
//        )3275215z( fiqaA fanhA      Ahnaf Aaqif (z5125723)
//          52-80-7102 no detaerC    Created on 2017-08-25
//    )arok-90-irf( gnueL nehpetS    Stephen Leung (fri09-kora)

#include <stdio.h>
#include <stdlib.h>

void stringReverse (char *buffer);
int stringLength (char *string);
void swap (char *array, int i, int j);

int main (int argc, char *argv[]) {
    /// THIS WON'T WORK!
    ///
    /// `str` only points to a string literal, which is stored in a
    /// read only section of the program.  If you attempt to modify
    /// it, your program will crash with a memory error (usually,
    /// SIGSEGV, the infamous "segmentation fault").
    //
    // char *str = "Hello!"
    // stringReverse (str)

    char str[] = ".'neetneves' :egassem terces A";
    stringReverse (str);
    printf ("%s\n", str);

    return EXIT_SUCCESS;
}

// Takes a string in `buffer`, and reverses it in-place.
void stringReverse (char *buffer) {
    int length = stringLength (buffer);
    int iMax = length - 1;
    int i = 0;
    while (i <= iMax / 2 && length != 0) {
        swap(buffer, i, iMax - i);
        i++;
    }
}

// Takes a string and finds its length, excluding the null-terminator.
int stringLength (char *string) {
    int i = 0;
    while (string[i] != '\0') {
        i++;
    }
    return i;
}

// Swaps two elements of an array, identified by their index
void swap (char *array, int i, int j) {
    char temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}
