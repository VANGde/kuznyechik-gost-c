#ifndef KUZNYECHIK_H
#define KUZNYECHIK_H

#include <stdint.h>
#include <string.h>

#define KUZNECHIK_BLOCK_SIZE 16

typedef unsigned char      u8;
typedef signed char        i8;
typedef unsigned short     u16;
typedef unsigned int       u32;
typedef unsigned long long u64;
typedef void               v;

typedef union {
    u8  b[16];
    u64 q[2];
} block128;

extern const u8 Pi[256];
extern const u8 Pi_reverse[256];
extern const u8 linear_vector[16];

v  X(const block128 *a, const block128 *b, block128 *c);
v  print_chunk(const block128 *p);
u8 GF_mult(u8 a, u8 b);

v S(block128 *in_out);
v S_reverse(block128 *in_out);
v R(block128 *in_out);
v R_reverse(block128 *in_out);
v L(block128 *in_out);
v L_reverse(block128 *in_out);

v gen_round_keys(const block128 key[2], block128 round_keys[10]);
v kuznechik_encrypt(const block128 round_keys[10], const block128 *in, block128 *out);
v kuznechik_decrypt(const block128 round_keys[10], const block128 *in, block128 *out);

#endif
