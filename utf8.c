/**
 * Convert a Unicode code point to UTF-8.
 */

#include <stdio.h>
#include <stdlib.h>
#include "utf8.h"

int main() 
{
    int value;

    printf("Enter a Unicode code point: ");
    scanf("%x", &value);

    int *bytes = code_point_to_utf8(value);

    int i;
    char byte_chars[5] = {'\0', '\0', '\0', '\0', '\0'};
    
    printf("Hex bytes: ");
    for (i = 0; i < 4; i++) {
        if (bytes[i] != -1) {
            printf("%x ", bytes[i]);
            byte_chars[i] = bytes[i];
        }
    }
    printf("\n");
    printf("Character: %s\n", byte_chars);

    return 0;    
}