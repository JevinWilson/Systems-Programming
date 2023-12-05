#ifndef ENCODE_DECODE_H
#define ENCODE_DECODE_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

uint32_t encode(int X, int Y, unsigned char Type, unsigned char Red, unsigned char Green, unsigned char Blue);
void decode(uint32_t value, int *X, int *Y, unsigned char *Type, unsigned char *Red, unsigned char *Green, unsigned char *Blue);

//macros
#define X_SIGN_MASK 0x00400000
#define X_ABS_MASK 0x00003F80
#define TYPE_MASK 0x00002000
#define RED_MASK 0x0000F000
#define GREEN_MASK 0x000007C0
#define BLUE_MASK 0x000000F0

#define X_SIGN_SHIFT 22
#define X_ABS_SHIFT 14
#define TYPE_SHIFT 13
#define RED_SHIFT 9
#define GREEN_SHIFT 4
#define BLUE_SHIFT 0

#define DECODE(value, mask, shift) ((value & mask) >> shift)
#define ENCODE(value, mask, shift) ((value << shift) & mask)

#endif // ENCODE_DECODE_H
