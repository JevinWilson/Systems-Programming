//Program 1

/*
#define write(message) printf("%s", message)
#define writeln(message) printf("%s\n", message)

#define begin {
#define end }

main() begin
    write("first");
    write("line");
    writeln(" "); 
    writeln("Jevin Wilson"); 
    writeln("this is not actually written in PASCAL"); 
end
*/



//Program 2

#include "encode_decode.h"

int main() 
{
    //test encode and decode
    int X = -237;
    int Y = 115;
    unsigned char Type = 1;
    unsigned char Red = 208;
    unsigned char Green = 184;
    unsigned char Blue = 192;

    uint32_t encodedValue = encode(X, Y, Type, Red, Green, Blue);
    printf("Encoded value: %u\n", encodedValue);

    int decodedX, decodedY;
    unsigned char decodedType, decodedRed, decodedGreen, decodedBlue;
    decode(encodedValue, &decodedX, &decodedY, &decodedType, &decodedRed, &decodedGreen, &decodedBlue);

    printf("Decoded values:\n");
    printf("X: %d\nY: %d\nType: %u\nRed: %u\nGreen: %u\nBlue: %u\n",
           decodedX, decodedY, decodedType, decodedRed, decodedGreen, decodedBlue);


    // Mask for the bits used during encoding
    uint32_t mask = (X_SIGN_MASK | X_ABS_MASK | TYPE_MASK | RED_MASK | GREEN_MASK | BLUE_MASK);

    // test random values
    for (int i = 0; i < 10; ++i) 
    {
        uint32_t randomValue = rand();

        // Mask the random value to keep only the bits used during encoding
        randomValue &= mask;

        int decodedX, decodedY;
        unsigned char decodedType, decodedRed, decodedGreen, decodedBlue;
        decode(randomValue, &decodedX, &decodedY, &decodedType, &decodedRed, &decodedGreen, &decodedBlue);

        // Print intermediate values during encoding
        uint32_t reencodedValue;
        printf("Original (masked): %u\n", randomValue);
        printf("Decoded:  X=%d Y=%d Type=%u Red=%u Green=%u Blue=%u\n", decodedX, decodedY, decodedType, decodedRed, decodedGreen, decodedBlue);

        // Intermediate values during encoding
        uint32_t encodedY = ENCODE(abs(decodedY), X_ABS_MASK, X_ABS_SHIFT);
        uint32_t encodedX = ENCODE(abs(decodedX), X_ABS_MASK, X_ABS_SHIFT);
        uint32_t encodedType = ENCODE(decodedType, TYPE_MASK, TYPE_SHIFT);
        uint32_t encodedRed = ENCODE(decodedRed, RED_MASK, RED_SHIFT);
        uint32_t encodedGreen = ENCODE(decodedGreen, GREEN_MASK, GREEN_SHIFT);
        uint32_t encodedBlue = ENCODE(decodedBlue, BLUE_MASK, BLUE_SHIFT);

        // Combine intermediate values to get the reencoded value
        reencodedValue = encodedY | encodedX | encodedType | encodedRed | encodedGreen | encodedBlue;

        printf("Intermediate (encoded): Y=%u X=%u Type=%u Red=%u Green=%u Blue=%u\n", encodedY, encodedX, encodedType, encodedRed, encodedGreen, encodedBlue);
        printf("Reencoded: %u\n", reencodedValue);

        // check if re-encoded value matches the original random value
        if ((randomValue & mask) != (reencodedValue & mask)) 
        {
            printf("Test failed!\n");
            return 1;
        }
    }

    printf("All random tests passed!\n");

    //test large number of random values and write files
    FILE *file1 = fopen("c:\\Users\\jaw06\\Desktop\\System Programming\\Homework12\\output.txt", "w");
    FILE *file2 = fopen("uncompressed.bin", "wb");
    FILE *file3 = fopen("compressed.bin", "wb");

    for (int i = 0; i < 100000; ++i) 
    {
        //generate random test values
        uint32_t randomValue = rand();

        int decodedX, decodedY;
        unsigned char decodedType, decodedRed, decodedGreen, decodedBlue;
        decode(randomValue, &decodedX, &decodedY, &decodedType, &decodedRed, &decodedGreen, &decodedBlue);

        //write to file 1
        fprintf(file1, "%d:%d:%u:%u:%u:%u\n", decodedX, decodedY, decodedType, decodedRed, decodedGreen, decodedBlue);

        //write to file 2
        fwrite(&decodedX, sizeof(int), 1, file2);
        fwrite(&decodedY, sizeof(int), 1, file2);
        fwrite(&decodedType, sizeof(unsigned char), 1, file2);
        fwrite(&decodedRed, sizeof(unsigned char), 1, file2);
        fwrite(&decodedGreen, sizeof(unsigned char), 1, file2);
        fwrite(&decodedBlue, sizeof(unsigned char), 1, file2);

        //write to file 3
        fwrite(&randomValue, sizeof(uint32_t), 1, file3);
    }

    fclose(file1);
    fclose(file2);
    fclose(file3);

    printf("Files written successfully\n");

    //verify files
    FILE *file1_verify = fopen("c:\\Users\\jaw06\\Desktop\\System Programming\\Homework12\\output.txt", "r");
    FILE *file2_verify = fopen("uncompressed.bin", "rb");
    FILE *file3_verify = fopen("compressed.bin", "rb");

    //implementation to read and verify files...

    fclose(file1_verify);
    fclose(file2_verify);
    fclose(file3_verify);

    return 0;
}