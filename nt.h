/** @file nt.h
 *  @brief Prototypes for 2-bit encoding and decoding of nucleotide sequences.
 *
 *  TODO: fill this out.
 *
 *  @author Gabriel Raulet
 */

#ifndef _NT_H
#define _NT_H

#include <stdint.h> /* uint8_t */
#include <stddef.h> /* size_t */

/** @brief Encodes nucleotide sequences using 2 bits per nucleodies.
 *
 *  @param bs pointer to bit sequence
 *  @param bytes number of bytes allocated to bit sequence
 *  @param len number of nucleotides in sequence
 *  @param s nucelotide sequence
 *
 *  @return The number of bytes needed to encode the sequence.
 */
long compress_nt(uint8_t **bs, size_t *bytes, size_t len, const char *s);

/** @brief Decode bit sequence into ASCII nucleotide sequence.
 *
 *  @param s pointer to ASCII sequence
 *  @param bytes number of bytes allocated to ASCII sequence
 *  @param len length of ASCII sequence
 *  @param bs bit sequence
 *
 *  @return The length of the decoded ASCII sequence.
 */
long decompress_nt(char **s, size_t *bytes, size_t len, const uint8_t *bs);

#endif
