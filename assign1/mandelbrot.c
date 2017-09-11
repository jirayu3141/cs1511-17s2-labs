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
#include "pixelColor.c"

// Add your own #defines here
#define BOUNDARY 2
#define BOUNDARY_SQUARED BOUNDARY * BOUNDARY
#define BASE_PIXEL_LENGTH 2

// Add your own function prototypes here
static double getPixelLength (z);
static unsigned long getPower (int base, int exponent);
static complex getCoords (int x, int y, complex center,
                          double pixelLength);
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
    complex z = c;
    // For all values of |z| where |z^2 + c| < 2 AND steps < 256
    while ((complexSquare(z) <= BOUNDARY_SQUARED) && (steps < MAX_STEPS)) {
        // Update z with the previous result of z.
        z = complexSum (complexSquare (z), c);
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
    double pixelLength = getPixelLength (z);
    int y = 0;
    while (y < TILE_SIZE) {
        int x = 0;
        while (x < TILE_SIZE) {
            complex pixelCoords = getCoords (x, y, center, pixelLength);
            grid[y][x] = escapeSteps (pixelCoords);
            x++;
        }
        y++;
    }
}

// Add your own functions here.
// Remember to make them static.

// Determines the length of a pixel given a zoom level
// Pixel length = 2^(-z) = 1 / 2^z
static double getPixelLength (z) {
    return (1 / getPower (BASE_PIXEL_LENGTH, z));
}

// Takes a base and exponent and returns base^exponent
static unsigned long getPower (int base, int exponent) {
    int result = 1;
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
                          double pixelLength) {
    // Translates x and y so (0, 0) is the center of the tile
    x -= TILE_SIZE / 2;
    y -= TILE_SIZE / 2;
    // Gets relative (to the center) and absolute coordinates
    complex relativeCoords = {x * pixelLength, y * pixelLength};
    complex absoluteCoords = complexSum (center, relativeCoords);
    return absoluteCoords;
}

// Adds two complex numbers
static complex complexSum (complex c1, complex c2) {
    complex sum =
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

static double complexModSquared (complex c) {
    return c.re * c.re + c.im * c.im;
}
