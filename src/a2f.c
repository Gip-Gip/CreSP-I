#include "common.h"

#define SKIP 200 /* The amount of bytes to skip in stdin */
#define WCOR 1 /* The correction for getting an accurate minimal crestlength */
#define THRSH 50 /* The threshold to which it is considered part of a crest */
#define RCONST 0.445 /* If a value is greater than this constant, it is rounded
                        up */

num bLen = sizeof(byte);

num rounded(double di, double dv)
{
    double d = di / dv;
    num n = d;
    double f = d - n;

    return n + (f > RCONST);
}

num getWave()
{
    num cLen = NUL;

    while(GET() < THRSH && !EF);
    while(GET() >= THRSH && !EF) cLen ++;

    return rounded(cLen, bLen);
}

int main( void )
{
    byte buf;

    fseek(stdin, SKIP, SEEK_SET);
    getWave();
    bLen = getWave() + WCOR;

    while(!EF && getWave() != LEND);
    for(buf = getWave(); !EF; buf = getWave()) PUT(buf);

    PUT(buf);

    return 0;
}
