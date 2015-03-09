/* Copyright (C) 1995-1998 Eric Young (eay@cryptsoft.com)
 * All rights reserved.
 *
 * This package is an SSL implementation written
 * by Eric Young (eay@cryptsoft.com).
 * The implementation was written so as to conform with Netscapes SSL.
 * 
 * This library is free for commercial and non-commercial use as long as
 * the following conditions are aheared to.  The following conditions
 * apply to all code found in this distribution, be it the RC4, RSA,
 * lhash, DES, etc., code; not just the SSL code.  The SSL documentation
 * included with this distribution is covered by the same copyright terms
 * except that the holder is Tim Hudson (tjh@cryptsoft.com).
 * 
 * Copyright remains Eric Young's, and as such any Copyright notices in
 * the code are not to be removed.
 * If this package is used in a product, Eric Young should be given attribution
 * as the author of the parts of the library used.
 * This can be in the form of a textual message at program startup or
 * in documentation (online or textual) provided with the package.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *    "This product includes cryptographic software written by
 *     Eric Young (eay@cryptsoft.com)"
 *    The word 'cryptographic' can be left out if the rouines from the library
 *    being used are not cryptographic related :-).
 * 4. If you include any Windows specific code (or a derivative thereof) from 
 *    the apps directory (application code) you must include an acknowledgement:
 *    "This product includes software written by Tim Hudson (tjh@cryptsoft.com)"
 * 
 * THIS SOFTWARE IS PROVIDED BY ERIC YOUNG ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 * 
 * The licence and distribution terms for any publically available version or
 * derivative of this code cannot be changed.  i.e. this code cannot simply be
 * copied and put under another distribution licence
 * [including the GNU Public Licence.]
 */
#include "ssl_tests.h"
#include <openssl/e_os2.h>
#ifdef OPENSSL_SYS_WINDOWS
#if defined(OPENSSL_SYS_WIN32) || defined(OPENSSL_SYS_WIN16) || defined(OPENSSL_SYS_WINDOWS)
#ifndef OPENSSL_SYS_MSDOS
#define OPENSSL_SYS_MSDOS
#endif
#endif

#ifndef OPENSSL_SYS_MSDOS
#if !defined(OPENSSL_SYS_VMS) || defined(OPENSSL_SYS_VMS_DECC)
#include OPENSSL_UNISTD
#endif
#else
#include <io.h>
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#endif

#ifdef OPENSSL_NO_DES
int ssl_test_des(int argc, char *argv[])
{
    TINYCLR_SSL_PRINTF("No DES support\n");
    return(0);
}
#else
#include <openssl/des.h>

#define crypt(c,s) (DES_crypt((c),(s)))

/* tisk tisk - the test keys don't all have odd parity :-( */
/* test data */
#define NUM_TESTS 34
static unsigned char key_data[NUM_TESTS][8]={
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF},
	{0x30,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11},
	{0x01,0x23,0x45,0x67,0x89,0xAB,0xCD,0xEF},
	{0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0xFE,0xDC,0xBA,0x98,0x76,0x54,0x32,0x10},
	{0x7C,0xA1,0x10,0x45,0x4A,0x1A,0x6E,0x57},
	{0x01,0x31,0xD9,0x61,0x9D,0xC1,0x37,0x6E},
	{0x07,0xA1,0x13,0x3E,0x4A,0x0B,0x26,0x86},
	{0x38,0x49,0x67,0x4C,0x26,0x02,0x31,0x9E},
	{0x04,0xB9,0x15,0xBA,0x43,0xFE,0xB5,0xB6},
	{0x01,0x13,0xB9,0x70,0xFD,0x34,0xF2,0xCE},
	{0x01,0x70,0xF1,0x75,0x46,0x8F,0xB5,0xE6},
	{0x43,0x29,0x7F,0xAD,0x38,0xE3,0x73,0xFE},
	{0x07,0xA7,0x13,0x70,0x45,0xDA,0x2A,0x16},
	{0x04,0x68,0x91,0x04,0xC2,0xFD,0x3B,0x2F},
	{0x37,0xD0,0x6B,0xB5,0x16,0xCB,0x75,0x46},
	{0x1F,0x08,0x26,0x0D,0x1A,0xC2,0x46,0x5E},
	{0x58,0x40,0x23,0x64,0x1A,0xBA,0x61,0x76},
	{0x02,0x58,0x16,0x16,0x46,0x29,0xB0,0x07},
	{0x49,0x79,0x3E,0xBC,0x79,0xB3,0x25,0x8F},
	{0x4F,0xB0,0x5E,0x15,0x15,0xAB,0x73,0xA7},
	{0x49,0xE9,0x5D,0x6D,0x4C,0xA2,0x29,0xBF},
	{0x01,0x83,0x10,0xDC,0x40,0x9B,0x26,0xD6},
	{0x1C,0x58,0x7F,0x1C,0x13,0x92,0x4F,0xEF},
	{0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01},
	{0x1F,0x1F,0x1F,0x1F,0x0E,0x0E,0x0E,0x0E},
	{0xE0,0xFE,0xE0,0xFE,0xF1,0xFE,0xF1,0xFE},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF},
	{0x01,0x23,0x45,0x67,0x89,0xAB,0xCD,0xEF},
	{0xFE,0xDC,0xBA,0x98,0x76,0x54,0x32,0x10}};

static unsigned char plain_data[NUM_TESTS][8]={
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF},
	{0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x01},
	{0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11},
	{0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11},
	{0x01,0x23,0x45,0x67,0x89,0xAB,0xCD,0xEF},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x01,0x23,0x45,0x67,0x89,0xAB,0xCD,0xEF},
	{0x01,0xA1,0xD6,0xD0,0x39,0x77,0x67,0x42},
	{0x5C,0xD5,0x4C,0xA8,0x3D,0xEF,0x57,0xDA},
	{0x02,0x48,0xD4,0x38,0x06,0xF6,0x71,0x72},
	{0x51,0x45,0x4B,0x58,0x2D,0xDF,0x44,0x0A},
	{0x42,0xFD,0x44,0x30,0x59,0x57,0x7F,0xA2},
	{0x05,0x9B,0x5E,0x08,0x51,0xCF,0x14,0x3A},
	{0x07,0x56,0xD8,0xE0,0x77,0x47,0x61,0xD2},
	{0x76,0x25,0x14,0xB8,0x29,0xBF,0x48,0x6A},
	{0x3B,0xDD,0x11,0x90,0x49,0x37,0x28,0x02},
	{0x26,0x95,0x5F,0x68,0x35,0xAF,0x60,0x9A},
	{0x16,0x4D,0x5E,0x40,0x4F,0x27,0x52,0x32},
	{0x6B,0x05,0x6E,0x18,0x75,0x9F,0x5C,0xCA},
	{0x00,0x4B,0xD6,0xEF,0x09,0x17,0x60,0x62},
	{0x48,0x0D,0x39,0x00,0x6E,0xE7,0x62,0xF2},
	{0x43,0x75,0x40,0xC8,0x69,0x8F,0x3C,0xFA},
	{0x07,0x2D,0x43,0xA0,0x77,0x07,0x52,0x92},
	{0x02,0xFE,0x55,0x77,0x81,0x17,0xF1,0x2A},
	{0x1D,0x9D,0x5C,0x50,0x18,0xF7,0x28,0xC2},
	{0x30,0x55,0x32,0x28,0x6D,0x6F,0x29,0x5A},
	{0x01,0x23,0x45,0x67,0x89,0xAB,0xCD,0xEF},
	{0x01,0x23,0x45,0x67,0x89,0xAB,0xCD,0xEF},
	{0x01,0x23,0x45,0x67,0x89,0xAB,0xCD,0xEF},
	{0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF}};

static unsigned char cipher_data[NUM_TESTS][8]={
	{0x8C,0xA6,0x4D,0xE9,0xC1,0xB1,0x23,0xA7},
	{0x73,0x59,0xB2,0x16,0x3E,0x4E,0xDC,0x58},
	{0x95,0x8E,0x6E,0x62,0x7A,0x05,0x55,0x7B},
	{0xF4,0x03,0x79,0xAB,0x9E,0x0E,0xC5,0x33},
	{0x17,0x66,0x8D,0xFC,0x72,0x92,0x53,0x2D},
	{0x8A,0x5A,0xE1,0xF8,0x1A,0xB8,0xF2,0xDD},
	{0x8C,0xA6,0x4D,0xE9,0xC1,0xB1,0x23,0xA7},
	{0xED,0x39,0xD9,0x50,0xFA,0x74,0xBC,0xC4},
	{0x69,0x0F,0x5B,0x0D,0x9A,0x26,0x93,0x9B},
	{0x7A,0x38,0x9D,0x10,0x35,0x4B,0xD2,0x71},
	{0x86,0x8E,0xBB,0x51,0xCA,0xB4,0x59,0x9A},
	{0x71,0x78,0x87,0x6E,0x01,0xF1,0x9B,0x2A},
	{0xAF,0x37,0xFB,0x42,0x1F,0x8C,0x40,0x95},
	{0x86,0xA5,0x60,0xF1,0x0E,0xC6,0xD8,0x5B},
	{0x0C,0xD3,0xDA,0x02,0x00,0x21,0xDC,0x09},
	{0xEA,0x67,0x6B,0x2C,0xB7,0xDB,0x2B,0x7A},
	{0xDF,0xD6,0x4A,0x81,0x5C,0xAF,0x1A,0x0F},
	{0x5C,0x51,0x3C,0x9C,0x48,0x86,0xC0,0x88},
	{0x0A,0x2A,0xEE,0xAE,0x3F,0xF4,0xAB,0x77},
	{0xEF,0x1B,0xF0,0x3E,0x5D,0xFA,0x57,0x5A},
	{0x88,0xBF,0x0D,0xB6,0xD7,0x0D,0xEE,0x56},
	{0xA1,0xF9,0x91,0x55,0x41,0x02,0x0B,0x56},
	{0x6F,0xBF,0x1C,0xAF,0xCF,0xFD,0x05,0x56},
	{0x2F,0x22,0xE4,0x9B,0xAB,0x7C,0xA1,0xAC},
	{0x5A,0x6B,0x61,0x2C,0xC2,0x6C,0xCE,0x4A},
	{0x5F,0x4C,0x03,0x8E,0xD1,0x2B,0x2E,0x41},
	{0x63,0xFA,0xC0,0xD0,0x34,0xD9,0xF7,0x93},
	{0x61,0x7B,0x3A,0x0C,0xE8,0xF0,0x71,0x00},
	{0xDB,0x95,0x86,0x05,0xF8,0xC8,0xC6,0x06},
	{0xED,0xBF,0xD1,0xC6,0x6C,0x29,0xCC,0xC7},
	{0x35,0x55,0x50,0xB2,0x15,0x0E,0x24,0x51},
	{0xCA,0xAA,0xAF,0x4D,0xEA,0xF1,0xDB,0xAE},
	{0xD5,0xD4,0x4F,0xF7,0x20,0x68,0x3D,0x0D},
	{0x2A,0x2B,0xB0,0x08,0xDF,0x97,0xC2,0xF2}};

static unsigned char cipher_ecb2[NUM_TESTS-1][8]={
	{0x92,0x95,0xB5,0x9B,0xB3,0x84,0x73,0x6E},
	{0x19,0x9E,0x9D,0x6D,0xF3,0x9A,0xA8,0x16},
	{0x2A,0x4B,0x4D,0x24,0x52,0x43,0x84,0x27},
	{0x35,0x84,0x3C,0x01,0x9D,0x18,0xC5,0xB6},
	{0x4A,0x5B,0x2F,0x42,0xAA,0x77,0x19,0x25},
	{0xA0,0x6B,0xA9,0xB8,0xCA,0x5B,0x17,0x8A},
	{0xAB,0x9D,0xB7,0xFB,0xED,0x95,0xF2,0x74},
	{0x3D,0x25,0x6C,0x23,0xA7,0x25,0x2F,0xD6},
	{0xB7,0x6F,0xAB,0x4F,0xBD,0xBD,0xB7,0x67},
	{0x8F,0x68,0x27,0xD6,0x9C,0xF4,0x1A,0x10},
	{0x82,0x57,0xA1,0xD6,0x50,0x5E,0x81,0x85},
	{0xA2,0x0F,0x0A,0xCD,0x80,0x89,0x7D,0xFA},
	{0xCD,0x2A,0x53,0x3A,0xDB,0x0D,0x7E,0xF3},
	{0xD2,0xC2,0xBE,0x27,0xE8,0x1B,0x68,0xE3},
	{0xE9,0x24,0xCF,0x4F,0x89,0x3C,0x5B,0x0A},
	{0xA7,0x18,0xC3,0x9F,0xFA,0x9F,0xD7,0x69},
	{0x77,0x2C,0x79,0xB1,0xD2,0x31,0x7E,0xB1},
	{0x49,0xAB,0x92,0x7F,0xD0,0x22,0x00,0xB7},
	{0xCE,0x1C,0x6C,0x7D,0x85,0xE3,0x4A,0x6F},
	{0xBE,0x91,0xD6,0xE1,0x27,0xB2,0xE9,0x87},
	{0x70,0x28,0xAE,0x8F,0xD1,0xF5,0x74,0x1A},
	{0xAA,0x37,0x80,0xBB,0xF3,0x22,0x1D,0xDE},
	{0xA6,0xC4,0xD2,0x5E,0x28,0x93,0xAC,0xB3},
	{0x22,0x07,0x81,0x5A,0xE4,0xB7,0x1A,0xAD},
	{0xDC,0xCE,0x05,0xE7,0x07,0xBD,0xF5,0x84},
	{0x26,0x1D,0x39,0x2C,0xB3,0xBA,0xA5,0x85},
	{0xB4,0xF7,0x0F,0x72,0xFB,0x04,0xF0,0xDC},
	{0x95,0xBA,0xA9,0x4E,0x87,0x36,0xF2,0x89},
	{0xD4,0x07,0x3A,0xF1,0x5A,0x17,0x82,0x0E},
	{0xEF,0x6F,0xAF,0xA7,0x66,0x1A,0x7E,0x89},
	{0xC1,0x97,0xF5,0x58,0x74,0x8A,0x20,0xE7},
	{0x43,0x34,0xCF,0xDA,0x22,0xC4,0x86,0xC8},
	{0x08,0xD7,0xB4,0xFB,0x62,0x9D,0x08,0x85}};

static unsigned char cbc_key [8]={0x01,0x23,0x45,0x67,0x89,0xab,0xcd,0xef};
static unsigned char cbc2_key[8]={0xf1,0xe0,0xd3,0xc2,0xb5,0xa4,0x97,0x86};
static unsigned char cbc3_key[8]={0xfe,0xdc,0xba,0x98,0x76,0x54,0x32,0x10};
static unsigned char cbc_iv  [8]={0xfe,0xdc,0xba,0x98,0x76,0x54,0x32,0x10};
/* Changed the following text constant to binary so it will work on ebcdic
 * machines :-) */
/* static char cbc_data[40]="7654321 Now is the time for \0001"; */
static unsigned char cbc_data[40]={
	0x37,0x36,0x35,0x34,0x33,0x32,0x31,0x20,
	0x4E,0x6F,0x77,0x20,0x69,0x73,0x20,0x74,
	0x68,0x65,0x20,0x74,0x69,0x6D,0x65,0x20,
	0x66,0x6F,0x72,0x20,0x00,0x31,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	};

static unsigned char cbc_ok[32]={
	0xcc,0xd1,0x73,0xff,0xab,0x20,0x39,0xf4,
	0xac,0xd8,0xae,0xfd,0xdf,0xd8,0xa1,0xeb,
	0x46,0x8e,0x91,0x15,0x78,0x88,0xba,0x68,
	0x1d,0x26,0x93,0x97,0xf7,0xfe,0x62,0xb4};

#ifdef SCREW_THE_PARITY
#error "SCREW_THE_PARITY is not ment to be defined."
#error "Original vectors are preserved for reference only."
static unsigned char cbc2_key[8]={0xf0,0xe1,0xd2,0xc3,0xb4,0xa5,0x96,0x87};
static unsigned char xcbc_ok[32]={
	0x86,0x74,0x81,0x0D,0x61,0xA4,0xA5,0x48,
	0xB9,0x93,0x03,0xE1,0xB8,0xBB,0xBD,0xBD,
	0x64,0x30,0x0B,0xB9,0x06,0x65,0x81,0x76,
	0x04,0x1D,0x77,0x62,0x17,0xCA,0x2B,0xD2,
	};
#else
static unsigned char xcbc_ok[32]={
	0x84,0x6B,0x29,0x14,0x85,0x1E,0x9A,0x29,
	0x54,0x73,0x2F,0x8A,0xA0,0xA6,0x11,0xC1,
	0x15,0xCD,0xC2,0xD7,0x95,0x1B,0x10,0x53,
	0xA6,0x3C,0x5E,0x03,0xB2,0x1A,0xA3,0xC4,
	};
#endif

static unsigned char cbc3_ok[32]={
	0x3F,0xE3,0x01,0xC9,0x62,0xAC,0x01,0xD0,
	0x22,0x13,0x76,0x3C,0x1C,0xBD,0x4C,0xDC,
	0x79,0x96,0x57,0xC0,0x64,0xEC,0xF5,0xD4,
	0x1C,0x67,0x38,0x12,0xCF,0xDE,0x96,0x75};

static unsigned char pcbc_ok[32]={
	0xcc,0xd1,0x73,0xff,0xab,0x20,0x39,0xf4,
	0x6d,0xec,0xb4,0x70,0xa0,0xe5,0x6b,0x15,
	0xae,0xa6,0xbf,0x61,0xed,0x7d,0x9c,0x9f,
	0xf7,0x17,0x46,0x3b,0x8a,0xb3,0xcc,0x88};

static unsigned char cfb_key[8]={0x01,0x23,0x45,0x67,0x89,0xab,0xcd,0xef};
static unsigned char cfb_iv[8]={0x12,0x34,0x56,0x78,0x90,0xab,0xcd,0xef};
static unsigned char cfb_buf1[40],cfb_buf2[40],cfb_tmp[8];
static unsigned char plain[24]=
	{
	0x4e,0x6f,0x77,0x20,0x69,0x73,
	0x20,0x74,0x68,0x65,0x20,0x74,
	0x69,0x6d,0x65,0x20,0x66,0x6f,
	0x72,0x20,0x61,0x6c,0x6c,0x20
	};
static unsigned char cfb_cipher8[24]= {
	0xf3,0x1f,0xda,0x07,0x01,0x14, 0x62,0xee,0x18,0x7f,0x43,0xd8,
	0x0a,0x7c,0xd9,0xb5,0xb0,0xd2, 0x90,0xda,0x6e,0x5b,0x9a,0x87 };
static unsigned char cfb_cipher16[24]={
	0xF3,0x09,0x87,0x87,0x7F,0x57, 0xF7,0x3C,0x36,0xB6,0xDB,0x70,
	0xD8,0xD5,0x34,0x19,0xD3,0x86, 0xB2,0x23,0xB7,0xB2,0xAD,0x1B };
static unsigned char cfb_cipher32[24]={
	0xF3,0x09,0x62,0x49,0xA4,0xDF, 0xA4,0x9F,0x33,0xDC,0x7B,0xAD,
	0x4C,0xC8,0x9F,0x64,0xE4,0x53, 0xE5,0xEC,0x67,0x20,0xDA,0xB6 };
static unsigned char cfb_cipher48[24]={
	0xF3,0x09,0x62,0x49,0xC7,0xF4, 0x30,0xB5,0x15,0xEC,0xBB,0x85,
	0x97,0x5A,0x13,0x8C,0x68,0x60, 0xE2,0x38,0x34,0x3C,0xDC,0x1F };
static unsigned char cfb_cipher64[24]={
	0xF3,0x09,0x62,0x49,0xC7,0xF4, 0x6E,0x51,0xA6,0x9E,0x83,0x9B,
	0x1A,0x92,0xF7,0x84,0x03,0x46, 0x71,0x33,0x89,0x8E,0xA6,0x22 };

static unsigned char ofb_key[8]={0x01,0x23,0x45,0x67,0x89,0xab,0xcd,0xef};
static unsigned char ofb_iv[8]={0x12,0x34,0x56,0x78,0x90,0xab,0xcd,0xef};
static unsigned char ofb_buf1[24],ofb_buf2[24],ofb_tmp[8];
static unsigned char ofb_cipher[24]=
	{
	0xf3,0x09,0x62,0x49,0xc7,0xf4,0x6e,0x51,
	0x35,0xf2,0x4a,0x24,0x2e,0xeb,0x3d,0x3f,
	0x3d,0x6d,0x5b,0xe3,0x25,0x5a,0xf8,0xc3
	};

#if 0
static DES_LONG cbc_cksum_ret=0xB462FEF7L;
#else
static DES_LONG cbc_cksum_ret=0xF7FE62B4L;
#endif
static unsigned char cbc_cksum_data[8]={0x1D,0x26,0x93,0x97,0xf7,0xfe,0x62,0xb4};

static char *pt(unsigned char *p);
static int cfb_test(int bits, unsigned char *cfb_cipher);
static int cfb64_test(unsigned char *cfb_cipher);
static int ede_cfb64_test(unsigned char *cfb_cipher);
int ssl_test_des(int argc, char *argv[])
	{
	int j,err=0;
	unsigned int i;
	des_cblock in,out,outin,iv3,iv2;
	des_key_schedule ks,ks2,ks3;
	unsigned char cbc_in[40];
	unsigned char cbc_out[40];
	DES_LONG cs;
	unsigned char cret[8];
#ifdef _CRAY
        struct {
            int a:32;
            int b:32;
        } lqret[2];
#else
        DES_LONG lqret[4];
#endif
	int num;
	char *str;

#ifndef OPENSSL_NO_DESCBCM
	TINYCLR_SSL_PRINTF("Doing cbcm\n");
	if ((j=DES_set_key_checked(&cbc_key,&ks)) != 0)
		{
		TINYCLR_SSL_PRINTF("Key error %d\n",j);
		err=1;
		}
	if ((j=DES_set_key_checked(&cbc2_key,&ks2)) != 0)
		{
		TINYCLR_SSL_PRINTF("Key error %d\n",j);
		err=1;
		}
	if ((j=DES_set_key_checked(&cbc3_key,&ks3)) != 0)
		{
		TINYCLR_SSL_PRINTF("Key error %d\n",j);
		err=1;
		}
	TINYCLR_SSL_MEMSET(cbc_out,0,40);
	TINYCLR_SSL_MEMSET(cbc_in,0,40);
	i=TINYCLR_SSL_STRLEN((char *)cbc_data)+1;
	/* i=((i+7)/8)*8; */
	TINYCLR_SSL_MEMCPY(iv3,cbc_iv,sizeof(cbc_iv));
	TINYCLR_SSL_MEMSET(iv2,'\0',sizeof iv2);

	DES_ede3_cbcm_encrypt(cbc_data,cbc_out,16L,&ks,&ks2,&ks3,&iv3,&iv2,
			      DES_ENCRYPT);
	DES_ede3_cbcm_encrypt(&cbc_data[16],&cbc_out[16],i-16,&ks,&ks2,&ks3,
			      &iv3,&iv2,DES_ENCRYPT);
	/*	if (memcmp(cbc_out,cbc3_ok,
		(unsigned int)(TINYCLR_SSL_STRLEN((char *)cbc_data)+1+7)/8*8) != 0)
		{
		TINYCLR_SSL_PRINTF("des_ede3_cbc_encrypt encrypt error\n");
		err=1;
		}
	*/
	TINYCLR_SSL_MEMCPY(iv3,cbc_iv,sizeof(cbc_iv));
	TINYCLR_SSL_MEMSET(iv2,'\0',sizeof iv2);
	DES_ede3_cbcm_encrypt(cbc_out,cbc_in,i,&ks,&ks2,&ks3,&iv3,&iv2,DES_DECRYPT);
	if (TINYCLR_SSL_MEMCMP(cbc_in,cbc_data,TINYCLR_SSL_STRLEN((char *)cbc_data)+1) != 0)
		{
		unsigned int n;

		TINYCLR_SSL_PRINTF("des_ede3_cbcm_encrypt decrypt error\n");
		for(n=0 ; n < i ; ++n)
		    TINYCLR_SSL_PRINTF(" %02x",cbc_data[n]);
		TINYCLR_SSL_PRINTF("\n");
		for(n=0 ; n < i ; ++n)
		    TINYCLR_SSL_PRINTF(" %02x",cbc_in[n]);
		TINYCLR_SSL_PRINTF("\n");
		err=1;
		}
#endif

	TINYCLR_SSL_PRINTF("Doing ecb\n");
	for (i=0; i<NUM_TESTS; i++)
		{
		DES_set_key_unchecked(&key_data[i],&ks);
		TINYCLR_SSL_MEMCPY(in,plain_data[i],8);
		TINYCLR_SSL_MEMSET(out,0,8);
		TINYCLR_SSL_MEMSET(outin,0,8);
		des_ecb_encrypt(&in,&out,ks,DES_ENCRYPT);
		des_ecb_encrypt(&out,&outin,ks,DES_DECRYPT);

		if (TINYCLR_SSL_MEMCMP(out,cipher_data[i],8) != 0)
			{
			TINYCLR_SSL_PRINTF("Encryption error %2d\nk=%s p=%s o=%s act=%s\n",
				i+1,pt(key_data[i]),pt(in),pt(cipher_data[i]),
				pt(out));
			err=1;
			}
		if (TINYCLR_SSL_MEMCMP(in,outin,8) != 0)
			{
			TINYCLR_SSL_PRINTF("Decryption error %2d\nk=%s p=%s o=%s act=%s\n",
				i+1,pt(key_data[i]),pt(out),pt(in),pt(outin));
			err=1;
			}
		}

#ifndef LIBDES_LIT
	TINYCLR_SSL_PRINTF("Doing ede ecb\n");
	for (i=0; i<(NUM_TESTS-2); i++)
		{
		DES_set_key_unchecked(&key_data[i],&ks);
		DES_set_key_unchecked(&key_data[i+1],&ks2);
		DES_set_key_unchecked(&key_data[i+2],&ks3);
		TINYCLR_SSL_MEMCPY(in,plain_data[i],8);
		TINYCLR_SSL_MEMSET(out,0,8);
		TINYCLR_SSL_MEMSET(outin,0,8);
		des_ecb2_encrypt(&in,&out,ks,ks2,DES_ENCRYPT);
		des_ecb2_encrypt(&out,&outin,ks,ks2,DES_DECRYPT);

		if (TINYCLR_SSL_MEMCMP(out,cipher_ecb2[i],8) != 0)
			{
			TINYCLR_SSL_PRINTF("Encryption error %2d\nk=%s p=%s o=%s act=%s\n",
				i+1,pt(key_data[i]),pt(in),pt(cipher_ecb2[i]),
				pt(out));
			err=1;
			}
		if (TINYCLR_SSL_MEMCMP(in,outin,8) != 0)
			{
			TINYCLR_SSL_PRINTF("Decryption error %2d\nk=%s p=%s o=%s act=%s\n",
				i+1,pt(key_data[i]),pt(out),pt(in),pt(outin));
			err=1;
			}
		}
#endif

	TINYCLR_SSL_PRINTF("Doing cbc\n");
	if ((j=DES_set_key_checked(&cbc_key,&ks)) != 0)
		{
		TINYCLR_SSL_PRINTF("Key error %d\n",j);
		err=1;
		}
	TINYCLR_SSL_MEMSET(cbc_out,0,40);
	TINYCLR_SSL_MEMSET(cbc_in,0,40);
	TINYCLR_SSL_MEMCPY(iv3,cbc_iv,sizeof(cbc_iv));
	des_ncbc_encrypt(cbc_data,cbc_out,TINYCLR_SSL_STRLEN((char *)cbc_data)+1,ks,
			 &iv3,DES_ENCRYPT);
	if (TINYCLR_SSL_MEMCMP(cbc_out,cbc_ok,32) != 0)
		{
		TINYCLR_SSL_PRINTF("cbc_encrypt encrypt error\n");
		err=1;
		}

	TINYCLR_SSL_MEMCPY(iv3,cbc_iv,sizeof(cbc_iv));
	des_ncbc_encrypt(cbc_out,cbc_in,TINYCLR_SSL_STRLEN((char *)cbc_data)+1,ks,
			 &iv3,DES_DECRYPT);
	if (TINYCLR_SSL_MEMCMP(cbc_in,cbc_data,TINYCLR_SSL_STRLEN((char *)cbc_data)) != 0)
		{
		TINYCLR_SSL_PRINTF("cbc_encrypt decrypt error\n");
		err=1;
		}

#ifndef LIBDES_LIT
	TINYCLR_SSL_PRINTF("Doing desx cbc\n");
	if ((j=DES_set_key_checked(&cbc_key,&ks)) != 0)
		{
		TINYCLR_SSL_PRINTF("Key error %d\n",j);
		err=1;
		}
	TINYCLR_SSL_MEMSET(cbc_out,0,40);
	TINYCLR_SSL_MEMSET(cbc_in,0,40);
	TINYCLR_SSL_MEMCPY(iv3,cbc_iv,sizeof(cbc_iv));
	des_xcbc_encrypt(cbc_data,cbc_out,TINYCLR_SSL_STRLEN((char *)cbc_data)+1,ks,
			 &iv3,&cbc2_key,&cbc3_key, DES_ENCRYPT);
	if (TINYCLR_SSL_MEMCMP(cbc_out,xcbc_ok,32) != 0)
		{
		TINYCLR_SSL_PRINTF("des_xcbc_encrypt encrypt error\n");
		err=1;
		}
	TINYCLR_SSL_MEMCPY(iv3,cbc_iv,sizeof(cbc_iv));
	des_xcbc_encrypt(cbc_out,cbc_in,TINYCLR_SSL_STRLEN((char *)cbc_data)+1,ks,
			 &iv3,&cbc2_key,&cbc3_key, DES_DECRYPT);
	if (TINYCLR_SSL_MEMCMP(cbc_in,cbc_data,TINYCLR_SSL_STRLEN((char *)cbc_data)+1) != 0)
		{
		TINYCLR_SSL_PRINTF("des_xcbc_encrypt decrypt error\n");
		err=1;
		}
#endif

	TINYCLR_SSL_PRINTF("Doing ede cbc\n");
	if ((j=DES_set_key_checked(&cbc_key,&ks)) != 0)
		{
		TINYCLR_SSL_PRINTF("Key error %d\n",j);
		err=1;
		}
	if ((j=DES_set_key_checked(&cbc2_key,&ks2)) != 0)
		{
		TINYCLR_SSL_PRINTF("Key error %d\n",j);
		err=1;
		}
	if ((j=DES_set_key_checked(&cbc3_key,&ks3)) != 0)
		{
		TINYCLR_SSL_PRINTF("Key error %d\n",j);
		err=1;
		}
	TINYCLR_SSL_MEMSET(cbc_out,0,40);
	TINYCLR_SSL_MEMSET(cbc_in,0,40);
	i=TINYCLR_SSL_STRLEN((char *)cbc_data)+1;
	/* i=((i+7)/8)*8; */
	TINYCLR_SSL_MEMCPY(iv3,cbc_iv,sizeof(cbc_iv));

	des_ede3_cbc_encrypt(cbc_data,cbc_out,16L,ks,ks2,ks3,&iv3,
			     DES_ENCRYPT);
	des_ede3_cbc_encrypt(&(cbc_data[16]),&(cbc_out[16]),i-16,ks,ks2,ks3,
			     &iv3,DES_ENCRYPT);
	if (TINYCLR_SSL_MEMCMP(cbc_out,cbc3_ok,
		(unsigned int)(TINYCLR_SSL_STRLEN((char *)cbc_data)+1+7)/8*8) != 0)
		{
		unsigned int n;

		TINYCLR_SSL_PRINTF("des_ede3_cbc_encrypt encrypt error\n");
		for(n=0 ; n < i ; ++n)
		    TINYCLR_SSL_PRINTF(" %02x",cbc_out[n]);
		TINYCLR_SSL_PRINTF("\n");
		for(n=0 ; n < i ; ++n)
		    TINYCLR_SSL_PRINTF(" %02x",cbc3_ok[n]);
		TINYCLR_SSL_PRINTF("\n");
		err=1;
		}

	TINYCLR_SSL_MEMCPY(iv3,cbc_iv,sizeof(cbc_iv));
	des_ede3_cbc_encrypt(cbc_out,cbc_in,i,ks,ks2,ks3,&iv3,DES_DECRYPT);
	if (TINYCLR_SSL_MEMCMP(cbc_in,cbc_data,TINYCLR_SSL_STRLEN((char *)cbc_data)+1) != 0)
		{
		unsigned int n;

		TINYCLR_SSL_PRINTF("des_ede3_cbc_encrypt decrypt error\n");
		for(n=0 ; n < i ; ++n)
		    TINYCLR_SSL_PRINTF(" %02x",cbc_data[n]);
		TINYCLR_SSL_PRINTF("\n");
		for(n=0 ; n < i ; ++n)
		    TINYCLR_SSL_PRINTF(" %02x",cbc_in[n]);
		TINYCLR_SSL_PRINTF("\n");
		err=1;
		}

#ifndef LIBDES_LIT
	TINYCLR_SSL_PRINTF("Doing pcbc\n");
	if ((j=DES_set_key_checked(&cbc_key,&ks)) != 0)
		{
		TINYCLR_SSL_PRINTF("Key error %d\n",j);
		err=1;
		}
	TINYCLR_SSL_MEMSET(cbc_out,0,40);
	TINYCLR_SSL_MEMSET(cbc_in,0,40);
	des_pcbc_encrypt(cbc_data,cbc_out,TINYCLR_SSL_STRLEN((char *)cbc_data)+1,ks,
			 &cbc_iv,DES_ENCRYPT);
	if (TINYCLR_SSL_MEMCMP(cbc_out,pcbc_ok,32) != 0)
		{
		TINYCLR_SSL_PRINTF("pcbc_encrypt encrypt error\n");
		err=1;
		}
	des_pcbc_encrypt(cbc_out,cbc_in,TINYCLR_SSL_STRLEN((char *)cbc_data)+1,ks,&cbc_iv,
			 DES_DECRYPT);
	if (TINYCLR_SSL_MEMCMP(cbc_in,cbc_data,TINYCLR_SSL_STRLEN((char *)cbc_data)+1) != 0)
		{
		TINYCLR_SSL_PRINTF("pcbc_encrypt decrypt error\n");
		err=1;
		}

	TINYCLR_SSL_PRINTF("Doing ");
	TINYCLR_SSL_PRINTF("cfb8 ");
	err+=cfb_test(8,cfb_cipher8);
	TINYCLR_SSL_PRINTF("cfb16 ");
	err+=cfb_test(16,cfb_cipher16);
	TINYCLR_SSL_PRINTF("cfb32 ");
	err+=cfb_test(32,cfb_cipher32);
	TINYCLR_SSL_PRINTF("cfb48 ");
	err+=cfb_test(48,cfb_cipher48);
	TINYCLR_SSL_PRINTF("cfb64 ");
	err+=cfb_test(64,cfb_cipher64);

	TINYCLR_SSL_PRINTF("cfb64() ");
	err+=cfb64_test(cfb_cipher64);

	TINYCLR_SSL_MEMCPY(cfb_tmp,cfb_iv,sizeof(cfb_iv));
	for (i=0; i<sizeof(plain); i++)
		des_cfb_encrypt(&(plain[i]),&(cfb_buf1[i]),
			8,1,ks,&cfb_tmp,DES_ENCRYPT);
	if (TINYCLR_SSL_MEMCMP(cfb_cipher8,cfb_buf1,sizeof(plain)) != 0)
		{
		TINYCLR_SSL_PRINTF("cfb_encrypt small encrypt error\n");
		err=1;
		}

	TINYCLR_SSL_MEMCPY(cfb_tmp,cfb_iv,sizeof(cfb_iv));
	for (i=0; i<sizeof(plain); i++)
		des_cfb_encrypt(&(cfb_buf1[i]),&(cfb_buf2[i]),
			8,1,ks,&cfb_tmp,DES_DECRYPT);
	if (TINYCLR_SSL_MEMCMP(plain,cfb_buf2,sizeof(plain)) != 0)
		{
		TINYCLR_SSL_PRINTF("cfb_encrypt small decrypt error\n");
		err=1;
		}

	TINYCLR_SSL_PRINTF("ede_cfb64() ");
	err+=ede_cfb64_test(cfb_cipher64);

	TINYCLR_SSL_PRINTF("done\n");

	TINYCLR_SSL_PRINTF("Doing ofb\n");
	DES_set_key_checked(&ofb_key,&ks);
	TINYCLR_SSL_MEMCPY(ofb_tmp,ofb_iv,sizeof(ofb_iv));
	des_ofb_encrypt(plain,ofb_buf1,64,sizeof(plain)/8,ks,&ofb_tmp);
	if (TINYCLR_SSL_MEMCMP(ofb_cipher,ofb_buf1,sizeof(ofb_buf1)) != 0)
		{
		TINYCLR_SSL_PRINTF("ofb_encrypt encrypt error\n");
TINYCLR_SSL_PRINTF("%02X %02X %02X %02X %02X %02X %02X %02X\n",
ofb_buf1[8+0], ofb_buf1[8+1], ofb_buf1[8+2], ofb_buf1[8+3],
ofb_buf1[8+4], ofb_buf1[8+5], ofb_buf1[8+6], ofb_buf1[8+7]);
TINYCLR_SSL_PRINTF("%02X %02X %02X %02X %02X %02X %02X %02X\n",
ofb_buf1[8+0], ofb_cipher[8+1], ofb_cipher[8+2], ofb_cipher[8+3],
ofb_buf1[8+4], ofb_cipher[8+5], ofb_cipher[8+6], ofb_cipher[8+7]);
		err=1;
		}
	TINYCLR_SSL_MEMCPY(ofb_tmp,ofb_iv,sizeof(ofb_iv));
	des_ofb_encrypt(ofb_buf1,ofb_buf2,64,sizeof(ofb_buf1)/8,ks,&ofb_tmp);
	if (TINYCLR_SSL_MEMCMP(plain,ofb_buf2,sizeof(ofb_buf2)) != 0)
		{
		TINYCLR_SSL_PRINTF("ofb_encrypt decrypt error\n");
TINYCLR_SSL_PRINTF("%02X %02X %02X %02X %02X %02X %02X %02X\n",
ofb_buf2[8+0], ofb_buf2[8+1], ofb_buf2[8+2], ofb_buf2[8+3],
ofb_buf2[8+4], ofb_buf2[8+5], ofb_buf2[8+6], ofb_buf2[8+7]);
TINYCLR_SSL_PRINTF("%02X %02X %02X %02X %02X %02X %02X %02X\n",
plain[8+0], plain[8+1], plain[8+2], plain[8+3],
plain[8+4], plain[8+5], plain[8+6], plain[8+7]);
		err=1;
		}

	TINYCLR_SSL_PRINTF("Doing ofb64\n");
	DES_set_key_checked(&ofb_key,&ks);
	TINYCLR_SSL_MEMCPY(ofb_tmp,ofb_iv,sizeof(ofb_iv));
	TINYCLR_SSL_MEMSET(ofb_buf1,0,sizeof(ofb_buf1));
	TINYCLR_SSL_MEMSET(ofb_buf2,0,sizeof(ofb_buf1));
	num=0;
	for (i=0; i<sizeof(plain); i++)
		{
		des_ofb64_encrypt(&(plain[i]),&(ofb_buf1[i]),1,ks,&ofb_tmp,
				  &num);
		}
	if (TINYCLR_SSL_MEMCMP(ofb_cipher,ofb_buf1,sizeof(ofb_buf1)) != 0)
		{
		TINYCLR_SSL_PRINTF("ofb64_encrypt encrypt error\n");
		err=1;
		}
	TINYCLR_SSL_MEMCPY(ofb_tmp,ofb_iv,sizeof(ofb_iv));
	num=0;
	des_ofb64_encrypt(ofb_buf1,ofb_buf2,sizeof(ofb_buf1),ks,&ofb_tmp,
			  &num);
	if (TINYCLR_SSL_MEMCMP(plain,ofb_buf2,sizeof(ofb_buf2)) != 0)
		{
		TINYCLR_SSL_PRINTF("ofb64_encrypt decrypt error\n");
		err=1;
		}

	TINYCLR_SSL_PRINTF("Doing ede_ofb64\n");
	DES_set_key_checked(&ofb_key,&ks);
	TINYCLR_SSL_MEMCPY(ofb_tmp,ofb_iv,sizeof(ofb_iv));
	TINYCLR_SSL_MEMSET(ofb_buf1,0,sizeof(ofb_buf1));
	TINYCLR_SSL_MEMSET(ofb_buf2,0,sizeof(ofb_buf1));
	num=0;
	for (i=0; i<sizeof(plain); i++)
		{
		des_ede3_ofb64_encrypt(&(plain[i]),&(ofb_buf1[i]),1,ks,ks,
				       ks,&ofb_tmp,&num);
		}
	if (TINYCLR_SSL_MEMCMP(ofb_cipher,ofb_buf1,sizeof(ofb_buf1)) != 0)
		{
		TINYCLR_SSL_PRINTF("ede_ofb64_encrypt encrypt error\n");
		err=1;
		}
	TINYCLR_SSL_MEMCPY(ofb_tmp,ofb_iv,sizeof(ofb_iv));
	num=0;
	des_ede3_ofb64_encrypt(ofb_buf1,ofb_buf2,sizeof(ofb_buf1),ks,ks,ks,
			       &ofb_tmp,&num);
	if (TINYCLR_SSL_MEMCMP(plain,ofb_buf2,sizeof(ofb_buf2)) != 0)
		{
		TINYCLR_SSL_PRINTF("ede_ofb64_encrypt decrypt error\n");
		err=1;
		}

	TINYCLR_SSL_PRINTF("Doing cbc_cksum\n");
	DES_set_key_checked(&cbc_key,&ks);
	cs=des_cbc_cksum(cbc_data,&cret,TINYCLR_SSL_STRLEN((char *)cbc_data),ks,&cbc_iv);
	if (cs != cbc_cksum_ret)
		{
		TINYCLR_SSL_PRINTF("bad return value (%08lX), should be %08lX\n",
			(unsigned long)cs,(unsigned long)cbc_cksum_ret);
		err=1;
		}
	if (TINYCLR_SSL_MEMCMP(cret,cbc_cksum_data,8) != 0)
		{
		TINYCLR_SSL_PRINTF("bad cbc_cksum block returned\n");
		err=1;
		}

	TINYCLR_SSL_PRINTF("Doing quad_cksum\n");
	cs=des_quad_cksum(cbc_data,(des_cblock *)lqret,
		(long)TINYCLR_SSL_STRLEN((char *)cbc_data),2,(des_cblock *)cbc_iv);
	if (cs != 0x70d7a63aL)
		{
		TINYCLR_SSL_PRINTF("quad_cksum error, ret %08lx should be 70d7a63a\n",
			(unsigned long)cs);
		err=1;
		}
#ifdef _CRAY
	if (lqret[0].a != 0x327eba8dL)
		{
		TINYCLR_SSL_PRINTF("quad_cksum error, out[0] %08lx is not %08lx\n",
			(unsigned long)lqret[0].a,0x327eba8dUL);
		err=1;
		}
	if (lqret[0].b != 0x201a49ccL)
		{
		TINYCLR_SSL_PRINTF("quad_cksum error, out[1] %08lx is not %08lx\n",
			(unsigned long)lqret[0].b,0x201a49ccUL);
		err=1;
		}
	if (lqret[1].a != 0x70d7a63aL)
		{
		TINYCLR_SSL_PRINTF("quad_cksum error, out[2] %08lx is not %08lx\n",
			(unsigned long)lqret[1].a,0x70d7a63aUL);
		err=1;
		}
	if (lqret[1].b != 0x501c2c26L)
		{
		TINYCLR_SSL_PRINTF("quad_cksum error, out[3] %08lx is not %08lx\n",
			(unsigned long)lqret[1].b,0x501c2c26UL);
		err=1;
		}
#else
	if (lqret[0] != 0x327eba8dL)
		{
		TINYCLR_SSL_PRINTF("quad_cksum error, out[0] %08lx is not %08lx\n",
			(unsigned long)lqret[0],0x327eba8dUL);
		err=1;
		}
	if (lqret[1] != 0x201a49ccL)
		{
		TINYCLR_SSL_PRINTF("quad_cksum error, out[1] %08lx is not %08lx\n",
			(unsigned long)lqret[1],0x201a49ccUL);
		err=1;
		}
	if (lqret[2] != 0x70d7a63aL)
		{
		TINYCLR_SSL_PRINTF("quad_cksum error, out[2] %08lx is not %08lx\n",
			(unsigned long)lqret[2],0x70d7a63aUL);
		err=1;
		}
	if (lqret[3] != 0x501c2c26L)
		{
		TINYCLR_SSL_PRINTF("quad_cksum error, out[3] %08lx is not %08lx\n",
			(unsigned long)lqret[3],0x501c2c26UL);
		err=1;
		}
#endif
#endif

	TINYCLR_SSL_PRINTF("input word alignment test");
	for (i=0; i<4; i++)
		{
		TINYCLR_SSL_PRINTF(" %d",i);
		des_ncbc_encrypt(&(cbc_out[i]),cbc_in,
				 TINYCLR_SSL_STRLEN((char *)cbc_data)+1,ks,
				 &cbc_iv,DES_ENCRYPT);
		}
	TINYCLR_SSL_PRINTF("\noutput word alignment test");
	for (i=0; i<4; i++)
		{
		TINYCLR_SSL_PRINTF(" %d",i);
		des_ncbc_encrypt(cbc_out,&(cbc_in[i]),
				 TINYCLR_SSL_STRLEN((char *)cbc_data)+1,ks,
				 &cbc_iv,DES_ENCRYPT);
		}
	TINYCLR_SSL_PRINTF("\n");
	TINYCLR_SSL_PRINTF("fast crypt test ");
	str=crypt("testing","ef");
	if (TINYCLR_SSL_STRCMP("efGnQx2725bI2",str) != 0)
		{
		TINYCLR_SSL_PRINTF("fast crypt error, %s should be efGnQx2725bI2\n",str);
		err=1;
		}
	str=crypt("bca76;23","yA");
	if (TINYCLR_SSL_STRCMP("yA1Rp/1hZXIJk",str) != 0)
		{
		TINYCLR_SSL_PRINTF("fast crypt error, %s should be yA1Rp/1hZXIJk\n",str);
		err=1;
		}
#ifdef OPENSSL_SYS_NETWARE
    if (err) TINYCLR_SSL_PRINTF("ERROR: %d\n", err);
#endif
	TINYCLR_SSL_PRINTF("\n");
	return(err);
	}

static char *pt(unsigned char *p)
	{
	static char bufs[10][20];
	static int bnum=0;
	char *ret;
	int i;
	static char *f="0123456789ABCDEF";

	ret= &(bufs[bnum++][0]);
	bnum%=10;
	for (i=0; i<8; i++)
		{
		ret[i*2]=f[(p[i]>>4)&0xf];
		ret[i*2+1]=f[p[i]&0xf];
		}
	ret[16]='\0';
	return(ret);
	}

#ifndef LIBDES_LIT

static int cfb_test(int bits, unsigned char *cfb_cipher)
	{
	des_key_schedule ks;
	int i,err=0;

	DES_set_key_checked(&cfb_key,&ks);
	TINYCLR_SSL_MEMCPY(cfb_tmp,cfb_iv,sizeof(cfb_iv));
	des_cfb_encrypt(plain,cfb_buf1,bits,sizeof(plain),ks,&cfb_tmp,
			DES_ENCRYPT);
	if (TINYCLR_SSL_MEMCMP(cfb_cipher,cfb_buf1,sizeof(plain)) != 0)
		{
		err=1;
		TINYCLR_SSL_PRINTF("cfb_encrypt encrypt error\n");
		for (i=0; i<24; i+=8)
			TINYCLR_SSL_PRINTF("%s\n",pt(&(cfb_buf1[i])));
		}
	TINYCLR_SSL_MEMCPY(cfb_tmp,cfb_iv,sizeof(cfb_iv));
	des_cfb_encrypt(cfb_buf1,cfb_buf2,bits,sizeof(plain),ks,&cfb_tmp,
			DES_DECRYPT);
	if (TINYCLR_SSL_MEMCMP(plain,cfb_buf2,sizeof(plain)) != 0)
		{
		err=1;
		TINYCLR_SSL_PRINTF("cfb_encrypt decrypt error\n");
		for (i=0; i<24; i+=8)
			TINYCLR_SSL_PRINTF("%s\n",pt(&(cfb_buf1[i])));
		}
	return(err);
	}

static int cfb64_test(unsigned char *cfb_cipher)
	{
	des_key_schedule ks;
	int err=0,i,n;

	DES_set_key_checked(&cfb_key,&ks);
	TINYCLR_SSL_MEMCPY(cfb_tmp,cfb_iv,sizeof(cfb_iv));
	n=0;
	des_cfb64_encrypt(plain,cfb_buf1,12,ks,&cfb_tmp,&n,DES_ENCRYPT);
	des_cfb64_encrypt(&(plain[12]),&(cfb_buf1[12]),sizeof(plain)-12,ks,
			  &cfb_tmp,&n,DES_ENCRYPT);
	if (TINYCLR_SSL_MEMCMP(cfb_cipher,cfb_buf1,sizeof(plain)) != 0)
		{
		err=1;
		TINYCLR_SSL_PRINTF("cfb_encrypt encrypt error\n");
		for (i=0; i<24; i+=8)
			TINYCLR_SSL_PRINTF("%s\n",pt(&(cfb_buf1[i])));
		}
	TINYCLR_SSL_MEMCPY(cfb_tmp,cfb_iv,sizeof(cfb_iv));
	n=0;
	des_cfb64_encrypt(cfb_buf1,cfb_buf2,17,ks,&cfb_tmp,&n,DES_DECRYPT);
	des_cfb64_encrypt(&(cfb_buf1[17]),&(cfb_buf2[17]),
			  sizeof(plain)-17,ks,&cfb_tmp,&n,DES_DECRYPT);
	if (TINYCLR_SSL_MEMCMP(plain,cfb_buf2,sizeof(plain)) != 0)
		{
		err=1;
		TINYCLR_SSL_PRINTF("cfb_encrypt decrypt error\n");
		for (i=0; i<24; i+=8)
			TINYCLR_SSL_PRINTF("%s\n",pt(&(cfb_buf2[i])));
		}
	return(err);
	}

static int ede_cfb64_test(unsigned char *cfb_cipher)
	{
	des_key_schedule ks;
	int err=0,i,n;

	DES_set_key_checked(&cfb_key,&ks);
	TINYCLR_SSL_MEMCPY(cfb_tmp,cfb_iv,sizeof(cfb_iv));
	n=0;
	des_ede3_cfb64_encrypt(plain,cfb_buf1,12,ks,ks,ks,&cfb_tmp,&n,
			       DES_ENCRYPT);
	des_ede3_cfb64_encrypt(&(plain[12]),&(cfb_buf1[12]),
			       sizeof(plain)-12,ks,ks,ks,
			       &cfb_tmp,&n,DES_ENCRYPT);
	if (TINYCLR_SSL_MEMCMP(cfb_cipher,cfb_buf1,sizeof(plain)) != 0)
		{
		err=1;
		TINYCLR_SSL_PRINTF("ede_cfb_encrypt encrypt error\n");
		for (i=0; i<24; i+=8)
			TINYCLR_SSL_PRINTF("%s\n",pt(&(cfb_buf1[i])));
		}
	TINYCLR_SSL_MEMCPY(cfb_tmp,cfb_iv,sizeof(cfb_iv));
	n=0;
	des_ede3_cfb64_encrypt(cfb_buf1,cfb_buf2,(long)17,ks,ks,ks,
			       &cfb_tmp,&n,DES_DECRYPT);
	des_ede3_cfb64_encrypt(&(cfb_buf1[17]),&(cfb_buf2[17]),
			       sizeof(plain)-17,ks,ks,ks,
			       &cfb_tmp,&n,DES_DECRYPT);
	if (TINYCLR_SSL_MEMCMP(plain,cfb_buf2,sizeof(plain)) != 0)
		{
		err=1;
		TINYCLR_SSL_PRINTF("ede_cfb_encrypt decrypt error\n");
		for (i=0; i<24; i+=8)
			TINYCLR_SSL_PRINTF("%s\n",pt(&(cfb_buf2[i])));
		}
	return(err);
	}

#endif
#endif

