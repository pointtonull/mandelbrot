#include "algorithm.h"

struct options options;

void parse_options(int argc, char *argv[])
{
    options.image_height = 400;
    options.image_width = 400;
    options.max_iterations = 60;
    options.center = 0;
    switch (argc){
        case 5:
            options.max_iterations = atoi(argv[4]);
        case 4:
            options.center += atof(argv[3]) * I;
        case 3:
            options.center += atof(argv[2]);
        case 2:
            options.pixel_size = 0.0125 / atof(argv[1]);
            break;
        default:
            printf("Valid syntax:\n");
            printf("    ./mandel-basic level [x_pos [y_pos [iterations]]]\n");
            printf("e.g:\n");
            printf("    ./mandelbrot 1\n");
            printf("    ./mandelbrot 16 .35\n");
            printf("    ./mandelbrot 16 -1.75 0 200\n");
            exit(1);
            break;
    }
}


int main(int argc, char *argv[])
{
    parse_options(argc, argv);
    create_blank_image();
    generate_mandelbrot_image();
    save_image("image.ppm");
    return 0;
}
