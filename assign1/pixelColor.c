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

// Adjust and add more step ranges here
// Make sure they don't overlap!
#define RANGE_1_LOWER   1
#define RANGE_1_UPPER 255

// Colours - add more of them:
//                R    G    B
#define BLACK   {  0,   0,   0}
#define WHITE   {255, 255, 255}

// Add a colour ID for each range
#define RANGE_1_COLOR   WHITE


// This function should take a number (of steps taken to escape the
// Mandelbrot set), and convert it to a color.
//
// You have artistic licence here, so make your Mandelbrot look amazing.
pixel pixelColor (int steps) {
    
    pixel color = BLACK; // Initialisation
    
    // Numbers inside the Mandelbrot set are coloured black.
    if (steps == NO_ESCAPE) {
        color = BLACK;
        
        // Add a new condition for each step range that you add
    } else if (steps >= RANGE_1_LOWER && steps <= RANGE_1_UPPER) {
        color = RANGE_1_COLOR;
    } 
    
    
    return color;
}
