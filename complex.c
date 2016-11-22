#include <stdio.h>
#include <math.h>
#include "complex.h"


complex_t add_complex(complex_t c1, complex_t c2)
{
    complex_t csum;

    csum.real = c1.real + c2.real;
    csum.imag = c1.imag + c2.imag;
    return (csum);
}



complex_t subtract_complex(complex_t c1, complex_t c2)
{
    complex_t cdiff;

    cdiff.real = c1.real - c2.real;
    cdiff.imag = c1.imag - c2.imag;
    return (cdiff);
}


complex_t multiply_complex(complex_t c1, complex_t c2)
{
    complex_t cmult;

    cmult.real = (c1.real * c2.real) - (c1.imag * c2.imag);
    cmult.imag = (c1.real * c2.imag) + (c1.imag * c2.real);
    return (cmult);
}

complex_t abs_complex(complex_t c)
{
    complex_t cabs;

    cabs.real = sqrt((c.real * c.real) + (c.imag * c.imag));
    cabs.imag = 0;
    return (cabs);
}
