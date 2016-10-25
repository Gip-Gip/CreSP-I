#include "common.h"

int main( void )
{
    num *fTbl = calloc(MVAL, sizeof(num)), tSz = NUL, top = NUL, i;
    byte *oTbl = calloc(MVAL, sizeof(byte)), buf = GET();

    for(; !EF; buf = GET())
    {
        fTbl[buf] ++;
        if(fTbl[buf] > fTbl[top]) top = buf;
    }

    for(; tSz < MVAL && fTbl[top] != NUL; tSz ++)
    {
        oTbl[tSz] = top, fTbl[top] = NUL;

        for(i = NUL; i < MVAL; i ++) if(fTbl[i] > fTbl[top]) top = i;
    }

    PUT(tSz);

    for(i = NUL; i < tSz; i ++)
    {
        PUT(oTbl[i]);
        fTbl[oTbl[i]] = i;
    }

    fseek(stdin, NUL, SEEK_SET);

    for(buf = GET(); !EF; buf = GET()) PUT(fTbl[buf]);

    return NUL;
}
