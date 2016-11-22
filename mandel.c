#include <stdio.h>
#include <math.h>
#include "complex.h"
#include "mandelbrot.h"


complex_t mandelbrot(int n, complex_t my_c)
{
    complex_t tmp;

    if (n <= 0)
        return (my_c);

    tmp = mandelbrot(n-1, my_c);
    if ((abs_complex(tmp).real) > 1000)
    {
        tmp.real = 100;
        tmp.imag = 100;
    }
    else
    {
        tmp = multiply_complex(tmp, tmp);
        tmp = add_complex(tmp, my_c);
    }
    return (tmp);
}

