#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include "randombytes.h"
#ifdef _WIN32

#include <windows.h>
#include <wincrypt.h>
#include <stdio.h>

#else
#include <fcntl.h>
#include <errno.h>
#ifdef __linux__
#define _GNU_SOURCE
#include <unistd.h>
#include <sys/syscall.h>
#else
#include <unistd.h>
#endif
#endif

#ifdef _WIN32

void randombytes(uint8_t *out, size_t outlen) {
    srand(time(NULL));
    uint8_t len[32];
    for(int i=0; i<outlen; i++) {
        len[i]=rand()%256;
        out[i]=len[i];
    }

/*
    HCRYPTPROV ctx;
    size_t len;
    if (!CryptAcquireContext(&ctx, NULL, NULL, PROV_RSA_FULL, CRYPT_VERIFYCONTEXT))
        abort();

    while (outlen > 0) {
        len = (outlen > 1048576) ? 1048576 : outlen;
        if (!CryptGenRandom(ctx, len, (BYTE *) out))
            abort();
        out += len;
        outlen -= len;
    }
    printf("out : ");
    for (int i = 0; i < 32; i++) {
        printf("%X ", *(out+i));
    }
    printf("\n");

    if (!CryptReleaseContext(ctx, 0))
        abort();
*/
}

#elif defined(__linux__) && defined(SYS_getrandom)
void randombytes(uint8_t *out, size_t outlen) {
  ssize_t ret;

  while(outlen > 0) {
    ret = syscall(SYS_getrandom, out, outlen, 0);
    if(ret == -1 && errno == EINTR)
      continue;
    else if(ret == -1)
      abort();

    out += ret;
    outlen -= ret;
  }
}
#else
void randombytes(uint8_t *out, size_t outlen) {
  static int fd = -1;
  ssize_t ret;

  while(fd == -1) {
    fd = open("/dev/urandom", O_RDONLY);
    if(fd == -1 && errno == EINTR)
      continue;
    else if(fd == -1)
      abort();
  }

  while(outlen > 0) {
    ret = read(fd, out, outlen);
    if(ret == -1 && errno == EINTR)
      continue;
    else if(ret == -1)
      abort();

    out += ret;
    outlen -= ret;
  }
}
#endif
