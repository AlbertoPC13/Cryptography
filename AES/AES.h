#include<stdlib.h>

# define Nb 4 // Block size
# define Nk 4 // Key Length 128
//# define Nk 6 // Key Length 192
# define Nr 10 // Number of rounds 128
//# define Nr 12 // Number of rounds 192

#define copy(A,B) for(int it = 0; it < 4; it++) A[it] = B[it]
#define XOR(R,A,B) for(int it = 0; it < Nb; it++) R[it] = A[it]^B[it]

unsigned char **keyScheduleCreation(void);
void keyExpansion(unsigned char *key, unsigned char **word);
unsigned char *word(unsigned char w0, unsigned char w1, unsigned char w2, unsigned char w3);
unsigned char *rotWord(unsigned char *w);
unsigned char *subWord(unsigned char *w);
unsigned char *Cipher(unsigned char *in, unsigned char **w);
void subBytes(unsigned char **state);
void shiftRows(unsigned char **state);
void AddRoundKey(unsigned char **state, unsigned char **w, short index);
unsigned char **StateCreation(unsigned char *in);