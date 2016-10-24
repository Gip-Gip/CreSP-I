#include "common.h"

#define TLEN 1 /* The length of the trough */
#define HLEN 20000 /* The length of the header */
#define AMP 0xFF /* The amperage */
#define LCOR 1 /* Correction constant for genWave */

void genWave(num len)
{
    num tLen = TLEN;

    while(tLen--) PUT(NUL);
    while(len-- + LCOR) PUT(AMP);
}

int main( void )
{
    num hLen = HLEN, buf = GET();

    while(--hLen) genWave(NUL);

    genWave(LEND);

    for(; !EF; buf = GET()) genWave(buf);

    return NUL;
}
