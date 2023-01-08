#pragma once

#include <stdint.h> /* uint8_t */
#include <stddef.h> /* size_t */

long compress_nt
(
    uint8_t **bs,  /* pointer to bit sequence             [in/out] */
    size_t *bytes, /* number of bytes allocated to @(*bs) [in/out] */
    size_t len,    /* length of @s                        [in]     */
    const char *s  /* ASCII sequence                      [in]     */
);

long decompress_nt
(
    char **s,         /* pointer to char sequence           [in/out] */
    size_t *bytes,    /* nubmer of bytes allocated to @(*s) [in/out] */
    size_t len,       /* length of @(*s)                    [in]     */
    const uint8_t *bs /* bit sequence                       [in]     */
);
