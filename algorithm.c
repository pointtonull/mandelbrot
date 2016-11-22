#include "algorithm.h"
#include "complex.h"
#include <math.h>


static struct image image = {0, 0, NULL};


double complex mandelbrot(int n, double complex c)
{
    double complex z;

    if (n <= 0)
        return c;
    else {
        z = mandelbrot(n - 1, c);
        if (cabs(z) <= 2)
            z = z * z + c;
        return z;
    }
}


void generate_mandelbrot_image(void)
{
    generate_mandelbrot_subimage(0, options.image_height - 1, 0,
        options.image_width - 1);
}


void generate_mandelbrot_subimage(int row1, int row2, int col1, int col2)
{
    double x, y, x1, y1;
    int image_row, image_col;
    double iterations;
    double complex z;

    y1 = cimag(options.center) + (options.pixel_size *
        (options.image_height - 1)) / 2.0;

    x1 = creal(options.center) - (options.pixel_size *
        (options.image_width - 1)) / 2.0;

    for (image_row=row1; image_row <= row2; ++image_row)
    {
        for (image_col=col1; image_col <= col2; ++image_col)
        {
            y = y1 - image_row * options.pixel_size;
            x = x1 + image_col * options.pixel_size;
            z = x + y * I;
            iterations = iterate_point(z);
            set_pixel_from_iteration_count(image_row, image_col, iterations);
        }
    }
}


void set_pixel_from_iteration_count(int image_row, int image_col, int
        iterations)
{
    unsigned char *pixel;

    pixel = image.pixels + 3 * image_row * image.width + 3 * image_col;
    pixel[0] = (13 * iterations) % 256;
    pixel[1] = (5 * iterations) % 256;
    pixel[2] = (11 * iterations) % 256;
}


void create_blank_image(void)
{
    unsigned char *pixel;
    int i;

    image.width = options.image_width;
    image.height = options.image_height;
    image.pixels = malloc(3 * image.width * image.height);
    pixel = image.pixels;
    for (i=0; i < image.width * image.height; ++i)
    {
        pixel[0] = pixel[1] = pixel[2] = 0;
        pixel += 3;
    }
}


void save_image(const char *file)
{
    FILE *fp;

    fp = fopen(file, "w");
    if (fp == NULL)
    {
        printf("Failed to open file %s\n", file);
        return;
    }

    fprintf(fp, "P6\n");
    fprintf(fp, "%d %d\n", options.image_width, options.image_height);
    fprintf(fp, "255\n");
    fwrite(image.pixels, 3 * image.width * image.height, 1, fp);
    fclose(fp);
    free(image.pixels);
    image.pixels = NULL;
    printf("Graph saved to '%s'\n", file);
}
