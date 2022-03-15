#include <stdint.h>
#include <stdlib.h>
#include "hal.h"
#include "simpleserial.h"

#define QINV -3327 // q^-1 mod 2^16
#define KYBER_Q 3329

int16_t a[2] = {0, 0};
//typedef signed char int8_t;
//typedef signed short int int16_t;
//typedef signed int int32_t;

int16_t montgomery_reduce(int32_t a)
{
    int16_t t;

    t = (int16_t)a*QINV;
    t = (a - (int32_t)t*KYBER_Q) >> 16;
    return t;
}

static int16_t fqmul(int16_t a, int16_t b) {
    return montgomery_reduce((int32_t)a*b);
}

void basemul(int16_t r[2], const int16_t a[2], const int16_t b[2], int16_t zeta)
{
    // trigger_high();
    r[0]  = fqmul(a[1], b[1]);
    // trigger_low();
    r[0]  = fqmul(r[0], zeta);
    r[0] += fqmul(a[0], b[0]);
    r[1]  = fqmul(a[0], b[1]);
    r[1] += fqmul(a[1], b[0]);
}

uint8_t set_key(uint8_t* text_in_buf, uint8_t len)
{
    uint8_t temp[4] = {0,};
    a[0] = (((int16_t)text_in_buf[0]) << 8) + ((int16_t)(text_in_buf[1]));
    a[1] = (((int16_t)text_in_buf[2]) << 8) + ((int16_t)(text_in_buf[3]));
    temp[1] = (uint8_t)a[0]&0xFF;
    temp[0] = (uint8_t)(a[0] >> 8) & 0xFF;
    temp[3] = (uint8_t)a[1]&0xFF;
    temp[2] = (uint8_t)(a[1] >> 8) & 0xFF;
    simpleserial_put('r', 4, temp);

	return 0x00;
}

uint8_t check_key(uint8_t* text_in_buf, uint8_t len)
{
    uint8_t temp[4];
    temp[1] = (uint8_t)a[0]&0xFF;
    temp[0] = (uint8_t)(a[0] >> 8) & 0xFF;
    temp[3] = (uint8_t)a[1]&0xFF;
    temp[2] = (uint8_t)(a[1] >> 8) & 0xFF;
    simpleserial_put('r', 4, temp);

	return 0x00;
}


uint8_t crypto_main(uint8_t* text_in_buf, uint8_t len)
{

    // 4바이트 값을 넣어줘야 함
    int16_t b[2];
    int16_t r[2];
    int16_t zeta = -1103;
    int8_t check[4];

    for(int i=0;i<4;i++){
        check[i] = text_in_buf[i];
    }

    b[0] = (((int16_t)text_in_buf[0]) << 8) | ((int16_t)(text_in_buf[1]));
    b[1] = (((int16_t)text_in_buf[2]) << 8) | ((int16_t)(text_in_buf[3]));


    trigger_high();
    basemul(r, a, b, zeta);
    trigger_low();

    simpleserial_put('r', 4, check);

	return 0x00;
}

int main(void)
{
    platform_init();
	init_uart();
	trigger_setup();

    //int16_t r[2], const int16_t a[2], const int16_t b[2], int16_t zeta
 	/* Uncomment this to get a HELLO message for debug */
	/*
	putch('h');
	putch('e');
	putch('l');
	putch('l');
	putch('o');
	putch('\n');
	*/

	simpleserial_init();  // 'v': check_version, 'y': ss_num_commands, 'w': ss_get_commands
	
    //
    simpleserial_addcmd('p', 4, crypto_main);
    simpleserial_addcmd('k', 4, set_key);
    simpleserial_addcmd('c', 0, check_key);

	while(1)
		simpleserial_get();
}
