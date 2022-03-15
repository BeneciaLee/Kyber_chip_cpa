cmake_minimum_required(VERSION 3.16.3)
project(test_kyber)

set(SRC_FILES test_kyber.c kem.c randombytes.c indcpa.c verify.c ntt.c poly.c polyvec.c reduce.c cbd.c fips202.c sha512.c sha256.c symmetric-shake.c symmetric-aes.c aes256ctr.c)
set(KYBER_NAME test_kyber)
add_executable(${KYBER_NAME} ${SRC_FILES})