#include <stdio.h>

#include <beecrypt/aes.h>

extern int fromhex(byte*, const char*);


int fromhex(byte* data, const char* hexdata)
{
        int length = strlen(hexdata);
        int count = 0, index = 0;
        byte b = 0;
        char ch;

        if (length & 1)
                count = 1;

        while (index++ < length)
        {
                ch = *(hexdata++);

                b <<= 4;
                if (ch >= '0' && ch <= '9')
                        b += (ch - '0');
                else if (ch >= 'A' && ch <= 'F')
                        b += (ch - 'A') + 10;
                else if (ch >= 'a' && ch <= 'f')
                        b += (ch - 'a') + 10;

                count++;
                if (count == 2)
                {
                        *(data++) = b;
                        b = 0;
                        count = 0;
                }
        }
        return (length+1) >>1;
}


struct vector
{
        char*                   key;
        char*                   input;
        char*                   expect;
        cipherOperation op;
};

#define NVECTORS 6

struct vector table[NVECTORS] = {
        { "000102030405060708090a0b0c0d0e0f",
          "00112233445566778899aabbccddeeff",
          "69c4e0d86a7b0430d8cdb78070b4c55a",
          ENCRYPT },
        { "000102030405060708090a0b0c0d0e0f",
          "69c4e0d86a7b0430d8cdb78070b4c55a",
          "00112233445566778899aabbccddeeff",
          DECRYPT },
        { "000102030405060708090a0b0c0d0e0f1011121314151617",
          "00112233445566778899aabbccddeeff",
          "dda97ca4864cdfe06eaf70a0ec0d7191",
          ENCRYPT },
        { "000102030405060708090a0b0c0d0e0f1011121314151617",
          "dda97ca4864cdfe06eaf70a0ec0d7191",
          "00112233445566778899aabbccddeeff",
          DECRYPT },
        { "000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f",
          "00112233445566778899aabbccddeeff",
          "8ea2b7ca516745bfeafc49904b496089",
          ENCRYPT },
        { "000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f",
          "8ea2b7ca516745bfeafc49904b496089",
          "00112233445566778899aabbccddeeff",
          DECRYPT }
};

int main()
{
        int i, failures = 0;
        aesParam param;
        byte key[32];
        byte src[16];
        byte dst[16];
        byte chk[16];
        size_t keybits;

        for (i = 0; i < NVECTORS; i++)
        {
                keybits = fromhex(key, table[i].key) << 3;

                if (aesSetup(&param, key, keybits, table[i].op))
                        return -1;

                fromhex(src, table[i].input);
                fromhex(chk, table[i].expect);

                switch (table[i].op)
                {
                case ENCRYPT:
                        if (aesEncrypt(&param, (uint32_t*) dst, (const uint32_t*) src))
                                return -1;
                        break;
                case DECRYPT:
                        if (aesDecrypt(&param, (uint32_t*) dst, (const uint32_t*) src))
                                return -1;
                        break;
                }

                if (memcmp(dst, chk, 16))
                {
                        printf("failed vector %d\n", i+1);
                        failures++;
                }
				else
				{
					printf(" success \n");
				}
        }

        return failures;
}

