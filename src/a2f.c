#include <common.h>

#define SKIP 200
#define CLENI 1
#define WCOR 1
#define THRSH 50

num bLen = 1;

num rounded(double di, double dv)
{
    double d = di / dv;
    num n = d;
    double f = d - n;

    return n + (f > 0.445);
}

num getWave()
{
    num cLen = CLENI;

    while(GET() < THRSH && !EF);
    while(GET() >= THRSH && !EF) cLen ++;

    return rounded(cLen, bLen) - WCOR;
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
