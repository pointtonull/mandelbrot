#ifndef _ALGORITHM_H_
#define _ALGORITHM_H_

#include <stdlib.h>
#include <stdio.h>
#include <omp.h>
#include <complex.h>
#include <stdbool.h>

/*#include complex.h
complex_t rec_mandelbrot(int n, complex_t my_c);*/

struct options
{
    int image_height;
    int image_width;
    double pixel_size;
    double complex center;
    int max_iterations;
    int magic_box_min_size;
};

struct image
{
    int height;
    int width;
    unsigned char *pixels;
};

extern struct options options;

void set_pixel_from_iteration_count(int image_row, int image_column, int
    iterations);
void create_blank_image(void);
void save_image(const char *filename);

int iterate_point(double complex c);
void generate_mandelbrot_image(void);
void generate_mandelbrot_subimage(int row1, int row2, int column1, int
    column2);

#endif
