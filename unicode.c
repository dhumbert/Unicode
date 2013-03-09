#include <stdio.h>
#include <stdlib.h>

void printbitssimple(int n);

int main() 
{
    int value = 0x20AC, hex_value = 0x0;

    int bytes[4] = {-1, -1, -1, -1};

    if (value >= 0x0000 && value <= 0x007F) {
        bytes[0] = value; // characters below code point 127 are ASCII
    } else if (value >= 0x0080 && value <= 0x07FF) {
        bytes[0] = 0xC0 | ((value & 0x7C0) >> 6);
        bytes[1] = 0x80 | (value & 0x3F);
    } else if (value >= 0x0800 && value <= 0xFFFF) {
        bytes[0] = 0xE0 | ((value & 0xF000) >> 12);
        bytes[1] = 0x80 | ((value & 0xFC0) >> 6);
        bytes[2] = 0x80 | (value & 0x3F);
    } else if (value >= 0x10000 && value <= 0x1FFFFF) {
        printf("3");
    } else if (value >= 0x200000 && value <= 0x3FFFFFF) {
        printf("4");
    } else if (value >= 0x4000000 && value <= 0x7FFFFFFF) {
        printf("5");
    } else {
        printf("6");
    }

    printf("Hex bytes: ");
    int i;
    for (i = 0; i < sizeof(bytes) / sizeof(int); i++) {
        if (bytes[i] != -1) {
            printf("%x ", bytes[i]);
        }
    }
    printf("\n");

    return 0;    
}

void printbitssimple(int n) {
    unsigned int i;

    i = 1<<(sizeof(n) * 8 - 1);

    while (i > 0) {
        if (n & i)
            printf("1");
        else
            printf("0");
        i >>= 1;
    }
}