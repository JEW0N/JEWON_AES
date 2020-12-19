#ifndef _aes_
#define _aes_

#define KEY_SIZE_128 16
#define KEY_SIZE_192 24
#define KEY_SIZE_256 32

#define Nr_128 10
#define Nr_192 12
#define Nr_256 14


//unsigned int x_time(unsigned int x);// Mixcolumns 연산에 사용

//void RotWord(unsigned int* temp, unsigned int* word[]);
//void SubWord(unsigned int* temp, unsigned int* sbox);
void AES_128_KeyExpansion(unsigned* key, unsigned int* roundkey);


//void AddRoundKey(unsigned int text[], unsigned int roundkey[], unsigned int round);
//void SubBytes(unsigned int plaintext[], unsigned int s_box[]);
//void ShiftRows(unsigned int* plaintext);
//void MixColumns(unsigned int* plaintext);
void AES_128_Encryption(unsigned int roundkey, unsigned int* plaintext, unsigned int* ciphertext);

//void InvShiftRows(unsigned int* ciphertext);
//void InvSubBytes(unsigned int ciphertext[], unsigned int inv_s_box[]);
//void InvMixColumns(unsigned int* plaintext);

void AES_128_Decryption(unsigned int roundkey, unsigned int* ciphertext, unsigned int* plaintext);


#endif jewon_AES