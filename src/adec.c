#include "common.h"

int main()
{
    num tblSz = GET(), i = NUL;
    byte *table = calloc(MVAL, sizeof(byte)), buf = GET();

    for(; i < tblSz && !EF; i ++, buf = GET()) table[i] = buf;

    for(; !EF; buf = GET()) PUT(table[buf]);

    return 0;
}
