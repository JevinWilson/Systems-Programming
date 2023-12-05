#include "encode_decode.h"

#include <stdint.h>

uint32_t encode(int X, int Y, unsigned char Type, unsigned char Red, unsigned char Green, unsigned char Blue) 
{
    uint32_t result = 0;

    //encode Y
    //sign of Y into MSB
    result |= (Y < 0) << 31;
    // 8 LSB of absolute value of Y into next 8 bits
    result |= (abs(Y) & 0xFF) << 23;

    //encode X
    //sign of X into next bit
    result |= (X < 0) << 22;
    // 8 LSB of absolute value of X into next 8 bits
    result |= (abs(X) & 0xFF) << 14;     
    //encode Type, LSB of Type into next bit
    result |= (Type & 0x01) << 13;      

    //encode RGB
    //4 MSB of Red into next 4 bits
    result |= (Red & 0xF0) << 9;
    //5 MSB of Green into next 5 bits
    result |= (Green & 0xF8) << 4;
    //4 MSB of Blue into remaining 4 bits
    result |= (Blue & 0xF0);            

    return result;
}


void decode(uint32_t value, int *X, int *Y, unsigned char *Type, unsigned char *Red, unsigned char *Green, unsigned char *Blue) 
{
    // Extract Y
    *Y = (value >> 23) & 0xFF;
    // Handle the sign of Y
    *Y = ((value >> 31) & 0x01) ? -*Y : *Y;  

    // Extract X
    *X = (value >> 14) & 0xFF;
    // Handle the sign of X
    *X = ((value >> 22) & 0x01) ? -*X : *X;  

    // Extract Type
    *Type = (value >> 13) & 0x01;

    // Extract Red
    *Red = (value >> 9) & 0xF0;
    // Extract Green
    *Green = (value >> 4) & 0xF8;
    // Extract Blue
    *Blue = value & 0xF0;
}
