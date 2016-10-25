#include "common.h"

#define TLEN 1 /* The length of the trough */
#define HLEN 20000 /* The length of the header */
#define AMP 0xFF /* The amperage */
#define LCOR 1 /* Correction constant for genWave */

void genW(num len)
{
    num tLen = TLEN;

    while(tLen--) PUT(NUL);
    while(len-- + LCOR) PUT(AMP);
}

int main( void )
{
    num hLen = HLEN, buf = GET();

    while(--hLen) genW(NUL);

    genW(LEND);

    for(; !EF; buf = GET()) genW(buf);

    return NUL;
}
