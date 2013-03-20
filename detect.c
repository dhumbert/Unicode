#include <stdio.h>
#include <stdlib.h>

int is_utf8(char*);
int is_utf16be(char*);
int is_utf16le(char*);
int is_utf32be(char*);
int is_utf32le(char*);
int check_bom(char*, int*);

int main()
{
    char to_check[4096];
    fread(to_check, 1, 4096, stdin);

    if (is_utf8(to_check)) {
        printf("UTF-8\n");
    } else if (is_utf16be(to_check)) {
        printf("UTF-16 BE\n");
    } else if (is_utf16le(to_check)) {
        printf("UTF-16 LE\n");
    } else if (is_utf32be(to_check)) {
        printf("UTF-32 BE\n");
    } else if (is_utf32le(to_check)) {
        printf("UTF-32 LE\n");
    } else {
        printf("Unknown encoding\n");
    }
}

int is_utf8(char *to_check)
{
    int *bom = malloc(3 * sizeof(int));
    bom[0] = 0xEF;
    bom[1] = 0xBB;
    bom[2] = 0xBF;
    
    return check_bom(to_check, bom);
}

int is_utf16be(char *to_check)
{
    int *bom = malloc(2 * sizeof(int));
    bom[0] = 0xFE;
    bom[1] = 0xFF;
    
    return check_bom(to_check, bom);
}

int is_utf16le(char *to_check)
{
    int *bom = malloc(2 * sizeof(int));
    bom[0] = 0xFF;
    bom[1] = 0xFE;
    
    return check_bom(to_check, bom);
}

int is_utf32be(char *to_check)
{
    int *bom = malloc(4 * sizeof(int));
    bom[0] = 0x00;
    bom[1] = 0x00;
    bom[2] = 0xFE;
    bom[3] = 0xFF;
    
    return check_bom(to_check, bom);
}

int is_utf32le(char *to_check)
{
    int *bom = malloc(4 * sizeof(int));
    bom[0] = 0x00;
    bom[1] = 0x00;
    bom[2] = 0xFF;
    bom[3] = 0xFE;
    
    return check_bom(to_check, bom);
}

int check_bom(char *to_check, int *bom_bytes)
{
    int bom_size = sizeof(bom_bytes) / sizeof(int);
    int i, success = 0;
    for (i = 0; i < bom_size; i++) {
        if ((to_check[i] ^ 0xFFFFFF00) == bom_bytes[i]) {
            success++;
        }
    }

    if (success == bom_size) {
        return 1;
    } else {
        return 0;
    }
}