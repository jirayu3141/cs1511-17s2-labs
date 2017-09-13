// Assignment 1 Mandelbrot
//
// Completed by
//  Kevin Luxa (z5074984)
//  Ahnaf Aaqif (z5125723)
//  Seokhyun Phil Jung (z3459079)
//
// Modified on 2017-09-08
// Tutor: Stephen Leung (fri09-kora)

// Add your own #includes here

#include "mandelbrot.h"
#include "pixelColor.h"

// Add your own #defines here
#define BOUNDARY 2
#define BOUNDARY_SQUARED BOUNDARY * BOUNDARY
#define BASE_PIXEL_LENGTH 2

// Add your own function prototypes here
static int bounded (complex z);
static complex iterateMandelbrot (complex z, complex c);
static long double getPixelLength (int z);
static unsigned long long getPower (int base, int exponent);
static complex getCoords (int x, int y, complex center,
                          long double pixelLength);
static complex complexSum (complex c1, complex c2);
static complex complexMultiply (complex c1, complex c2);
static complex complexSquare (complex c);
static double complexModSquared (complex c);

// Draw a single Mandelbrot tile, by calculating and colouring each of
// the pixels in the tile.
//
// Your function "returns" this tile by filling in the `pixels` 2D array
// that is passed in to your function.
//
// The `pixels` array is TILE_SIZE high and TILE_SIZE wide.
// The bottom left corner of the image is pixels[0][0].
//
// `center` is a complex number, representing the center of the tile.
// `z` is used to calculate the distance between each pixel in the image.
// Each pixel is 2^(-z) apart from each other.
void drawMandelbrot (pixel pixels[TILE_SIZE][TILE_SIZE],
                     complex center, int z) {
    // Stores result from escapeGrid
    int grid[TILE_SIZE][TILE_SIZE];
    escapeGrid (grid, center, z);

    // Sets each pixel in the tile to a color
    int y = 0;
    while (y < TILE_SIZE) {
        int x = 0;
        while (x < TILE_SIZE) {
            pixels[y][x] = pixelColor (grid[y][x]);
            x++;
        }
        y++;
    }
}

// Determine the number of steps required to escape the Mandelbrot set,
// for the given complex number `c`.
int escapeSteps (complex c) {
    int steps = 0;
    complex z = {0, 0}; // z starts at 0 + 0i
    
    // Continues to iterate the Mandelbrot function as
    // long as z remains bounded and steps < MAX_STEPS
    while (bounded (z) && (steps < MAX_STEPS)) {
        z = iterateMandelbrot (z, c);
        steps++;
    }
    if (steps == MAX_STEPS) {
        steps = NO_ESCAPE;
    }
    return steps;
}

// Fill a grid of TILE_SIZE by TILE_SIZE pixels, with the number of
// steps each pixel took to escape the Mandelbrot set.
void escapeGrid (int grid[TILE_SIZE][TILE_SIZE],
                 complex center, int z) {
    // Gets the length of a pixel from zoom level
    long double pixelLength = getPixelLength (z);
    
    int y = 0;
    while (y < TILE_SIZE) {
        int x = 0;
        while (x < TILE_SIZE) {
            // Finds the coordinates in the complex plane of a pixel in
            // the tile (given by x and y)
            complex pixelCoords = getCoords (x, y, center, pixelLength);
            
            // Gets the result of escapeSteps for the coordinates of
            // this pixel and stores it in its position in grid.
            grid[y][x] = escapeSteps (pixelCoords);
            x++;
        }
        y++;
    }
}

// Add your own functions here.
// Remember to make them static.

// Determines whether z is bounded (i.e., tests if
// |z| <= 2 by testing the equivalent if |z|^2 <= 4)
static int bounded (complex z) {
    return complexModSquared (z) <= BOUNDARY_SQUARED;
}

// Performs one iteration of the Mandelbrot function on z
static complex iterateMandelbrot (complex z, complex c) {
    return complexSum (complexSquare (z), c);
}

// Determines the length of a pixel from a zoom level
// Pixel length = 2^(-z) = 1 / 2^z
static long double getPixelLength (int z) {
    return (1.0 / getPower (BASE_PIXEL_LENGTH, z));
}

// Takes a base and exponent and returns base^exponent
static unsigned long long getPower (int base, int exponent) {
    unsigned long long result = 1;
    int i = 0;
    while (i < exponent) {
        result *= base;
        i++;
    }
    return result;
}

// Takes in two array indices, the length of a pixel, and the center of
// the tile, and returns the coordinates in the complex plane (given by
// a complex number) corresponding to the array indices
static complex getCoords (int x, int y, complex center,
                          long double pixelLength) {
    // Translates x and y so (0, 0) is the center of the tile
    x -= TILE_SIZE / 2;
    y -= TILE_SIZE / 2;
    // Gets the coordinates relative to the centre of the tile
    complex relativeCoords = {x * pixelLength, y * pixelLength};
    // Adds the centre coordinates to get absolute coordinates
    // (which are relative to the centre of the complex plane)
    complex absoluteCoords = complexSum (center, relativeCoords);
    return absoluteCoords;
}

// Adds two complex numbers
static complex complexSum (complex c1, complex c2) {
    complex sum = {
        .re = c1.re + c2.re,
        .im = c1.im + c2.im
    };
    return sum;
}

// Returns the product of two complex numbers
static complex complexMultiply (complex c1, complex c2) {
    complex product = {
        .re = c1.re * c2.re - c1.im * c2.im,
        .im = c1.im * c2.re + c2.im * c1.re
    };
    return product;
}

// Returns the square of a complex number
static complex complexSquare (complex c) {
    return complexMultiply (c, c);
}

// Returns the square of the modulus of a complex number
// modulus = distance from the centre of the complex plane
static double complexModSquared (complex c) {
    return c.re * c.re + c.im * c.im;
}
