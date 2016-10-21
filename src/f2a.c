#include "common.h"

#define TLEN 1
#define HLEN 20000
#define AMP 200
#define LCOR 2

void genWave(num len)
{
    num tLen = TLEN;

    while(--tLen + LCOR) PUT(NUL);
    while(--len + LCOR) PUT(AMP);
}

int main( void )
{
    num hLen = HLEN, buf = GET();

    while(--hLen) genWave(NUL);

    genWave(LEND);

    for(; !EF; buf = GET()) genWave(buf);

    return 0;
}
