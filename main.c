#include "nt.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    const char *seq = "GATTACAC";
    size_t len = strlen(seq);

    size_t bytes = 0;
    uint8_t *bs = NULL;

    compress_nt(&bs, &bytes, len, seq);

    fwrite(bs, 1, bytes, stdout);
    fflush(stdout);

    char *s = NULL;
    bytes = 0;

    decompress_nt(&s, &bytes, len, bs);

    fwrite(s, 1, bytes, stdout);
    fflush(stdout);

    free(bs);
    free(s);

    return 0;
}
