#include "nt.h"
#include "tab.h" /* char2code, code2char */
#include <stdlib.h> /* realloc */
#include <string.h> /* memset */
#include <limits.h> /* LONG_MAX */

long compress_nt(uint8_t **bs, size_t *bytes, size_t len, const char *s)
{
    uint8_t *buf; /* bit sequence */
    size_t n;     /* number of bytes allocated to @(*bs) */

    if (bs == NULL || bytes == NULL || s == NULL)
        return -1;

    buf = *bs;
    n = (len + 3) / 4; /* number of bytes needed to encode @len nucleotides */

    /* make sure @(*bs) has enough space */
    if (buf == NULL || *bytes < n)
    {
        buf = realloc(*bs, n);

        if (buf == NULL)
            return -1;

        *bytes = n;
        *bs = buf;
    }

    memset(buf, 0, n); /* set to zero or bitwise OR will not work */

    for (size_t i = 0; i < len; ++i)
    {
        buf[i/4] |= char2code[(int)s[i]] << ((i % 4) << 1);
    }

    return n <= LONG_MAX? (long)n : LONG_MAX;
}

long decompress_nt(char **s, size_t *bytes, size_t len, const uint8_t *bs)
{
    char *buf;

    if (s == NULL || bytes == NULL || bs == NULL)
        return -1;

    buf = *s;

    if (buf == NULL || *bytes < len)
    {
        buf = realloc(*s, len);

        if (buf == NULL)
            return -1;

        *bytes = len;
        *s = buf;
    }

    for (size_t i = 0; i < len; ++i)
    {
        buf[i] = code2char[(bs[i/4] >> ((i % 4) << 1)) & 3];
    }

    /* null-terminate only if there is space */
    if (*bytes + 1 >= len)
        buf[len] = (char)0;

    return len <= LONG_MAX? (long)len : LONG_MAX;
}
