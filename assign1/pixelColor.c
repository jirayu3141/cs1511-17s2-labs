// Assignment 1 Mandelbrot: Pixel Color
//
// Completed by
//  Kevin Luxa (z5074984)
//  Ahnaf Aaqif (z5125723)
//  Seokhyun Phil Jung (z3459079)
//
// Modified on 2017-09-10
// Tutor: Stephen Leung (fri09-kora)

#include "mandelbrot.h"
#include "pixelColor.h"

// Add a colour ID for each range
#define RANGE_1_COLOR  1


// Adjust and add more step ranges here
// Make sure they don't overlap!
#define RANGE_1_LOWER   1
#define RANGE_1_UPPER 255


// Function Prototypes
pixel getColor (int colorID);

// Add more colors here:
//    color name      R    G    B     Color ID
pixel black       = {  0,   0,   0};  //     0
pixel white       = {255, 255, 255};  //     1


// This function should take a number (of steps taken to escape the
// Mandelbrot set), and convert it to a color.
//
// You have artistic licence here, so make your Mandelbrot look amazing.
pixel pixelColor (int steps) {
    
    pixel color = black; // Initialisation
    
    // Numbers inside the Mandelbrot set are coloured black.
    if (steps == NO_ESCAPE) {
        color = black;
        
        // Add a new condition for each step range that you add
    } else if (steps >= RANGE_1_LOWER && steps <= RANGE_1_UPPER) {
        color = getColor (RANGE_1_COLOR);
    } 
    
    
    return color;
}

// Takes a colorID and returns the color corresponding to it.
pixel getColor (int colorID) {

    pixel color = black; // Initialisation
    
    // Add a new condition for each color that you add
    if (colorID == 1) {
        color = white;
    }
    
    
    return color;
}
