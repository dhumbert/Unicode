/**
 * Convert a Unicode code point to UTF-8.
 */

#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int value;

    printf("Enter a Unicode code point: ");
    scanf("%x", &value);

    int bytes[4] = {-1, -1, -1, -1};

    if (value >= 0x0000 && value <= 0x007F) {
        bytes[0] = value; // characters below code point 127 are ASCII
    } else if (value >= 0x0080 && value <= 0x07FF) { // 2 byte encoding
        bytes[0] = 0xC0 | ((value & 0x7C0) >> 6);
        bytes[1] = 0x80 | (value & 0x3F);
    } else if (value >= 0x0800 && value <= 0xFFFF) { // 3 byte encoding
        bytes[0] = 0xE0 | ((value & 0xF000) >> 12);
        bytes[1] = 0x80 | ((value & 0xFC0) >> 6);
        bytes[2] = 0x80 | (value & 0x3F);
    } else if (value >= 0x10000 && value <= 0x1FFFFF) { // 4 byte encoding
        bytes[0] = 0xF0 | ((value & 0x1C0000) >> 18);
        bytes[1] = 0x80 | ((value & 0x3F000) >> 12);
        bytes[2] = 0x80 | ((value & 0xFC0) >> 6);
        bytes[3] = 0x80 | (value & 0x3F);
    }

    int i;
    char byte_chars[5] = {'\0', '\0', '\0', '\0', '\0'};
    
    printf("Hex bytes: ");
    for (i = 0; i < sizeof(bytes) / sizeof(int); i++) {
        if (bytes[i] != -1) {
            printf("%x ", bytes[i]);
            byte_chars[i] = bytes[i];
        }
    }
    printf("\n");
    printf("Character: %s\n", byte_chars);

    return 0;    
}