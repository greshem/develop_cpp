#include <stdio.h>
#include <beecrypt/sha512.h> 

typedef  unsigned char byte;

struct vector
{
        int             input_size;
        byte*   input;
        byte*   expect;
};

struct vector table[1] = {
        {  3, (byte*) "abc",
              (byte*) "\xdd\xaf\x35\xa1\x93\x61\x7a\xba\xcc\x41\x73\x49\xae\x20\x41\x31\x12\xe6\xfa\x4e\x89\xa9\x7e\xa2\x0a\x9e\xee\xe6\x4b\x55\xd3\x9a\x21\x92\x99\x2a\x27\x4f\xc1\xa8\x36\xba\x3c\x23\xa3\xfe\xeb\xbd\x45\x4d\x44\x23\x64\x3c\xe8\x0e\x2a\x9a\xc9\x4f\xa5\x4c\xa4\x9f" },
};

void dump(const unsigned char *data_buffer, const unsigned int length) {
    unsigned char byte;
    unsigned int i, j;
    for(i=0; i < length; i++) {
        byte = data_buffer[i];
        printf("%02x ", data_buffer[i]);  // display byte in hex
        if(((i%16)==15) || (i==length-1)) {
            for(j=0; j < 15-(i%16); j++)
                printf("   ");
            printf("| ");
            for(j=(i-(i%16)); j <= i; j++) {  // display printable bytes from line
                byte = data_buffer[j];
                if((byte > 31) && (byte < 127)) // outside printable char range
                    printf("%c", byte);
                else
                    printf(".");
            }   
            printf("\n"); // end of the dump line (each line 16 bytes)
        } // end if
    } // end for
}


int main()
{
        int i, failures = 0;
        sha512Param param;
        byte digest[64];

        for (i = 0; i < 1; i++)
        {
                if (sha512Reset(&param))
                        return -1;
                if (sha512Update(&param, table[i].input, table[i].input_size))
                        return -1;
                if (sha512Digest(&param, digest))
                        return -1;

                if (memcmp(digest, table[i].expect, 64))
                {
                        printf("failed test vector %d\n", i+1);
                        failures++;
                }
        }
	sha512Reset(&param);
	sha512Update(&param, (byte*) "qianqian", 8);
    sha512Digest(&param, digest);
	dump(digest, 64);
			
        return failures;
}

