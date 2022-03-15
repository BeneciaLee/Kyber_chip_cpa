#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include "kem.h"
#include "randombytes.h"


FILE *fp,*fp3, *fp2, *fp1;
static int kyber512_keypair(uint8_t *pk, uint8_t *sk) {
    crypto_kem_keypair(pk, sk);
}

static int kyber512_enc(uint8_t *ct, uint8_t *key_b, const uint8_t *pk) {
    crypto_kem_enc(ct, key_b, pk);
}

static int kyber512_dec(uint8_t *key_a, uint8_t *ct, const uint8_t *sk) {
    crypto_kem_dec(key_a, ct, sk);
}

void kyber512_dec_check(int16_t* a, uint8_t *key_a, uint8_t *ct, const uint8_t *sk) {
    crypto_kem_dec_check(a, key_a, ct, sk);
}

int main(void) {
    uint8_t pk[CRYPTO_PUBLICKEYBYTES];
    uint8_t sk[CRYPTO_SECRETKEYBYTES];
    uint8_t ct[CRYPTO_CIPHERTEXTBYTES];
    uint8_t key_a[CRYPTO_BYTES];
    uint8_t key_b[CRYPTO_BYTES];
    uint8_t msg[2 * KYBER_SYMBYTES];
    /* Will contain key, coins */
    uint8_t kr[2 * KYBER_SYMBYTES];
    int16_t aaa[5] = {0,};
    char space;
    int abcd=0;
    int NTESTS=10;


    if(abcd==0) {
        fp1 = fopen("msg.txt", "w");
        for (int i = 0; i < NTESTS; i++) {
            randombytes(msg, KYBER_SYMBYTES);
            for (int j = 0; j < KYBER_SYMBYTES; j++) {
                fprintf(fp1, "%02x ", msg[j]);
            }
            fputc('\n', fp1);
            fputc('\n', fp1);
        }
        fclose(fp1);

        fp2 = fopen("sk.txt", "w");
        crypto_kem_keypair(pk, sk);
        for (int i = 0; i < CRYPTO_SECRETKEYBYTES; i++) {
            fprintf(fp2, "%02x ", sk[i]);

        }
        fclose(fp2);

        fp = fopen("ct.txt", "w");
        for (int i = 0; i < NTESTS; i++) {
            crypto_kem_enc(ct, key_b, pk);
            printf("Ct : ");

            for (int j = 0; j < CRYPTO_CIPHERTEXTBYTES; j++) {
                printf("%02x ", ct[j]);
                fprintf(fp, "%02x ", ct[j]);

            }
            fputc('\n', fp);
            fputc('\n', fp);
            printf("\n\n");

        }
        fclose(fp);
    }
    else {
        fp1 = fopen("msg.txt", "r");
        fp2 = fopen("ct.txt", "r");
        fp = fopen("a_b_zeta.txt", "w");

//        NTESTS = 1;

        for (int k = 0; k < NTESTS; k++) {
            if (k == 0) {
//                printf("sk: ");
                fp3 = fopen("sk.txt", "r");
                for (int i = 0; i < CRYPTO_SECRETKEYBYTES; i++) {
                    fscanf(fp3, "%02x ", &sk[i]);
//                    printf("%02x ", sk[i]);
                }
//                printf("\n\n");
                fclose(fp3);
            }

//            printf("msg: ");

            for (int i = 0; i < KYBER_SYMBYTES; i++) {
                fscanf(fp1, "%02x ", &msg[i]);
//                printf("%02x ", msg[i]);
            }
//            printf("\n\n");

//            printf("ct: ");
            for (int i = 0; i < CRYPTO_CIPHERTEXTBYTES; i++) {
                fscanf(fp2, "%02x ", &ct[i]);
//                printf("%02x ", ct[i]);
            }
//            printf("\n\n");

            printf("\n\n");

            // 1352 2926 337 -485
            kyber512_dec(key_a, ct, sk);
//            kyber512_dec_check(aaa, key_a, ct, sk);
//            printf("\n\n");
            //
            printf("%d %d\n", aaa[2], aaa[3]);
            printf("%d \n",aaa[4]);
            for(int i=0;i<5;i++) {
                printf("%02x ", ((aaa[i] >> 8)) & 0xFF);
                printf("%02x ", ((aaa[i])) & 0xFF);

                fprintf(fp, "%02x ", ((aaa[i] >> 8)) & 0xFF);
                fprintf(fp, "%02x ", ((aaa[i])) & 0xFF);
            }
            fputc('\n', fp);

        }
        fclose(fp1);
        fclose(fp2);

    }


    // key_a 32
    // sk : 1632
    // ct : 768
//    int


//    kyber512_dec_check(aaa, key_a, ct, sk);
//    kyber512_dec(key_a, ct, sk);
//
//    for(int i=0;i<4;i++){
//        printf("%d ", aaa[i]);
//    }

    printf("\n");
    printf("CRYPTO_SECRETKEYBYTES:  %d\n", CRYPTO_SECRETKEYBYTES);
    printf("CRYPTO_PUBLICKEYBYTES:  %d\n", CRYPTO_PUBLICKEYBYTES);
    printf("CRYPTO_CIPHERTEXTBYTES: %d\n", CRYPTO_CIPHERTEXTBYTES);

    return 0;
}
