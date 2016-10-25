#include "common.h"

#define SKIP 200 /* The amount of bytes to skip in stdin */
#define WCOR 1 /* The correction for getting an accurate minimal crestlength */
#define THRSH 0x90 /* The threshold to which it is considered part of a crest */
<<<<<<< HEAD
#define RCNST 0.445 /* If a value is greater than this constant, it is rounded
=======
#define RCONST 0.445 /* If a value is greater than this constant, it is rounded
>>>>>>> 0acd703eb86df399d0904c145edaf457c8b58bf2
                        up */

num bLen = sizeof(byte);

num dvid(dbl a, dbl b) /* Divide and round */
{
    dbl d = a / b;
    num n = d;
    dbl f = d - n;

    return n + (f > RCNST);
}

num getW()
{
    num cLen = NUL;

    while(GET() < THRSH && !EF);
    while(GET() >= THRSH && !EF) cLen ++;

    return dvid(cLen, bLen);
}

int main( void )
{
    byte buf;

    getW();
    bLen = getW() + WCOR;

    while(!EF && getW() != LEND);
    for(buf = getW(); !EF; buf = getW()) PUT(buf);

    PUT(buf);

    return NUL;
}
