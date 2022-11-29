#include<stdlib.h>
#include<stdio.h>

# define Nb 4 // Block size

/* AES 128 parameters */
// # define Nk 4 // Key Length for 128
// # define Nr 10 // Number of rounds for 128

/* AES 192 parameters */
// # define Nk 6 // Key Length for 192
// # define Nr 12 // Number of rounds for 192

/* AES 256 parameters */
# define Nk 8 // Key Length for 256
# define Nr 14 // Number of rounds for 256

// Main AES Cipher function
unsigned char *AES_Cipher(unsigned char *in, unsigned char *key);

// Word manipulation functions and macros
#define copy(A,B) for(int it = 0; it < 4; it++) A[it] = B[it]
#define XOR(R,A,B) for(int it = 0; it < Nb; it++) R[it] = A[it]^B[it]
unsigned char *word(unsigned char w0, unsigned char w1, unsigned char w2, unsigned char w3);
unsigned char *rotWord(unsigned char *w);
unsigned char *subWord(unsigned char *w);

// State manipulation functions
unsigned char **StateCreation(unsigned char *in);
unsigned char *outputCreation(unsigned char **state);

// Key related functions
unsigned char **keyScheduleCreation(void);
void keyExpansion(unsigned char *key, unsigned char **word);

// Cipher related functions
unsigned char *Cipher(unsigned char *in, unsigned char **w);
void subBytes(unsigned char **state);
void shiftRows(unsigned char **state);
void mixColumns(unsigned char **state);
void mixColumn(unsigned char *column);
void AddRoundKey(unsigned char **state, unsigned char **w, short index);

// Galois field multiplication
unsigned char galois_multiplication(unsigned char a, unsigned char b);

// Test purpose functions 
void show_keys(unsigned char **w);
void show_input(unsigned char *in);
void show_output(unsigned char *out);
void show_state(unsigned char **state);
void show_key(unsigned char *key);