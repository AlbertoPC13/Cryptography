#include <stdio.h>
#include <stdlib.h>
#include "AES.h"

int main(int argc, char const *argv[])
{
    unsigned char key_128[16] = {0x2B, 0x7E, 0x15, 0x16, 0x28, 0xAE, 0xD2, 0xA6, 0xAB, 0xF7, 0x15, 0x88, 0x09, 0xCF, 0x4F, 0x3C};
    unsigned char key_192[24] = {0x8E, 0x73, 0xB0, 0xF7, 0xDA, 0x0E, 0x64, 0x52, 0xC8, 0x10, 0xF3, 0x2B, 0x80, 0x90, 0x79, 0xE5, 0x62, 0xF8, 0xEA, 0xD2, 0x52, 0x2C, 0x6B, 0x7B};
    unsigned char **w = keyScheduleCreation();

    keyExpansion(key_128, w);

    printf("\n\n");
    for (short i = 0; i < (Nb * (Nr + 1)); i++)
    {
        printf("%d - ", i);
        for (short j = 0; j < 4; j++)
        {
            printf("[%x]", w[i][j]);
        }
        printf("\n\n");
    }
    printf("\n\n");

    unsigned char in[16] = {0x32, 0x43, 0xF6, 0xA8, 0x88, 0x5A, 0x30, 0x8D, 0x31, 0x31, 0x98, 0xA2, 0xE0, 0x37, 0x07, 0x34};
    unsigned char **state = StateCreation(in);

    AddRoundKey(state,w,0);
    subBytes(state);
    shiftRows(state);

    for (short i = 0; i < Nb; i++)
    {
        for (short j = 0; j < 4; j++)
        {
            printf("[%x]", state[i][j]);
        }
        printf("\n\n");
    }
    printf("\n\n");

    return 0;
}