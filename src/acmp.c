#include <common.h>

int main( void )
{
    num *frqTbl = calloc(MVAL, sizeof(num)), tblSz = MVAL, top = NUL, i;
    byte *outTbl = calloc(MVAL, sizeof(byte)), buf = GET();

    for(;!EF; buf = GET())
    {
        frqTbl[buf] ++;
        if(frqTbl[buf] > frqTbl[top]) top = buf;
    }

    for(;tblSz && frqTbl[top] != NUL;tblSz --)
    {
        outTbl[MVAL - tblSz] = top, frqTbl[top] = 0;

        for(i = NUL; i < MVAL; i ++) if(frqTbl[i] > frqTbl[top]) top = i;
    }

    PUT(tblSz = MVAL - tblSz);

    for(i = NUL; i < tblSz; i ++)
    {
        PUT(outTbl[i]);
        frqTbl[outTbl[i]] = i;
    }

    fseek(stdin, 0, SEEK_SET);

    for(buf = GET(); !EF; buf = GET()) PUT(frqTbl[buf]);

    return 0;
}