#include "common.h"

int main()
{
    num tSz = GET(), i = NUL;
    byte *tbl = calloc(MVAL, sizeof(byte)), buf = GET();

    for(; i < tSz && !EF; i ++, buf = GET()) tbl[i] = buf;

    for(; !EF; buf = GET()) PUT(tbl[buf]);

    return NUL;
}
