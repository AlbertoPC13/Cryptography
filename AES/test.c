#include<stdio.h>
#include<stdlib.h>

# define Nb 4 // Block size

#define copy(A,B) for(int i = 0; i < 4; i++) A[i] = B[i]
#define XOR(R,A,B) for(int i = 0; i < Nb; i++) R[i] = A[i]^B[i]

int main(int argc, char const *argv[])
{
    unsigned char *w = (unsigned char *) malloc(4 * sizeof(unsigned char));

    w[0] = 0x0F;
    w[1] = 0x0F;
    w[2] = 0x0F; 
    w[3] = 0x0F;

    printf("\nValor de w: \n");
    for (int i = 0; i < 4; i++)
    {
        printf("[%x]",w[i]);
    }
    printf("\n\n");

    unsigned char *x = (unsigned char *) malloc(4 * sizeof(unsigned char));

    x[0] = 0xF0;
    x[1] = 0xF0;
    x[2] = 0xF0; 
    x[3] = 0xF0;

    printf("\nValor de x: \n");
    for (int i = 0; i < 4; i++)
    {
        printf("[%x]",x[i]);
    }
    printf("\n\n");

    unsigned char *xor = (unsigned char *) malloc(4 * sizeof(unsigned char));

    XOR(xor,w,x);
    
    printf("\nValor de xor: \n");
    for (int i = 0; i < 4; i++)
    {
        printf("[%x]",xor[i]);
    }
    printf("\n\n");

    copy(x,w);

    printf("\nValor de x: \n");
    for (int i = 0; i < 4; i++)
    {
        printf("[%x]",x[i]);
    }
    printf("\n\n");

    printf("\nValor de w: \n");
    for (int i = 0; i < 4; i++)
    {
        printf("[%x]",w[i]);
    }
    printf("\n\n");

    return 0;
}

    // unsigned char palabra[4] = {0x09, 0xCF, 0x4F, 0x3C};

    // unsigned char *rot = (char *) malloc(4*sizeof(char));
    // unsigned char *sub = (char *) malloc(4*sizeof(char));
    // unsigned char *xor = (char *) malloc(4*sizeof(char));

    // rot = rotWord(palabra);
    // sub = subWord(rot);
    // XOR(xor,sub,word(rcon[1],0x00,0x00,0x00));

    // printf("\n\nWord: \n\n");
    // for (int j = 0; j < 4; j++)
    // {
    //         printf("[%x]",palabra[j]);
    // }
    // printf("\n\n");

    // printf("\n\nRotated word: \n\n");
    // for (int j = 0; j < 4; j++)
    // {
    //         printf("[%x]",rot[j]);
    // }
    // printf("\n\n");

    // printf("\n\nSub word: \n\n");
    // for (int j = 0; j < 4; j++)
    // {
    //         printf("[%x]",sub[j]);
    // }
    // printf("\n\n");

    // printf("\n\nXOR word: \n\n");
    // for (int j = 0; j < 4; j++)
    // {
    //         printf("[%x]",xor[j]);
    // }
    // printf("\n\n");

    // int n = Nb*(Nr+1);

    // printf("\n\nWords:\n\n");
    // for (int i = 0; i < Nk; i++)
    // {
    //     for (int j = 0; j < 4; j++)
    //     {
    //         printf("[%x]",w[i][j]);
    //     }
    //     printf("\n");
    // }
    // printf("\n\n");


    // printf("\n\nKey:\n\n");
    // for (int i = 0; i < 4 * Nk; i++)
    //     printf("[%x]",key[i]);
    // printf("\n\n");