#include <stdio.h>
#include <stdlib.h>

int maybe_utf8(char*);
int maybe_utf16be(char*);
int maybe_utf16le(char*);
int check_bom(char*, int*);

int main()
{
    int found = 0;
    char to_check[4096];
    fread(to_check, 1, 4096, stdin);

    printf("Could be: \n");

    if (maybe_utf8(to_check)) {
        printf("UTF-8\n");
        found++;
    }

    if (maybe_utf16be(to_check)) {
        printf("UTF-16 BE\n");
        found++;
    }

    if (maybe_utf16le(to_check)) {
        printf("UTF-16 LE\n");
        found++;
    }

    if (found == 0) {
        printf("Unknown encoding\n");
    }
}

int maybe_utf8(char *to_check)
{
    int *bom = malloc(3 * sizeof(int));
    bom[0] = 0xEF;
    bom[1] = 0xBB;
    bom[2] = 0xBF;
    
    return check_bom(to_check, bom);
}

int maybe_utf16be(char *to_check)
{
    int *bom = malloc(2 * sizeof(int));
    bom[0] = 0xFE;
    bom[1] = 0xFF;
    
    return check_bom(to_check, bom);
}

int maybe_utf16le(char *to_check)
{
    int *bom = malloc(2 * sizeof(int));
    bom[0] = 0xFF;
    bom[1] = 0xFE;
    
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