#include <stdio.h>
#include <time.h>;
#include "aes.h"


void main() {

    clock_t start, end;

    unsigned int key[KEY_SIZE_128] = {
        0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6, 0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c
        //  0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f
    };
    unsigned int plaintext[KEY_SIZE_128] = {
        //0x32, 0x43, 0xf6, 0xa8, 0x88, 0x5a, 0x30, 0x8d, 0x31, 0x31, 0x98, 0xa2, 0xe0, 0x37, 0x07, 0x34
        0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff

    };

    unsigned int ciphertext[KEY_SIZE_128] = { 0, };

    unsigned int rk[10000] = { 0, }; // key schedule 연산에 사용되는 임시변수

    start = clock();

    AES_128_KeyExpansion(key, rk);

   for (int i = 0; i < Nr_128 + 1; i++) {
       printf("#%02d round key: ", i + 1);
       for (int j = 0; j < KEY_SIZE_128; j++)
           printf("%02x ", rk[i * KEY_SIZE_128 + j]);
       printf("\n");
   }
   printf("\n");


    AES_128_Encryption(rk, plaintext, ciphertext);

    printf("ciphertext:\t");
    for (int j = 0; j < KEY_SIZE_128; j++) // 테스트용
        printf("%02x ", ciphertext[j]);
    printf("\n\n");

    AES_128_Decryption(rk, ciphertext, plaintext);

    printf("plaintext:\t");
    for (int j = 0; j < KEY_SIZE_128; j++) // 테스트용
        printf("%02x ", ciphertext[j]);
    printf("\n");

    end = clock();


    printf("AES-128 암호화 속도 : %.f s\n", (double)(end - start)); //초 단위 얼마나 걸렸는지 보여줌

}
